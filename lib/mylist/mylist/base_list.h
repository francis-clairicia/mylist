/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** base_list
*/

#ifndef BASE_LIST_H_
#define BASE_LIST_H_

#include "node.h"

///////////// Delete data from linked lists ///////////

//!
//! @brief Delete a node at a certain index
//!
//! @param list The linked list pointer
//! @param index (signed long int) The position
//!              (If negative, the search will begin at the end)
//!
#define list_pop(list, index)   \
    (list)->pop((list), (index))

//!
//! @brief Delete the first node
//!
//! @param list The linked list pointer
//!
#define list_pop_front(list)    \
    (list)->pop_front((list))

//!
//! @brief Delete the last node
//!
//! @param list The linked list pointer
//! @return void
//!
#define list_pop_back(list)    \
    (list)->pop_back((list))

//!
//! @brief Delete all the nodes, making list empty
//!
//! @param list The linked list pointer
//!
#define list_clear(list)    \
    (list)->clear((list))
//////////////////////////////////////////////////

///////////// Modify linked lists ///////////

//!
//! @brief Duplicate the linked list.
//!        This function will create a new list with each node data copied.
//!        If the list has a destructor, the duplicate should not have it.
//!
//! @param list The linked list pointer
//! @return The new linked list
//!
#define list_dup(list)      \
    (list)->duplicate((list))

//!
//! @brief Merge two lists, making the 'list2' empty
//!
//! @param list1 The linked list pointer receiving the nodes
//! @param list2 The linked list pointer to merge
//!
#define list_merge(list1, list2)    \
    (list1)->merge((list1), (list2))

//!
//! @brief Reverse a list
//!
//! @param list The linked list pointer
//!
#define list_reverse(list)  \
    (list)->reverse((list))

//!
//! @brief Put the first node of the list at the end
//!
//! @param list The linked list pointer
//!
#define list_rotate_begin(list) \
    (list)->rotate_begin((list))

//!
//! @brief Put the last node of the list at the start
//!
//! @param list The linked list pointer
//!
#define list_rotate_end(list) \
    (list)->rotate_end((list))
//////////////////////////////////////////////////

///////////// List informations /////////////

//!
//! @brief Get the list's length
//!
//! @param list The linked list pointer
//! @return (size_t) The number of nodes
//!
#define list_len(list) \
    (list)->__len__((list))

//!
//! @brief Check if the list is empty
//!
//! @param list The linked list pointer
//! @return (int) LIST_TRUE if the list is empty else LIST_FALSE
//!
#define list_empty(list) \
    (list)->empty((list))

//!
//! @brief Get the list's node data destructor function pointer
//!
//! @param list The linked list pointer
//! @return (node_dtor_t) The function pointer or NULL
//!
#define list_node_destructor(list) \
    (list)->__node_dtor__
//////////////////////////////////////////////////

///////////// Get/Find node in list /////////////

//!
//! @brief Get the first node pointer
//!
//! @param list The linked list pointer
//! @return (const node_t *) A node pointer, or NULL if the list is empty
//!
#define list_begin(list)    \
    (list)->__begin__((list))

//!
//! @brief Get the last node pointer
//!
//! @param list The linked list pointer
//! @return (const node_t *) A node pointer, or NULL if the list is empty
//!
#define list_end(list)    \
    (list)->__end__((list))

//!
//! @brief Get a node pointer at index
//!
//! @param list The linked list pointer
//! @param index (signed long int) The position.
//!              (If negative the search will begin at the end)
//! @return (const node_t *) A node pointer, or NULL if the node was not found
//!
#define list_get(list, index)   \
    (list)->get((list), (index))

//!
//! @brief macro for range loop from beginning to end
//!
//! @param node The name of the node variable
//! @param list The linked list pointer
//!
#define list_foreach(node, list)    \
    for (const node_t *node = list_begin(list); node; node = (node)->next)

//!
//! @brief macro for range loop from end to beginning
//!
//! @param node The name of the node variable
//! @param list The linked list pointer
//!
#define list_foreach_reversed(node, list)    \
    for (const node_t *node = list_end(list); node; node = (node)->previous)

#include "node_iterator.h"

/////////////////////////////////////////////////////////////////////////////

#endif /* !BASE_LIST_H_ */
