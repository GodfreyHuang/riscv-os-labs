## The Lab of the memory allocation  
  
It can run on the qemu.  
When the os booting, the message print on the terminal show the memory status and the test function will allow a memory space.   
  
I want to find the reason of why DATA won't get any memory space, so I copy actually same code from https://github.com/cccriscv/mini-riscv-os/tree/master/09-MemoryAllocator and only use necessary code of malloc.  

The result is the memory space of DATA still missing:  
```
HEAP_START = 800043f4, HEAP_SIZE = 07ffbc0c, num of pages = 522172
TEXT:   0x80000000 -> 0x80002f4c
RODATA: 0x80002f4c -> 0x800030da
DATA:   0x80004000 -> 0x80004000
BSS:    0x80004000 -> 0x800043f4
HEAP:   0x80084400 -> 0x88000000
OS start
p = 0x80084400
p2 = 0x80084800
p3 = 0x80084a00
```  
  
The conclution is that I guess I don't have init the progress which will use the DATA space so the DATA is empty.  