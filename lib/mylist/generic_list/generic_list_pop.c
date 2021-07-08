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
    node_t *to_remove = container_remove_node(list, index);

    destroy_node(to_remove, list_node_destructor(this), LIST_TRUE);
}

void intern_generic_list_pop_front(list_t *this)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *to_remove = container_remove_first_node(list);

    destroy_node(to_remove, list_node_destructor(this), LIST_TRUE);
}

void intern_generic_list_pop_back(list_t *this)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *to_remove = container_remove_last_node(list);

    destroy_node(to_remove, list_node_destructor(this), LIST_TRUE);
}