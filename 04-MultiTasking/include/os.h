#ifndef __OS_H__
#define __OS_H__

#include "riscv.h"
#include "lib.h"
#include "task.h"

extern void os_kernel();
extern void os_start();
extern int main(int argc, char *argv[]);

extern void user_init();

#endif