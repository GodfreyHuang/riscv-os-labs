// Reference:
// https://github.com/cccriscv/mini-riscv-os/blob/master/01-HelloOs/os.c

#include "os.h"

int main(int argc, char *argv[])
{
    page_init();
    os_puts("Init riscv os!\n");
    page_test();

    while (1) {
    }
    return 0;
}
