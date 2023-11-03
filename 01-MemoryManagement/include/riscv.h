#include <stdint.h>

#define UART 0x10000000
#define UART_THR (uint8_t *) (UART + 0x00)  // THR:transmitter holding register
#define UART_LSR (uint8_t *) (UART + 0x05)  // LSR:line status register
#define UART_LSR_EMPTY_MASK 0x40  // LSR Bit 6: Transmitter empty; both the THR and LSR are empty