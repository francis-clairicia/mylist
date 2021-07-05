/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_create
*/

#include <string.h>
#include <stdlib.h>
#include "generic_list_intern.h"

static const list_t GENERIC_LIST_MODEL =
{
    .insert = &intern_generic_list_insert,
    .push_front = &intern_generic_list_push_front,
    .push_back = &intern_generic_list_push_back,
    .emplace = &intern_generic_list_emplace,
    .emplace_front = &intern_generic_list_emplace_front,
    .emplace_back = &intern_generic_list_emplace_back,
    .pop = &intern_generic_list_pop,
    .pop_front = &intern_generic_list_pop_front,
    .pop_back = &intern_generic_list_pop_back,
    .remove = &intern_generic_list_remove,
    .remove_cmp = &intern_generic_list_remove_cmp,
    .clear = &intern_generic_list_clear,
    .duplicate = &intern_generic_list_duplicate,
    .merge = &intern_generic_list_merge,
    .reverse = &intern_generic_list_reverse,
    .rotate_begin = &intern_generic_list_rotate_begin,
    .rotate_end = &intern_generic_list_rotate_end,
    .empty = &intern_generic_list_empty,
    .get = &intern_generic_list_get,
    .__len__ = &intern_generic_list_length,
    .__begin__ = &intern_generic_list_begin,
    .__end__ = &intern_generic_list_end,
    .__get_dtor__ = &intern_generic_list_get_dtor,
    .find = &intern_generic_list_find,
    .find_cmp = &intern_generic_list_find_cmp,
    .contains = &intern_generic_list_contains,
    .__c = {0}
};

list_t *generic_list_create(node_dtor_t destructor)
{
    list_t *list = malloc(sizeof(*list));

    if (list) {
        memcpy(list, &GENERIC_LIST_MODEL, sizeof(*list));
        ((container_list_t *)(&list->__c))->__dtor__ = destructor;
    }
    return list;
}