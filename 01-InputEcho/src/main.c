//Reference: https://github.com/cccriscv/mini-riscv-os/blob/master/01-HelloOs/os.c

#include "riscv.h"
#include "os.h"

int main(void)
{
    os_puts("Init riscv os!\n\n");

    while (1) 
    {
        os_puts("type something: ");
        char str[100];
        os_gets(str);
        os_puts("\r\necho: ");
        os_puts(str);
        os_puts("\r\n");
    }
    
    return 0;
}
