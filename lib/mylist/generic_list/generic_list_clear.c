/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_clear
*/

#include "generic_list_intern.h"

void intern_generic_list_clear(list_t *this)
{
    while (!list_empty(this))
        list_pop_back(this);
}