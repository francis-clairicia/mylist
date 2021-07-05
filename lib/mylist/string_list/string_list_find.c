/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_find
*/

#include <string.h>
#include "string_list_intern.h"

const node_t *intern_string_list_find(const string_list_t *this, const char *s)
{
    return container_find_node(&this->__c, s, 0, (data_cmp_t)&strcmp);
}

const node_t *intern_string_list_find_cmp(const string_list_t *this,
                                        const char *s,
                                        data_cmp_t comparator)
{
    return container_find_node(&this->__c, s, 0, comparator);
}