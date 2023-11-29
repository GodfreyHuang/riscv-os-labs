The lab of encapsulate task handler.  
  
In original case, the task variables are global variables, which might be unsave.  
That's the reason I decide to encapsulate the task handler into a struct called rv.  
  
```
typedef struct rv rv_cpu;
typedef void (*func_sw)(struct context *, struct context *);

//uint8_t task0_stack[STACK_SIZE];

struct rv
{
    //task manager
    //uint8_t *task0_stack;
    struct context ctx_os;
    struct context ctx_task;

    //task switcher -> sys_switch
    func_sw switcher;
};
```    
  
This lab can work.  