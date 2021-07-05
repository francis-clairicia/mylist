/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_intern
*/

#ifndef GENERIC_LIST_INTERN_H_
#define GENERIC_LIST_INTERN_H_

#include "mylist/generic_list.h"

int intern_generic_list_insert(
    list_t *this,
    ssize_t index,
    const void *data,
    size_t size
);

int intern_generic_list_push_front(
    list_t *this,
    const void *data,
    size_t size
);

int intern_generic_list_push_back(
    list_t *this,
    const void *data,
    size_t size
);

void intern_generic_list_pop(
    list_t *this,
    ssize_t index
);

void intern_generic_list_pop_front(
    list_t *this
);

void intern_generic_list_pop_back(
    list_t *this
);

void *intern_generic_list_emplace(
    list_t *this,
    ssize_t index,
    size_t size
);

int intern_generic_list_remove(
    list_t *this,
    const void *data,
    size_t size
);

int intern_generic_list_remove_cmp(
    list_t *this,
    const void *data,
    data_cmp_t comparator
);

void *intern_generic_list_emplace_front(
    list_t *this,
    size_t size
);

void *intern_generic_list_emplace_back(
    list_t *this,
    size_t size
);

void intern_generic_list_clear(
    list_t *this
);

list_t *intern_generic_list_duplicate(
    const list_t *this
);

void intern_generic_list_merge(
    list_t *this,
    list_t *other
);

void intern_generic_list_reverse(
    list_t *this
);

void intern_generic_list_rotate_begin(
    list_t *this
);

void intern_generic_list_rotate_end(
    list_t *this
);

int intern_generic_list_empty(
    const list_t *this
);

const node_t *intern_generic_list_get(
    const list_t *this,
    ssize_t index
);

size_t intern_generic_list_length(
    const list_t *this
);

const node_t *intern_generic_list_begin(
    const list_t *this
);

const node_t *intern_generic_list_end(
    const list_t *this
);

node_dtor_t intern_generic_list_get_dtor(
    const list_t *this
);

const node_t *intern_generic_list_find(
    const list_t *this,
    const void *data,
    size_t size
);

const node_t *intern_generic_list_find_cmp(
    const list_t *this,
    const void *data,
    data_cmp_t comparator
);

int intern_generic_list_contains(
    const list_t *this,
    const void *data,
    size_t size
);

#endif /* !GENERIC_LIST_INTERN_H_ */
