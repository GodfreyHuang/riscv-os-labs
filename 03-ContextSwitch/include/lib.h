#ifndef __LIB_H__
#define __LIB_H__

#include "os.h"

extern int os_putc(char ch);
extern void os_puts(char *s);
extern char os_getc();
extern int os_gets(char *s);

#endif