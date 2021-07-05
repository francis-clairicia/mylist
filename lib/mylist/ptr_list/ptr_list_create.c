/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_create
*/

#include <stdlib.h>
#include <string.h>
#include "ptr_list_intern.h"

static const ptr_list_t PTR_LIST_MODEL =
{
    .ptr_insert = &intern_ptr_list_insert,
    .ptr_push_front = &intern_ptr_list_push_front,
    .ptr_push_back = &intern_ptr_list_push_back,
    .pop = &intern_ptr_list_pop,
    .pop_front = &intern_ptr_list_pop_front,
    .pop_back = &intern_ptr_list_pop_back,
    .ptr_remove = &intern_ptr_list_remove,
    .ptr_remove_cmp = &intern_ptr_list_remove_cmp,
    .clear = &intern_ptr_list_clear,
    .duplicate = &intern_ptr_list_duplicate,
    .merge = &intern_ptr_list_merge,
    .reverse = &intern_ptr_list_reverse,
    .rotate_begin = &intern_ptr_list_rotate_begin,
    .rotate_end = &intern_ptr_list_rotate_end,
    .empty = &intern_ptr_list_empty,
    .get = &intern_ptr_list_get,
    .__len__ = &intern_ptr_list_length,
    .__begin__ = &intern_ptr_list_begin,
    .__end__ = &intern_ptr_list_end,
    .__get_dtor__ = &intern_ptr_list_get_dtor,
    .ptr_find = &intern_ptr_list_find,
    .ptr_find_cmp = &intern_ptr_list_find_cmp,
    .ptr_contains = &intern_ptr_list_contains,
    .__c = {0}
};

ptr_list_t *ptr_list_create(node_dtor_t destructor)
{
    ptr_list_t *list = malloc(sizeof(*list));

    if (list) {
        memcpy(list, &PTR_LIST_MODEL, sizeof(*list));
        ((container_list_t *)(&list->__c))->__dtor__ = destructor;
    }
    return list;
}