#ifndef __OS_H__
#define __OS_H__

#include "lib.h"
#include "riscv.h"
// define the kernel functions

// memory allocator
extern void *malloc(size_t size);
extern void free(void *p);
extern void page_init();
extern void page_test();

// main function
extern int main(int argc, char *argv[]);

#endif