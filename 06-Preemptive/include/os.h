#ifndef __OS_H__
#define __OS_H__

#include "riscv.h"
#include "lib.h"
#include "task.h"

//context switch
extern void sys_switch();

//time counter
extern void sys_timer();
extern void timer_handler();
extern void timer_init();

//user task
extern void user_init();

//os
extern void os_kernel();
extern void os_start();

#endif