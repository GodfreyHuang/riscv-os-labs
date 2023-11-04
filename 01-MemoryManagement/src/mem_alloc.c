// mem_alloc.c: the memory allocator

#include "os.h"

extern uint32_t TEXT_START;
extern uint32_t TEXT_END;
extern uint32_t DATA_START;
extern uint32_t DATA_END;
extern uint32_t RODATA_START;
extern uint32_t RODATA_END;
extern uint32_t BSS_START;
extern uint32_t BSS_END;
extern uint32_t HEAP_START;
extern uint32_t HEAP_SIZE;

/*
 * _alloc_start points to the actual start address of heap pool
 * _alloc_end points to the actual end address of heap pool
 * _num_pages holds the actual max number of pages we can allocate.
 */

static uint32_t _alloc_start = 0;
static uint32_t _alloc_end = 0;
static uint32_t _num_pages = 0;

#define PAGE_SIZE 256
#define PAGE_ORDER 8

#define PAGE_TAKEN (uint8_t)(1 << 0)
#define PAGE_LAST (uint8_t)(1 << 1)
#define pageNum(x) ((x) / ((PAGE_SIZE) + 1)) + 1

/*
 * Page Descriptor 
 * flags:
 * - 00: This means this page hasn't been allocated
 * - 01: This means this page was allocated
 * - 11: This means this page was allocated and is the last page of the memory block allocated
 */

struct Page
{
  uint8_t flags;
};