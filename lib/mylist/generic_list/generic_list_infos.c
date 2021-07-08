/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_infos
*/

#include "generic_list_intern.h"

int intern_generic_list_empty(const list_t *this)
{
    return this->__c.size == 0;
}

size_t intern_generic_list_length(const list_t *this)
{
    return this->__c.size;
}

const node_t *intern_generic_list_begin(const list_t *this)
{
    return this->__c.start;
}

const node_t *intern_generic_list_end(const list_t *this)
{
    return this->__c.end;
}
