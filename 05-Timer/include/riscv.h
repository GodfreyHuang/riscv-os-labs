#ifndef __RISCV_H__
#define __RISCV_H__

#include <stdint.h>
#include <stdlib.h>

#define reg_t uint32_t // RISCV32: register is 32bits
// define reg_t as uint64_t // RISCV64: register is 64bits

#define UART        0x10000000            // RISC-V 的 virt 虛擬機，其 UART 映射區起始位址為 0x10000000
#define UART_THR    (uint8_t *)(UART + 0x00) // THR:transmitter holding register 傳送暫存器
#define UART_RHR    (uint8_t *)(UART + 0x00) // THR:transmitter holding register 傳送暫存器
#define UART_LSR    (uint8_t *)(UART + 0x05) // LSR:line status register 輸出狀態暫存器
#define UART_LSR_RX_READY 0x01            // input is waiting to be read from RHR
#define UART_LSR_EMPTY_MASK 0x40          // LSR Bit 6: 當 LSR 的第六位元為 1 時，代表傳送區為空的，可以傳了 (Transmitter empty; both the THR and LSR are empty)

#define STACK_SIZE 1024

// Saved registers for kernel context switches.
struct context {
    reg_t ra;
    reg_t sp;

    // callee-saved
    reg_t s0;
    reg_t s1;
    reg_t s2;
    reg_t s3;
    reg_t s4;
    reg_t s5;
    reg_t s6;
    reg_t s7;
    reg_t s8;
    reg_t s9;
    reg_t s10;
    reg_t s11;
};

struct task_handler
{
    uint8_t task0_stack[STACK_SIZE];
    struct context ctx_os;
    struct context ctx_task;
};
typedef struct task_handler th;
typedef struct task_handler* thP;

// ref: https://github.com/mit-pdos/xv6-riscv/blob/riscv/kernel/riscv.h
// 
// local interrupt controller, which contains the timer.
// ================== Timer Interrput ====================

#define NCPU 8             // maximum number of CPUs
#define CLINT 0x2000000
#define CLINT_MTIMECMP(hartid) (CLINT + 0x4000 + 4*(hartid))
#define CLINT_MTIME (CLINT + 0xBFF8) // cycles since boot.

// which hart (core) is this?
static inline reg_t r_mhartid()
{
  reg_t x;
  asm volatile("csrr %0, mhartid" : "=r" (x) );
  return x;
}

// Machine Status Register, mstatus
#define MSTATUS_MPP_MASK (3 << 11) // previous mode.
#define MSTATUS_MPP_M (3 << 11)
#define MSTATUS_MPP_S (1 << 11)
#define MSTATUS_MPP_U (0 << 11)
#define MSTATUS_MIE (1 << 3)    // machine-mode interrupt enable.

static inline reg_t r_mstatus()
{
  reg_t x;
  asm volatile("csrr %0, mstatus" : "=r" (x) );
  return x;
}

static inline void w_mstatus(reg_t x)
{
  asm volatile("csrw mstatus, %0" : : "r" (x));
}

// machine exception program counter, holds the
// instruction address to which a return from
// exception will go.
static inline void w_mepc(reg_t x)
{
  asm volatile("csrw mepc, %0" : : "r" (x));
}

static inline reg_t r_mepc()
{
  reg_t x;
  asm volatile("csrr %0, mepc" : "=r" (x));
  return x;
}

// Machine Scratch register, for early trap handler
static inline void w_mscratch(reg_t x)
{
  asm volatile("csrw mscratch, %0" : : "r" (x));
}

// Machine-mode interrupt vector
static inline void w_mtvec(reg_t x)
{
  asm volatile("csrw mtvec, %0" : : "r" (x));
}

// Machine-mode Interrupt Enable
#define MIE_MEIE (1 << 11) // external
#define MIE_MTIE (1 << 7)  // timer
#define MIE_MSIE (1 << 3)  // software

static inline reg_t r_mie()
{
  reg_t x;
  asm volatile("csrr %0, mie" : "=r" (x) );
  return x;
}

static inline void w_mie(reg_t x)
{
  asm volatile("csrw mie, %0" : : "r" (x));
}

#endif