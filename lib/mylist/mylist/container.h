/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** container
*/

#ifndef MY_LIST_CONTAINER_H_
#define MY_LIST_CONTAINER_H_

#include "constants.h"
#include "node.h"

//!
//! @brief Structure for the real linked list implementation.
//!        The container will only manage the nodes and do primitive actions
//!        to link the nodes, to find them, or to remove them.
//!
typedef struct linked_list_container
{
    node_t *start;         // The linked list's head
    node_t *end;           // The linked list's tail
    size_t size;           // The linked list's size (the number of nodes)
    node_dtor_t __dtor__;  // The node data destructor
} container_list_t;

///////////// Functions to implement a container /////////////

//!
//! @brief Put a node at the beginning of the list
//!
//! @param list The linked list container
//! @param element The node to add
//! @return LIST_SUCCESS, or LIST_ERROR if 'element' is NULL
//!
int container_add_node_at_start(container_list_t *list, node_t *element);

//!
//! @brief Put a node at the end of the list
//!
//! @param list The linked list container
//! @param element The node to add
//! @return LIST_SUCCESS, or LIST_ERROR if 'element' is NULL
//!
int container_add_node_at_end(container_list_t *list, node_t *element);

//!
//! @brief Put a node at a certain index
//!
//! @param list The linked list container
//! @param element The node to add
//! @param index The position. (If negative, the search will begin at the end)
//! @return LIST_SUCCESS, or LIST_ERROR if 'element' is NULL
//!
int container_add_node(container_list_t *list, node_t *element, ssize_t index);

//!
//! @brief Get a node pointer at index
//!
//! @param list The linked list container
//! @param index The position. (If negative, the search will begin at the end)
//! @return A node pointer, or NULL if the node was not found
//!
node_t *container_get_node(const container_list_t *list, ssize_t index);

//!
//! @brief Find a node matching with a data.
//!
//! @param list The linked list container
//! @param data The data to match
//! @param size The data size (ignored if a comparator is given)
//! @param comparator A function to use to compare the data.
//!                   The function must returns 0 if the data match,
//!                   non-zero value otherwise
//! @return A node pointer, or NULL if the data was not found
//!
node_t *container_find_node(const container_list_t *list, const void *data,
                            size_t size, data_cmp_t comparator);

//!
//! @brief Merge two containers, making 'list2' empty
//!
//! @param list1 The linked list container receiving the nodes
//! @param list2 The linked list container to merge
//!
void container_merge(container_list_t *list1, container_list_t *list2);

//!
//! @brief Detach the first node of the linked list
//!
//! @param list The linked list container
//! @return The detached node, or NULL if the list is empty
//!
node_t *container_remove_first_node(container_list_t *list);

//!
//! @brief Detach the last node of the linked list
//!
//! @param list The linked list container
//! @return The detached node, or NULL if the list is empty
//!
node_t *container_remove_last_node(container_list_t *list);

//!
//! @brief Detach a node at a certain index
//!
//! @param list The linked list container
//! @param index The position. (If negative, the search will begin at the end)
//! @return The detached node, or NULL if the node was not found
//!
node_t *container_remove_node(container_list_t *list, ssize_t index);

//!
//! @brief Detach a node matching a data
//!
//! @param list The linked list container
//! @param data The data to match
//! @param size The data size (ignored if a comparator is given)
//! @param comparator A function to use to compare the data.
//!                   The function must returns 0 if the data match,
//!                   non-zero value otherwise
//! @return The detached node, or NULL if the data was not found
//!
node_t *container_remove_node_from_data(
    container_list_t *list,
    const void *data,
    size_t size,
    data_cmp_t comparator
);

//!
//! @brief Reverse a linked list container
//!
//! @param list The linked list container
//!
void container_reverse(container_list_t *list);

//!
//! @brief Put the first node of the container at the end
//!
//! @param list The linked list container
//!
void container_rotate_begin(container_list_t *list);

//!
//! @brief Put the last node of the container at the beginning
//!
//! @param list The linked list containerc
//!
void container_rotate_end(container_list_t *list);
/////////////////////////////////////////////////////////////////////////////

#endif /* !MY_LIST_CONTAINER_H_ */
