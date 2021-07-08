/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_intern
*/

#ifndef PTR_LIST_INTERN_H_
#define PTR_LIST_INTERN_H_

#include "mylist/ptr_list.h"

int intern_ptr_list_insert(
    ptr_list_t *this,
    ssize_t index,
    void *ptr
);

int intern_ptr_list_push_front(
    ptr_list_t *this,
    void *ptr
);

int intern_ptr_list_push_back(
    ptr_list_t *this,
    void *ptr
);

void intern_ptr_list_pop(
    ptr_list_t *this,
    ssize_t index
);

void intern_ptr_list_pop_front(
    ptr_list_t *this
);

void intern_ptr_list_pop_back(
    ptr_list_t *this
);

int intern_ptr_list_remove(
    ptr_list_t *this,
    const void *ptr
);

int intern_ptr_list_remove_cmp(
    ptr_list_t *this,
    const void *ptr,
    data_cmp_t comparator
);

void intern_ptr_list_clear(
    ptr_list_t *this
);

ptr_list_t *intern_ptr_list_duplicate(
    const ptr_list_t *this
);

void intern_ptr_list_merge(
    ptr_list_t *this,
    ptr_list_t *other
);

void intern_ptr_list_reverse(
    ptr_list_t *this
);

void intern_ptr_list_rotate_begin(
    ptr_list_t *this
);

void intern_ptr_list_rotate_end(
    ptr_list_t *this
);

int intern_ptr_list_empty(
    const ptr_list_t *this
);

const node_t *intern_ptr_list_get(
    const ptr_list_t *this,
    ssize_t index
);

size_t intern_ptr_list_length(
    const ptr_list_t *this
);

const node_t *intern_ptr_list_begin(
    const ptr_list_t *this
);

const node_t *intern_ptr_list_end(
    const ptr_list_t *this
);

const node_t *intern_ptr_list_find(
    const ptr_list_t *this,
    const void *ptr
);

const node_t *intern_ptr_list_find_cmp(
    const ptr_list_t *this,
    const void *ptr,
    data_cmp_t comparator
);

int intern_ptr_list_contains(
    const ptr_list_t *this,
    const void *ptr
);

#endif /* !PTR_LIST_INTERN_H_ */
