/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_dup
*/

#include "string_list_intern.h"

string_list_t *intern_string_list_duplicate(const string_list_t *this)
{
    string_list_t *dest = string_list_create();

    if (!dest)
        return NULL;
    list_foreach(node, this) {
        if (dest->str_push_back(dest, node->data.ptr) == LIST_ERROR) {
            string_list_destroy(dest);
            return NULL;
        }
    }
    return dest;
}