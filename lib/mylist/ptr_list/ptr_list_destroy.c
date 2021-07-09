/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** list_destroy
*/

#include <stdlib.h>
#include <string.h>
#include "mylist/ptr_list.h"

void ptr_list_destroy(ptr_list_t *list)
{
    if (list) {
        list_clear(list);
        memset(list, 0, sizeof(*list));
        free(list);
    }
}