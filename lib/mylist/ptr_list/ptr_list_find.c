/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_find
*/

#include "ptr_list_intern.h"

static int ptr_cmp(const void *node_ptr, const void *ptr)
{
    return (size_t)node_ptr - (size_t)ptr;
}

const node_t *intern_ptr_list_find(const ptr_list_t *this, const void *ptr)
{
    return container_find_node(&this->__c, ptr, 0, &ptr_cmp);
}

const node_t *intern_ptr_list_find_cmp(const ptr_list_t *this,
                                        const void *ptr,
                                        data_cmp_t comparator)
{
    return container_find_node(&this->__c, ptr, 0, comparator);
}