/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_create
*/

#include <string.h>
#include <stdlib.h>
#include "string_list_intern.h"

static const string_list_t STRING_LIST_MODEL =
{
    .str_insert = &intern_string_list_insert,
    .str_push_front = &intern_string_list_push_front,
    .str_push_back = &intern_string_list_push_back,
    .pop = &intern_string_list_pop,
    .pop_front = &intern_string_list_pop_front,
    .pop_back = &intern_string_list_pop_back,
    .str_remove = &intern_string_list_remove,
    .str_remove_cmp = &intern_string_list_remove_cmp,
    .clear = &intern_string_list_clear,
    .duplicate = &intern_string_list_duplicate,
    .merge = &intern_string_list_merge,
    .reverse = &intern_string_list_reverse,
    .rotate_begin = &intern_string_list_rotate_begin,
    .rotate_end = &intern_string_list_rotate_end,
    .empty = &intern_string_list_empty,
    .get = &intern_string_list_get,
    .__len__ = &intern_string_list_length,
    .__begin__ = &intern_string_list_begin,
    .__end__ = &intern_string_list_end,
    .__get_dtor__ = &intern_string_list_get_dtor,
    .str_find = &intern_string_list_find,
    .str_find_cmp = &intern_string_list_find_cmp,
    .str_contains = &intern_string_list_contains,
    .__c = {0}
};

string_list_t *string_list_create(void)
{
    string_list_t *list = malloc(sizeof(*list));

    if (list) {
        memcpy(list, &STRING_LIST_MODEL, sizeof(*list));
        ((container_list_t *)(&list->__c))->__dtor__ = &free;
    }
    return list;
}