#ifndef __LIB_H__
#define __LIB_H__

#include "riscv.h"
#include <stdarg.h>
#include <stddef.h>

//string functions
extern char *os_gets(char *);
extern int os_getc(void);
extern int os_putc(char ch);
extern void os_puts(char *s);

//printf functions
extern int os_printf(const char *s, ...);
extern int os_vprintf(const char *s, va_list vl);
extern int os_vsnprintf(char *out, size_t n, const char *s, va_list vl);

extern void os_delay(volatile int num);

#endif
