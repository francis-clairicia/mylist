/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_get
*/

#include "string_list_intern.h"

const node_t *intern_string_list_get(const string_list_t *this, ssize_t index)
{
    return container_get_node((container_list_t *)&this->__c, index);
}