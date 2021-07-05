/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_get
*/

#include "ptr_list_intern.h"

const node_t *intern_ptr_list_get(const ptr_list_t *this, ssize_t index)
{
    return container_get_node((container_list_t *)&this->__c, index);
}