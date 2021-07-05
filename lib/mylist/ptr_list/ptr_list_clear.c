/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_clear
*/

#include "ptr_list_intern.h"

void intern_ptr_list_clear(ptr_list_t *this)
{
    while (!list_empty(this))
        list_pop_back(this);
}