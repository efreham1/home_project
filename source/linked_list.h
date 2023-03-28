#include <stdlib.h>
#include <stdbool.h>
#include "entry.h"

#pragma once

typedef struct linked_list linked_list_t;

typedef bool (*entry_gt_function)(entry_t a, entry_t b);
typedef bool (*entry_eq_function)(entry_t a, entry_t b);


linked_list_t *linked_list_create(entry_gt_function gt_func, entry_eq_function eq_func, bool sorting);

void linked_list_insert(linked_list_t *list, entry_t entry);

bool linked_list_remove(linked_list_t *list, entry_t entry);

void linked_list_clear(linked_list_t *list);

void linked_list_destroy(linked_list_t *list);