## The Lab of the memory allocation  
  
It can run on the qemu.  
When the os booting, the message print on the terminal show the memory status and the test function will allow a memory space.   
  
This function of the lab is usable but the initialization still have some problem. the DATA didn't get any memory space. The output of the lab looks like:  
```
HEAP_START = 800033f4, HEAP_SIZE = 07ffcc0c, num of pages = 522188
TEXT:   0x80000000 -> 0x80002da0
RODATA: 0x80002da0 -> 0x80002f34
DATA:   0x80003000 -> 0x80003000
BSS:    0x80003000 -> 0x800033f4
HEAP:   0x80083400 -> 0x88000000
Init riscv os!
p = 0x80083400
p2 = 0x80083800
p3 = 0x80083a00
```
