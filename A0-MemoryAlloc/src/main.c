// Reference: https://github.com/cccriscv/mini-riscv-os/blob/master/01-HelloOs/os.c

#include "os.h"
#include "riscv.h"

//uart
#define LSR_RX_READY (1 << 0)
#define EOF 0

void uart_init()
{
    /* disable interrupts */
    UART_REGW(UART_IER, 0x00);

    /* Baud rate setting */
    uint8_t lcr = UART_REGR(UART_LCR);
    UART_REGW(UART_LCR, lcr | (1 << 7));
    UART_REGW(UART_DLL, 0x03);
    UART_REGW(UART_DLM, 0x00);

    lcr = 0;
    UART_REGW(UART_LCR, lcr | (3 << 0));

    uint8_t ier = UART_REGR(UART_IER);
    UART_REGW(UART_IER, ier | (1 << 0));
}

int main(int argc, char *argv[])
{
    os_puts("Init riscv os!\n");

    uart_init();
    page_init();
    mem_test();

    while (1) {
    }
    return 0;
}
