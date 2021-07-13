/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** node
*/

#ifndef MY_LIST_NODE_H_
#define MY_LIST_NODE_H_

#include <sys/types.h>
#include <stddef.h>

//!
//! @brief The structure containing informations for a data inside a node
//!
typedef struct data_node
{
    void *ptr;    // The pointer to the contained data
    size_t size;  // The data size
} data_node_t;

//!
//! @brief The node data destruction function type
//!
typedef void (*node_dtor_t)(void *);

//!
//! @brief The data comparator function type.
//!        The function must returns 0 if the data match,
//!        non-zero value otherwise
//!
typedef int (*data_cmp_t)(const void *, const void *);

//!
//! @brief The linked list's node structure
//!
typedef struct node_list
{
    data_node_t data;            // The node data informations
    struct node_list *previous;  // A pointer to the previous node in the list
    struct node_list *next;      // A pointer to the next node in the list
} node_t;

///////////// Macros to get a data from a node_t struct pointer /////////////

//!
//! @brief Get the pointer to the data inside the node
//!
//! @param node The node_t pointer
//! @param type The type of the pointed data
//! @return The casted data pointer within the node
//!
#define NODE_PTR(node, type) ((type *)((node)->data.ptr))

//!
//! @brief Get the value of the data inside the node
//!
//! @param node The node_t pointer
//! @param type The data type
//! @return The data within the node
//!
#define NODE_DATA(node, type) (*((type *)((node)->data.ptr)))

//!
//! @brief Get the string data inside the node
//!
//! @param node The node_t pointer
//!
#define NODE_STR(node) ((char *)((node)->data.ptr))

//!
//! @brief Get the node data size
//!
//! @param node The node_t pointer
//!
#define NODE_SIZE(node) ((size_t)((node)->data.size))
/////////////////////////////////////////////////////////////////////////////

///////////// Functions to create/destroy a node /////////////

//!
//! @brief Create an empty node object with a zero-initialized data
//!
//! @param size The data size in bytes
//! @return The newly malloc'd node
//!
node_t *create_empty_node(size_t size);

//!
//! @brief Create a node object
//!
//! @param data The data to copy
//! @param size The data size
//! @return The newly malloc'd node
//!
node_t *create_node(const void *data, size_t size);

//!
//! @brief Create a node object
//!
//! @param ptr The data pointer to use (malloc'd or not)
//! @return The newly malloc'd node
//!
node_t *create_ptr_node(void *ptr);

//!
//! @brief Create a node object
//!
//! @param str The string to copy
//! @return The newly malloc'd node
//!
node_t *create_string_node(const char *str);

//!
//! @brief Destroy a node, freeing the data inside.
//!        If 'dtor' is not NULL, this function will always be used.
//!        Otherwise: If 'use_free' == 0, the pointer will not be free,
//!        else the libC's free() will be used
//!
//! @param node The node to destroy
//! @param dtor The function to use to destroy the data, or NULL
//! @param use_free boolean, must be LIST_FALSE or LIST_TRUE
//!
void destroy_node(node_t *node, node_dtor_t dtor, int use_free);
/////////////////////////////////////////////////////////////////////////////

#endif /* !NODE_H_ */
