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

static int put_node_at_index(container_list_t *l, node_t *element, ssize_t idx)
{
    node_t *node_index = NULL;

    if (idx < 0) {
        node_index = l->end;
        for (ssize_t i = -1; i > (idx + 1); --i)
            node_index = node_index->previous;
    } else {
        node_index = l->start;
        for (ssize_t i = 0; i < idx; ++i)
            node_index = node_index->next;
    }
    node_index->previous->next = element;
    element->previous = node_index->previous;
    element->next = node_index;
    node_index->previous = element;
    l->size += 1;
    return LIST_SUCCESS;
}

int container_add_node(container_list_t *list, node_t *element, ssize_t index)
{
    if (!element)
        return LIST_ERROR;
    if (index == 0)
        return (container_add_node_at_start(list, element));
    if (index == -1)
        return (container_add_node_at_end(list, element));
    if (index >= 0 && (size_t)index >= list->size)
        return (container_add_node_at_end(list, element));
    if (index < 0 && (ssize_t)(list->size + index) < 0)
        return (container_add_node_at_start(list, element));
    return (put_node_at_index(list, element, index));
}
