#include "lib.h"

int os_putc(char ch)
{
    while ((*UART_LSR & UART_LSR_EMPTY_MASK) == 0)
        ;
    return *UART_THR = ch;
}

void os_puts(char *s)
{
    while (*s)
        os_putc(*s++);
}  

// char os_getc()
// {

// }

// int os_gets(char *s)
// {

// }