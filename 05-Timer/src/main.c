#include "riscv.h"
#include "os.h"

struct task_handler test;

void user_task0()
{
    os_puts("Task0: Context Switch Success!\n");
    while(1) {}
}

int main(int argc, char *argv[])
{
    os_puts("Init riscv os!\n");

	timer_init(); // start timer interrupt ...

    while (1) {}
    
    return 0;
}
