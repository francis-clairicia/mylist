/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_intern
*/

#ifndef STRING_LIST_INTERN_H_
#define STRING_LIST_INTERN_H_

#include "mylist/string_list.h"

int intern_string_list_insert(
    string_list_t *this,
    ssize_t index,
    const char *str
);

int intern_string_list_push_front(
    string_list_t *this,
    const char *str
);

int intern_string_list_push_back(
    string_list_t *this,
    const char *str
);

void intern_string_list_pop(
    string_list_t *this,
    ssize_t index
);

void intern_string_list_pop_front(
    string_list_t *this
);

void intern_string_list_pop_back(
    string_list_t *this
);

int intern_string_list_remove(
    string_list_t *this,
    const char *s
);

int intern_string_list_remove_cmp(
    string_list_t *this,
    const char *s,
    data_cmp_t comparator
);

void intern_string_list_clear(
    string_list_t *this
);

string_list_t *intern_string_list_duplicate(
    const string_list_t *this
);

void intern_string_list_merge(
    string_list_t *this,
    string_list_t *other
);

void intern_string_list_reverse(
    string_list_t *this
);

void intern_string_list_rotate_begin(
    string_list_t *this
);

void intern_string_list_rotate_end(
    string_list_t *this
);

int intern_string_list_empty(
    const string_list_t *this
);

const node_t *intern_string_list_get(
    const string_list_t *this,
    ssize_t index
);

size_t intern_string_list_length(
    const string_list_t *this
);

const node_t *intern_string_list_begin(
    const string_list_t *this
);

const node_t *intern_string_list_end(
    const string_list_t *this
);

const node_t *intern_string_list_find(
    const string_list_t *this,
    const char *str
);

const node_t *intern_string_list_find_cmp(
    const string_list_t *this,
    const char *str,
    data_cmp_t comparator
);

int intern_string_list_contains(
    const string_list_t *this,
    const char *str
);

#endif /* !STRING_LIST_INTERN_H_ */
