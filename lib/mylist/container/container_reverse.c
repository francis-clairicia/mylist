/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** container_reverse
*/

#include "mylist/container.h"

static void swap_node_links(node_t *node)
{
    node_t *prev = node->previous;

    node->previous = node->next;
    node->next = prev;
}

void container_reverse(container_list_t *list)
{
    node_t *tail = list->end;

    if (list->size <= 1)
        return;
    for (node_t *node = list->start; node; node = node->previous)
        swap_node_links(node);
    list->end = list->start;
    list->start = tail;
}