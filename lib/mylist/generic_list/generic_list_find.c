/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_find
*/

#include "generic_list_intern.h"

const node_t *intern_generic_list_find(const list_t *this,
                                    const void *data, size_t size)
{
    return container_find_node(&this->__c, data, size, NULL);
}

const node_t *intern_generic_list_find_cmp(const list_t *this,
                                        const void *data,
                                        data_cmp_t comparator)
{
    return container_find_node(&this->__c, data, 0, comparator);
}