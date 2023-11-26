The lab of encapsulate task handler.  
  
In original case, the task variables are global variables, which might be unsave.  
That's the reason I decide to encapsulate the task handler into a struct called rv.  
  
```
typedef struct rv rv_cpu;
typedef void (*func_sw)(struct context *, struct context *);

struct rv
{
    //task manager
    uint8_t task0_stack[STACK_SIZE];
    struct context ctx_os;
    struct context ctx_task;

    //task switcher -> sys_switch
    func_sw switcher;
};
```  
  
There is a question that I cannot let task0_stack set into the struct rv. Qemu cannot excecute, which is confuse me a long time.  
Perhaps that memory space need malloc to set, so I decide using the memalloc example to do the lab. 
memalloc example reference: https://github.com/cccriscv/mini-riscv-os/tree/master/09-MemoryAllocator  
  
This lab is still in progress.  