#ifndef __RISCV_H__
#define __RISCV_H__

#include <stdint.h>

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

#endif