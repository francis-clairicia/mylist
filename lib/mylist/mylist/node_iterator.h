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

//!
//! @brief Switch to the next node
//!
//! @param node The node iterator
//!
void node_iter_next(node_iterator_t *node);

//!
//! @brief Switch to previous node
//!
//! @param node The node iterator
//!
void node_iter_prev(node_iterator_t *node);

//!
//! @brief Get the first iterator
//!
//! @param list The linked list pointer
//!
#define list_iter_begin(list)   \
    node_iter_start(list_begin(list), 0)

//!
//! @brief Get the last iterator
//!
//! @param list The linked list pointer
//!
#define list_iter_end(list)     \
    node_iter_start(list_end(list), list_len(list) - 1)

//!
//! @brief Macro for range loop using node_iterator_t from beginning to end
//!
//! @param it The name of the node iterator variable
//! @param list The linked list
//!
#define list_foreach_iter(it, list)                     \
    for (node_iterator_t it = list_iter_begin(list);    \
        (it).data.ptr;                                  \
        node_iter_next(&it))

//!
//! @brief Macro for range loop using node_iterator_t from end to beginning
//!
//! @param it The name of the node iterator variable
//! @param list The linked list
//!
#define list_foreach_reversed_iter(it, list)            \
    for (node_iterator_t it = list_iter_end(list);      \
        (it).data.ptr;                                  \
        node_iter_prev(&it))

//!
//! @brief Delete a node and set the iterator to the next node
//!
//! @param list The linked list pointer
//! @param it The node iterator
//!
#define list_pop_iter_next(list, it)        \
    {                                       \
        size_t it##_index = (it).index;     \
        node_iter_next(&it);                \
        (it).index = it##_index;            \
        list_pop(list, it##_index);         \
    }

//!
//! @brief Delete a node and set the iterator to the previous node
//!
//! @param list The linked list pointer
//! @param it The node iterator
//!
#define list_pop_iter_prev(list, it)        \
    {                                       \
        size_t it##_index = (it).index;     \
        node_iter_prev(&it);                \
        (it).index = it##_index;            \
        list_pop(list, it##_index);         \
    }

/////////////////////////////////////////////////////////////////////////////

#endif /* !NODE_ITERATOR_H_ */
