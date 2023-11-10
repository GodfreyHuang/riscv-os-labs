//Reference: https://github.com/cccriscv/mini-riscv-os/blob/master/01-HelloOs/os.c

#include "riscv.h"
#include "os.h"

uint8_t task0_stack[STACK_SIZE];
struct context ctx_os;
struct context ctx_task;

void user_task0()
{
    os_puts("Task0: Context Switch Success!\n");
    while(1) {}
}

int main(int argc, char *argv[])
{
    os_puts("riscv os operate!\n");

    // ctx_task.ra = (reg_t) user_task0;
    // ctx_task.sp = (reg_t) &task0_stack[STACK_SIZE - 1];
    // sys_switch(&ctx_os, &ctx_task);

    while (1) {}
    
    return 0;
}
