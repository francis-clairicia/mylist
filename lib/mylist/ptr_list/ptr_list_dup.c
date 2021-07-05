/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_dup
*/

#include "ptr_list_intern.h"

ptr_list_t *intern_ptr_list_duplicate(const ptr_list_t *this)
{
    ptr_list_t *dest = ptr_list_create(NULL);

    if (!dest)
        return NULL;
    list_foreach(node, this) {
        if (dest->ptr_push_back(dest, node->data.ptr) == LIST_ERROR) {
            ptr_list_destroy(dest);
            return NULL;
        }
    }
    return dest;
}