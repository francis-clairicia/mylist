/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_remove
*/

#include "generic_list_intern.h"

int intern_generic_list_remove(list_t *this, const void *data, size_t size)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *node = container_remove_node_from_data(list, data, size, NULL);

    if (!node)
        return LIST_ERROR;
    destroy_node(node, list_node_destructor(this), LIST_TRUE);
    return LIST_SUCCESS;
}

int intern_generic_list_remove_cmp(list_t *this, const void *data,
                                data_cmp_t comparator)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *node = container_remove_node_from_data(list, data, 0, comparator);

    if (!node)
        return LIST_ERROR;
    destroy_node(node, list_node_destructor(this), LIST_TRUE);
    return LIST_SUCCESS;
}