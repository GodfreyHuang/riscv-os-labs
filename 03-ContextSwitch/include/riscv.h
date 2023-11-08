#ifndef __RISCV_H__
#define __RISCV_H__

#include <stdint.h>

#define UART        0x10000000            // RISC-V 的 virt 虛擬機，其 UART 映射區起始位址為 0x10000000
#define UART_THR    (uint8_t *)(UART + 0x00) // THR:transmitter holding register 傳送暫存器
#define UART_RHR    (uint8_t *)(UART + 0x00) // THR:transmitter holding register 傳送暫存器
#define UART_LSR    (uint8_t *)(UART + 0x05) // LSR:line status register 輸出狀態暫存器
#define UART_LSR_RX_READY 0x01            // input is waiting to be read from RHR
#define UART_LSR_EMPTY_MASK 0x40          // LSR Bit 6: 當 LSR 的第六位元為 1 時，代表傳送區為空的，可以傳了 (Transmitter empty; both the THR and LSR are empty)

#endif