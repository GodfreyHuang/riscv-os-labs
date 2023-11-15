#include "lib.h"

//string output
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

//string input
char os_getc()
{
    while ((*UART_LSR & UART_LSR_RX_READY) == 0)
        ;
    return *UART_RHR;
}

int os_gets(char *s)
{	
    char *p = s;
	while (1) 
    {
		char ch = os_getc();
		os_putc(ch);
        if (ch == '\n' || ch == '\r') 
            break;
		*p++ = ch;
	}
	*p = '\0';
	return p-s;
}