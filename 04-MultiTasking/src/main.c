//Reference: https://github.com/cccriscv/mini-riscv-os/blob/master/01-HelloOs/os.c

#include "riscv.h"
#include "os.h"

void os_kernel() 
{
	task_os();
}

void os_start() 
{
	os_puts("OS activated\n");
	user_init();
}

int main(int argc, char *argv[])
{
	os_start();
	
	int current_task = 0;
	while (1) {
		os_puts("OS: Activate next task\n");
		task_go(current_task);
		os_puts("OS: Back to OS\n");
		current_task = (current_task + 1) % taskTop; // Round Robin Scheduling
		os_puts("\n");
	}
	return 0;
}
