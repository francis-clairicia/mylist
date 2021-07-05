/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_merge
*/

#include "string_list_intern.h"

void intern_string_list_merge(string_list_t *this, string_list_t *other)
{
    container_list_t *list1 = (container_list_t *)&this->__c;
    container_list_t *list2 = (other) ? (container_list_t *)&other->__c : NULL;

    container_merge(list1, list2);
}