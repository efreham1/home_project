#include "heap.h"

struct heap
{
    void *data_ptr
};


heap_t *create_heap(size_t bytes)
{
    heap_t *heap = calloc(sizeof(heap_t), 1);
    heap->data_ptr = calloc(bytes, 1);
    return heap;
}

void *allocate(heap_t *heap, size_t bytes)
{

}

void deallocate(heap_t *heap, void *ptr)
{

}

void destroy_heap(heap_t *heap)
{
    
}