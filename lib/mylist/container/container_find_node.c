/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** container_find_node
*/

#include <string.h>
#include "mylist/container.h"

static node_t *find_with_byte_comparison(const container_list_t *list,
                                        const void *data, size_t size)
{
    for (node_t *node = list->start; node; node = node->next) {
        if (node->data.size != size)
            continue;
        if (memcmp(node->data.ptr, data, size) == 0)
            return node;
    }
    return NULL;
}

static node_t *find_with_comparator(const container_list_t *list,
                                    const void *data, data_cmp_t comparator)
{
    for (node_t *node = list->start; node; node = node->next) {
        if (comparator(node->data.ptr, data) == 0)
            return node;
    }
    return NULL;
}

node_t *container_find_node(const container_list_t *list, const void *data,
                            size_t size, data_cmp_t comparator)
{
    if (!data)
        return NULL;
    if (comparator)
        return find_with_comparator(list, data, comparator);
    if (size)
        return find_with_byte_comparison(list, data, size);
    return NULL;
}