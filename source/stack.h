#include <stdbool.h>
#include "entry.h"

#pragma once

typedef struct stack stack_t;

stack_t *stack_create();

void stack_destroy(stack_t *stack);

void stack_push(stack_t *stack, entry_t entry);

entry_t stack_pop(stack_t *stack);

bool stack_empty(stack_t *stack);

void stack_clear(stack_t *stack);