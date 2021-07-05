/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** node_iterator
*/

#ifndef NODE_ITERATOR_H_
#define NODE_ITERATOR_H_

#include "node.h"
#include "base_list.h"

typedef struct node_iterator
{
    data_node_t data;
    size_t index;
    const node_t *previous;
    const node_t *next;
} node_iterator_t;

node_iterator_t node_iter_start(const node_t *start, size_t index);

void node_iter_next(node_iterator_t *node);

void node_iter_prev(node_iterator_t *node);

///////////// Get/Find node in list /////////////

// Get the first iterator
#define list_iter_begin(list)   \
    node_iter_start(list_begin(list), 0)

// Get the last iterator
#define list_iter_end(list)     \
    node_iter_start(list_end(list), list_len(list) - 1)

// macro for range loop using node_iterator_t
#define list_foreach_iter(it, list)                     \
    for (node_iterator_t it = list_iter_begin(list);    \
        (it).data.ptr;                                  \
        node_iter_next(&it))

// macro for range loop reversed using node_iterator_t
#define list_foreach_reversed_iter(it, list)            \
    for (node_iterator_t it = list_iter_end(list);      \
        (it).data.ptr;                                  \
        node_iter_prev(&it))

// Delete a node using an iterator (next)
#define list_pop_iter_next(list, it)        \
    {                                       \
        size_t it##_index = (it).index;     \
        node_iter_next(&it);                \
        if ((it).data.ptr) {                \
            (it).index = it##_index;        \
        }                                   \
        list_pop(list, it##_index);         \
    }

// Delete a node using an iterator (prev)
#define list_pop_iter_prev(list, it)        \
    {                                       \
        size_t it##_index = (it).index;     \
        node_iter_prev(&it);                \
        if ((it).data.ptr) {                \
            (it).index = it##_index;        \
        }                                   \
        list_pop(list, it##_index);         \
    }

/////////////////////////////////////////////////////////////////////////////

#endif /* !NODE_ITERATOR_H_ */
