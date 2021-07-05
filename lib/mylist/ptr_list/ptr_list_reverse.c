/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_reverse
*/

#include "ptr_list_intern.h"

void intern_ptr_list_reverse(ptr_list_t *this)
{
    container_reverse((container_list_t *)&this->__c);
}