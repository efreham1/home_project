#include <stdlib.h>
#include "stack.h"

typedef struct node node_t;

struct stack
{
    node_t *top;
    unsigned int length;
};

struct node
{
    entry_t entry;
    node_t *next;
};

node_t *node_create(entry_t entry, node_t *next)
{
    node_t *node = malloc(sizeof(node_t));
    node->entry = entry;
    node->next = next;
    return next;
}

node_t *node_destroy_return_next(node_t *node)
{
    if (node)
    {
        node_t *next = node->next;
        free(node);
        return next;
    }
    return NULL;
}

stack_t *stack_create()
{
    return calloc(sizeof(stack_t), 1);
}

void stack_destroy(stack_t *stack)
{
    stack_clear(stack);
    free(stack);
}

void stack_push(stack_t *stack, entry_t entry)
{
    stack->top = node_create(entry, stack->top);
    stack->length++;
}

entry_t stack_pop(stack_t *stack)
{
    if (stack->top)
    {
        entry_t entry = stack->top->entry;
        stack->top = node_destroy_return_next(stack->top);
        stack->length--;
        return entry;
    }
    return (entry_t) NULL;
}

bool stack_empty(stack_t *stack)
{
    return stack->length==0;
}

void stack_clear(stack_t *stack)
{
    node_t *node = stack->top;
    while (node)
    {
        node = node_destroy_return_next(node);
    }
}