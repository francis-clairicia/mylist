/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_merge
*/

#include "ptr_list_intern.h"

void intern_ptr_list_merge(ptr_list_t *this, ptr_list_t *other)
{
    container_list_t *list1 = (container_list_t *)&this->__c;
    container_list_t *list2 = (other) ? (container_list_t *)&other->__c : NULL;

    container_merge(list1, list2);
}