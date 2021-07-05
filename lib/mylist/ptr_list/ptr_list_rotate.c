/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_rotate
*/

#include "ptr_list_intern.h"

void intern_ptr_list_rotate_begin(ptr_list_t *this)
{
    container_rotate_begin((container_list_t *)&this->__c);
}

void intern_ptr_list_rotate_end(ptr_list_t *this)
{
    container_rotate_end((container_list_t *)&this->__c);
}