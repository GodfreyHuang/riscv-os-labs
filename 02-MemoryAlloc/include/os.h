#ifndef __OS_H__
#define __OS_H__

#include "riscv.h"
#include "lib.h"
//define the kernel functions

//memory allocator
extern void *malloc(size_t size);
extern void free(void *p);

#endif