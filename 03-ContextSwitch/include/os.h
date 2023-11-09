#ifndef __OS_H__
#define __OS_H__

#include "riscv.h"
#include "lib.h"

//context switch
extern void sys_switch();

//user task
extern void user_task();

#endif