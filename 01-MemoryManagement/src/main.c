// Reference: https://github.com/cccriscv/mini-riscv-os/blob/master/01-HelloOs/os.c

#include "riscv.h"

int putc(char ch)
{
    while ((*UART_LSR & UART_LSR_EMPTY_MASK) == 0)
        ;
    return *UART_THR = ch;
}

void puts(char *s)
{
    while (*s)
        putc(*s++);
}

int main(int argc, char *argv[])
{
    puts("Init riscv os!\n");
    while (1) {
    }
    return 0;
}
