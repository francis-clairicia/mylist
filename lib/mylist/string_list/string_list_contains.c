/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_contains
*/

#include "string_list_intern.h"

int intern_string_list_contains(const string_list_t *this, const char *str)
{
    return (this->str_find(this, str) != NULL);
}