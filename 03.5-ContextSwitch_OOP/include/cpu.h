#ifndef __CPU_H__
#define __CPU_H__

#include "riscv.h"

typedef struct rv rv_cpu;
typedef void (*func_sw)(struct context *, struct context *);

//uint8_t task0_stack[STACK_SIZE];

struct rv
{
    //task manager
    //uint8_t *task0_stack;
    struct context ctx_os;
    struct context ctx_task;

    //task switcher -> sys_switch
    func_sw switcher;
};

#endif