#ifndef __OS_H__
#define __OS_H__

#include "riscv.h"

// print char in console
int os_putc(char ch);
// print string in console
void os_puts(char *s);

char os_getc();

int os_gets(char *s);

#endif