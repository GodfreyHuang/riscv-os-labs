#ifndef __LIB_H__
#define __LIB_H__

#include "riscv.h"
#include <stddef.h>
#include <stdarg.h>

//string functions 
int os_putc(char ch);
void os_puts(char *s);

//print functions
int os_printf(const char *s, ...);
int os_vprintf(const char *s, va_list vl);
int os_vsnprintf(char *out, size_t n, const char *s, va_list vl);

#endif
