typedef union parallel_gc p_gc_t;

p_gc_t *init_gc();

void destroy_gc(p_gc_t *gc);
