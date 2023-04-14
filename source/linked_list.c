#include "linked_list.h"

typedef struct node node_t;

struct node
{
    entry_t entry;
    node_t *next;
};

struct linked_list
{
    node_t sentinel;
    int length;
    entry_eq_function eq_fun;
    entry_gt_function gt_fun;
};


node_t *get_previous_node(linked_list_t *list, entry_t entry)
{
    node_t *node = &list->sentinel;
    while (list->gt_fun && node->next && list->gt_fun(node->next->entry, entry))
    {
        node = node->next;
    }
    return node;
}

node_t *create_node(node_t *next, entry_t entry)
{
    node_t *node = calloc(sizeof(node_t), 1);
    node->next = next;
    node->entry = entry;
    return node;
}

node_t *destroy_node_return_next(node_t *node)
{
    if (node)
    {
        node_t *next = node->next;
        free(node);
        return next;
    }
}


linked_list_t *linked_list_create(entry_gt_function gt_func, entry_eq_function eq_func, bool sorting)
{
    linked_list_t *list = calloc(sizeof(linked_list_t), 1);
    if (sorting) list->gt_fun = gt_func;
    list->length = 0;
    list->eq_fun = eq_func;
    return list;
}

void linked_list_insert(linked_list_t *list, entry_t entry)
{
    node_t *previous_node = get_previous_node(list, entry);

    node_t *next = previous_node->next;
    node_t *new_node = create_node(next, entry);
    previous_node->next = new_node;
    list->length++;
}

bool linked_list_remove(linked_list_t *list, entry_t entry)
{
    node_t *previous_node = get_previous_node(list, entry);
    if (previous_node->next)
    {
        node_t *node = previous_node->next;
        while (node->next && !list->gt_fun(entry, node->next->entry) && !list->eq_fun(entry, node->entry))
        {
            previous_node = node;
            node = node->next;
        }

        if (list->eq_fun(entry, node->entry))
        {
            previous_node->next = destroy_node_return_next(node);
            return true;
        }
        else return false;
    }
else return false;
}

void linked_list_clear(linked_list_t *list)
{
    node_t *node = list->sentinel.next;
    while (node)
    {
        node = destroy_node_return_next(node);
    }
    
}

void linked_list_destroy(linked_list_t *list)
{
    linked_list_clear(list);
    free(list);
}