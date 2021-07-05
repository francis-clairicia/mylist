/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_pop
*/

#include "generic_list_intern.h"

void intern_generic_list_pop(list_t *this, ssize_t index)
{
    container_list_t *list = (container_list_t *)&this->__c;

    destroy_node(container_remove_node(list, index), list->__dtor__);
}

void intern_generic_list_pop_front(list_t *this)
{
    container_list_t *list = (container_list_t *)&this->__c;

    destroy_node(container_remove_first_node(list), list->__dtor__);
}

void intern_generic_list_pop_back(list_t *this)
{
    container_list_t *list = (container_list_t *)&this->__c;

    destroy_node(container_remove_last_node(list), list->__dtor__);
}