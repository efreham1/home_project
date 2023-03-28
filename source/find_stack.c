#include <stdlib.h>
#include "find_stack.h"

struct stack
{
    unsigned long start;
};


stack_t *initiate_stack(int frames)
{
    stack_t *stack = malloc(sizeof(stack_t));
    stack->start = (unsigned long) __builtin_frame_address(frames);
    return stack;
}

void **get_ptrs(stack_t *stack, int *len)
{
    unsigned long end = (unsigned long) __builtin_frame_address(0);
    unsigned long length = stack->start-end;
    void *buf[length/8];
    int idx = 0;
    for (unsigned long ptr = end; ptr < stack->start; ptr++)
    {
        unsigned long potential_ptr = (unsigned long) *((void **) ptr);
        if (potential_ptr != 0 && potential_ptr%4==0)
        {
            buf[idx++] = (void *) ptr;
        }
    }
    void **ptrs = malloc(idx*sizeof(void *));
    for (int i = 0; i < idx; i++)
    {
        ptrs[i] = buf[i];
    }
    *len = idx;
    return ptrs;
}

void destroy_stack(stack_t *stack)
{
    free(stack);
}