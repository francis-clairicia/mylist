/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** container_find_node
*/

#include <string.h>
#include "mylist/container.h"

node_t *container_find_node(const container_list_t *list, const void *data,
                            size_t size, data_cmp_t comparator)
{
    if (!data || (!comparator && size == 0))
        return NULL;
    for (node_t *node = list->start; node; node = node->next) {
        if (comparator && comparator(node->data.ptr, data) == 0)
            return node;
        if (comparator || node->data.size != size)
            continue;
        if (memcmp(node->data.ptr, data, size) == 0)
            return node;
    }
    return NULL;
}