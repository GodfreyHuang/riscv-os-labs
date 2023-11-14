//Reference: https://github.com/cccriscv/mini-riscv-os/blob/master/01-HelloOs/os.c

#include "riscv.h"
#include "os.h"

#include <stddef.h>
#include <stdlib.h>

// int init_rvcpu(rv_cpu **self)
// {
//     os_puts("processing...\n");

//     *self = malloc(sizeof(rv_cpu));
//     if((*self) == NULL)
//         return -1;

//     for(int i = 0; i < STACK_SIZE; ++i)
//         (*self)->task0_stack[i] = 0;
//     (*self)->switcher = sys_switch;

//     if((*self)->switcher == NULL)
//     {
//         os_puts("function pointer error!\n");  
//         return -1;      
//     }

//     return 0;
// }
uint8_t task0_stack[STACK_SIZE];

int init_rvcpu(rv_cpu *self)
{
    os_puts("processing...\n");
    self->switcher = sys_switch;
}

void user_task0()
{
    os_puts("Task0: Context Switch Success!\n");
    while(1) {}
}

int main(int argc, char *argv[])
{
    os_puts("init rv\n");

    // rv_cpu *test = NULL;
    // int status = init_rvcpu(&test);
    // if(status == -1)
    // {
    //     os_puts("shut down\n");
    // }
    rv_cpu test;
    //test.switcher = sys_switch;
    init_rvcpu(&test);

    test.ctx_task.ra = (reg_t) user_task0;
    test.ctx_task.sp = (reg_t) &task0_stack[STACK_SIZE - 1];
    test.switcher(&(test.ctx_os), &(test.ctx_task));

    os_puts("riscv os operate!\n");

    while (1) {}
    
    return 0;
}
