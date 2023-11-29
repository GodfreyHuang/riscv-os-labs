## The Lab of the memory allocation  
  
It can run on the qemu.  
When the os booting, the message print on the terminal show the memory status and the test function will allow a memory space.   
  
This function of the lab is usable but the initialization still have some problem. the DATA didn't get any memory space. The output of the lab looks like:  
```
HEAP_START = 800023f4, HEAP_SIZE = 07ffdc0c, num of pages = 522204
TEXT:   0x80000000 -> 0x80001e08
RODATA: 0x80001e08 -> 0x80001f84
DATA:   0x80002000 -> 0x80002000
BSS:    0x80002000 -> 0x800023f4
HEAP:   0x80082400 -> 0x88000000
Init riscv os!
p3 = 0x80082400
```
