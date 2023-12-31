//Reference: https://github.com/cccriscv/mini-riscv-os/blob/master/01-HelloOs/os.c

#include "riscv.h"
#include "os.h"

//uint8_t task0_stack[STACK_SIZE];
//struct context ctx_os;
//struct context ctx_task;

struct task_handler test;

void user_task0()
{
    os_puts("Task0: Context Switch Success!\n");
    while(1) {}
}

int main(int argc, char *argv[])
{
    os_puts("riscv os operate!\n");

    // struct task_handler *th = (struct task_handler)malloc(sizeof(struct task_handler));
    
    // th->ctx_task.ra = (reg_t) user_task0;
    // th->ctx_task.sp = (reg_t) &(th->task0_stack[STACK_SIZE - 1]);
    // sys_switch(&(th->ctx_os), &(th->ctx_task));

    //struct task_handler test;

    test.ctx_task.ra = (reg_t) user_task0;
    test.ctx_task.sp = (reg_t) &(test.task0_stack[STACK_SIZE - 1]);
    sys_switch(&(test.ctx_os), &(test.ctx_task));

    while (1) {}
    
    return 0;
}
