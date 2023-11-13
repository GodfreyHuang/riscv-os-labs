#ifndef __LIB_H__
#define __LIB_H__

#include "riscv.h"
#include <stddef.h>
#include <stdarg.h>

extern int os_putc(char ch);
extern void os_puts(char *s);
extern char os_getc();
extern int os_gets(char *s);

extern void os_delay(volatile int num);

#endif