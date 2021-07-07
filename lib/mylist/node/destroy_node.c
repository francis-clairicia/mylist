/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** destroy_node
*/

#include <stdlib.h>
#include "mylist/container.h"

void destroy_node(node_t *node, node_dtor_t destructor, int use_free)
{
    if (!node)
        return;
    if (node->data.ptr) {
        if (destructor) {
            destructor(node->data.ptr);
        } else if (use_free != 0) {
            free(node->data.ptr);
        }
    }
    free(node);
}
