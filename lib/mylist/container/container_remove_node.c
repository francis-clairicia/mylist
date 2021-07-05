/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** remove_node
*/

#include "mylist/container.h"

node_t *container_remove_first_node(container_list_t *list)
{
    node_t *node = NULL;

    if (list->start) {
        node = list->start;
        list->start = list->start->next;
        if (list->start) {
            list->start->previous = NULL;
            list->size -= 1;
        } else {
            list->end = NULL;
            list->size = 0;
        }
        node->next = NULL;
        node->previous = NULL;
    }
    return node;
}

node_t *container_remove_last_node(container_list_t *list)
{
    node_t *node = NULL;

    if (list->end) {
        node = list->end;
        list->end = list->end->previous;
        if (list->end) {
            list->end->next = NULL;
            list->size -= 1;
        } else {
            list->start = NULL;
            list->size = 0;
        }
        node->next = NULL;
        node->previous = NULL;
    }
    return node;
}

static void remove_middle_node(container_list_t *list, node_t *node)
{
    node_t *previous_node = node->previous;
    node_t *next_node = node->next;

    previous_node->next = next_node;
    next_node->previous = previous_node;
    node->next = NULL;
    node->previous = NULL;
    list->size -= 1;
}

node_t *container_remove_node(container_list_t *list, ssize_t index)
{
    node_t *to_remove = NULL;

    if (index == 0)
        return container_remove_first_node(list);
    if (index == -1)
        return container_remove_last_node(list);
    to_remove = container_get_node(list, index);
    if (to_remove) {
        if (to_remove == list->start)
            return container_remove_first_node(list);
        if (to_remove == list->end)
            return container_remove_last_node(list);
        remove_middle_node(list, to_remove);
    }
    return to_remove;
}

node_t *container_remove_node_from_data(container_list_t *list,
                                        const void *data,
                                        size_t size,
                                        data_cmp_t comparator)
{
    node_t *to_remove = container_find_node(list, data, size, comparator);

    if (to_remove) {
        if (to_remove == list->start)
            return container_remove_first_node(list);
        if (to_remove == list->end)
            return container_remove_last_node(list);
        remove_middle_node(list, to_remove);
    }
    return to_remove;
}
