#ifndef __TASK_H__
#define __TASK_H__

#include "riscv.h"
#include "sys.h"

#define MAX_TASK 10
#define STACK_SIZE 1024

extern int taskTop;

typedef struct rv rv_cpu;
typedef void (*func_sw)(struct context *, struct context *);

struct rv
{
    //task manager
    uint8_t task0_stack[STACK_SIZE];
    struct context ctx_os;
    struct context ctx_task;

    //task switcher -> sys_switch
    func_sw switcher;
};

extern int  task_create(void (*task)(void));
extern void task_go(int i);
extern void task_os();

#endif
