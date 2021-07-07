/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_remove
*/

#include <string.h>
#include "string_list_intern.h"

int intern_string_list_remove(string_list_t *this, const char *s)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *node;

    node = container_remove_node_from_data(list, s, 0, (data_cmp_t)&strcmp);
    if (!node)
        return LIST_ERROR;
    destroy_node(node, NULL, LIST_TRUE);
    return LIST_SUCCESS;
}

int intern_string_list_remove_cmp(string_list_t *this, const char *s,
                                data_cmp_t comparator)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *node;

    node = container_remove_node_from_data(list, s, 0, comparator);
    if (!node)
        return LIST_ERROR;
    destroy_node(node, NULL, LIST_TRUE);
    return LIST_SUCCESS;
}