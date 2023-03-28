#pragma once

typedef struct stack stack_t;

/// @brief Initiate a stack object
/// @param frames How many stack frames that should be disregarded
/// @return The initiated stack object with start on the specified stackframe
stack_t *initiate_stack(int frames);

/// @brief Get all potential pointers located on the stack frames between start and current
/// @param stack The stack object
/// @param len A pointer to a stack variable to which to write the length of the array of potential pointers
/// @return An array of potential pointers
void **get_ptrs(stack_t *stack, int *len);

/// @brief Destroy a stack and return its resources
/// @param stack The stack to be destroyed
void destroy_stack(stack_t *stack);