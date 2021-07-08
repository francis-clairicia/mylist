/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_pop
*/

#include "ptr_list_intern.h"

void intern_ptr_list_pop(ptr_list_t *this, ssize_t idx)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *to_remove = container_remove_node(list, idx);

    destroy_node(to_remove, list_node_destructor(this), LIST_FALSE);
}

void intern_ptr_list_pop_front(ptr_list_t *this)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *to_remove = container_remove_first_node(list);

    destroy_node(to_remove, list_node_destructor(this), LIST_FALSE);
}

void intern_ptr_list_pop_back(ptr_list_t *this)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *to_remove = container_remove_last_node(list);

    destroy_node(to_remove, list_node_destructor(this), LIST_FALSE);
}