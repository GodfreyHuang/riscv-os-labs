#ifndef __OS_H__
#define __OS_H__

#include "riscv.h"
#include "lib.h"

//context switch
extern void sys_switch();

//time counter
extern void sys_timer();
extern reg_t timer_handler(reg_t epc, reg_t cause);
extern void timer_init();

//user task
extern void user_task();

#endif