/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** container_add_node
*/

#include "mylist/container.h"

int container_add_node_at_start(container_list_t *list, node_t *element)
{
    if (!element)
        return LIST_ERROR;
    element->previous = NULL;
    element->next = list->start;
    if (list->size == 0)
        list->end = element;
    else
        list->start->previous = element;
    list->start = element;
    list->size += 1;
    return LIST_SUCCESS;
}

int container_add_node_at_end(container_list_t *list, node_t *element)
{
    if (!element)
        return LIST_ERROR;
    element->previous = list->end;
    element->next = NULL;
    if (list->size == 0)
        list->start = element;
    else
        list->end->next = element;
    list->end = element;
    list->size += 1;
    return LIST_SUCCESS;
}

static int put_node_at_index(container_list_t *l, node_t *element, size_t index)
{
    node_t *node_index = l->start;

    for (size_t i = 0; i < index; ++i)
        node_index = node_index->next;
    node_index->previous->next = element;
    element->previous = node_index->previous;
    element->next = node_index;
    node_index->previous = element;
    l->size += 1;
    return LIST_SUCCESS;
}

int container_add_node(container_list_t *list, node_t *element, ssize_t index)
{
    size_t idx = 0;

    if (!element)
        return LIST_ERROR;
    if (index >= 0) {
        if (index == 0)
            return (container_add_node_at_start(list, element));
        if ((size_t)index >= list->size)
            return (container_add_node_at_end(list, element));
    } else {
        if (index == -1)
            return (container_add_node_at_end(list, element));
        if ((ssize_t)(list->size + index) < 0)
            return (container_add_node_at_start(list, element));
    }
    idx = (index < 0) ? list->size + 1 + index : (size_t)index;
    return (put_node_at_index(list, element, idx));
}
