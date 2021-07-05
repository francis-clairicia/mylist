/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_dup
*/

#include "generic_list_intern.h"

list_t *intern_generic_list_duplicate(const list_t *this)
{
    list_t *dest = generic_list_create(this->__c.__dtor__);

    if (!dest)
        return NULL;
    list_foreach(n, this) {
        if (dest->push_back(dest, n->data.ptr, n->data.size) == LIST_ERROR) {
            generic_list_destroy(dest);
            return NULL;
        }
    }
    return dest;
}