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

//!
//! @brief The node iterator structure
//!
typedef struct node_iterator
{
    data_node_t data;        // The node data informations
    size_t index;            // The node position in the list
    const node_t *previous;  // A pointer to the previous node in the list
    const node_t *next;      // A pointer to the next node in the list
} node_iterator_t;

///////////// Functions/Macros to use a node iterator /////////////

//!
//! @brief Create a new node iterator object
//!
//! @param start The first node
//! @param index The first node's position in the list
//!              (between 0 and list_len(list) - 1 included)
//! @return The node iterator
//!
node_iterator_t node_iter_start(const node_t *start, size_t index);

void node_iter_next(node_iterator_t *node);

void node_iter_prev(node_iterator_t *node);

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
