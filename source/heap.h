#pragma once

#include <stdlib.h>

typedef struct heap heap_t;

heap_t *create_heap(size_t bytes);

void *allocate(heap_t *heap, size_t bytes);

void deallocate(heap_t *heap, void *ptr);

void destroy_heap(heap_t *heap);