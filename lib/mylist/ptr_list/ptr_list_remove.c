/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_remove
*/

#include "ptr_list_intern.h"

static int ptr_cmp(const void *node_ptr, const void *ptr)
{
    return (size_t)node_ptr - (size_t)ptr;
}

int intern_ptr_list_remove(ptr_list_t *this, const void *ptr)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *node = container_remove_node_from_data(list, ptr, 0, &ptr_cmp);

    if (!node)
        return LIST_ERROR;
    destroy_node(node, list->__dtor__, LIST_FALSE);
    return LIST_SUCCESS;
}

int intern_ptr_list_remove_cmp(ptr_list_t *this, const void *ptr,
                            data_cmp_t comparator)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *node = container_remove_node_from_data(list, ptr, 0, comparator);

    if (!node)
        return LIST_ERROR;
    destroy_node(node, list->__dtor__, LIST_FALSE);
    return LIST_SUCCESS;
}