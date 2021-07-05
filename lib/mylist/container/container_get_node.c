/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** container_get_node
*/

#include "mylist/container.h"

node_t *container_get_node(const container_list_t *list, ssize_t index)
{
    node_t *node = NULL;

    if (index < 0) {
        node = list->end;
        for (ssize_t i = -1; node && i > index; --i, (node = node->previous));
    } else {
        node = list->start;
        for (ssize_t i = 0; node && i < index; ++i, (node = node->next));
    }
    return node;
}