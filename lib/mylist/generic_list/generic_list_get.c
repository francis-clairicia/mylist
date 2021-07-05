/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_get
*/

#include "generic_list_intern.h"

const node_t *intern_generic_list_get(const list_t *this, ssize_t index)
{
    return container_get_node(&this->__c, index);
}