/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list
*/

#ifndef PTR_LIST_H_
#define PTR_LIST_H_

#include "container.h"
#include "base_list.h"

typedef struct pointer_linked_list ptr_list_t;

//!
//! @brief Structure for linked lists of pointers. This list is a wrapper to use
//!        pointers as elements for each nodes of the list. The pointer can be
//!        allocated or not. This implementation is here to provide a better
//!        use of pointers, instead of push it in a generic list_t.
//!
struct pointer_linked_list
{
    int (*const ptr_insert)(ptr_list_t *this, ssize_t index, void *ptr);
    int (*const ptr_push_front)(ptr_list_t *this, void *ptr);
    int (*const ptr_push_back)(ptr_list_t *this, void *ptr);

    void (*const pop)(ptr_list_t *this, ssize_t index);
    void (*const pop_front)(ptr_list_t *this);
    void (*const pop_back)(ptr_list_t *this);
    int (*const ptr_remove)(ptr_list_t *this, const void *ptr);
    int (*const ptr_remove_cmp)(ptr_list_t *this,
                                const void *ptr, data_cmp_t comparator);

    void (*const clear)(ptr_list_t *this);
    ptr_list_t *(*const duplicate)(const ptr_list_t *this);
    void (*const merge)(ptr_list_t *this, ptr_list_t *other);
    void (*const reverse)(ptr_list_t *this);
    void (*const rotate_begin)(ptr_list_t *this);
    void (*const rotate_end)(ptr_list_t *this);

    int (*const empty)(const ptr_list_t *this);
    const node_t *(*const get)(const ptr_list_t *this, ssize_t index);

    size_t (*const __len__)(const ptr_list_t *this);
    const node_t *(*const __begin__)(const ptr_list_t *this);
    const node_t *(*const __end__)(const ptr_list_t *this);
    node_dtor_t (*const __get_dtor__)(const ptr_list_t *this);

    const node_t *(*const ptr_find)(const ptr_list_t *this, const void *ptr);
    const node_t *(*const ptr_find_cmp)(const ptr_list_t *this,
                                        const void *ptr, data_cmp_t comparator);
    int (*const ptr_contains)(const ptr_list_t *this, const void *ptr);

    const container_list_t __c;
};

/////////// Init/destroy a linked list ///////////

//!
//! @brief Create and initialize a new linked list
//!
//! @param destructor A pointer to the function to use to free the node data,
//!                   or NULL if there is no function to use.
//!                   Will not destroy the pointer if NULL is given
//! @return The newly allocated list, or NULL in case of failure
//!
ptr_list_t *ptr_list_create(node_dtor_t destructor);

//!
//! @brief Free the whole linked list (nodes + structure),
//!        allocated by ptr_list_create()
//!
//! @param list The list to destroy
//!
void ptr_list_destroy(ptr_list_t *list);
///////////////////////////////////////////////////////////////

///////////// Useful functions /////////////

//!
//! @brief Create a NULL-terminated array of pointer from a pointer list.
//!        Each pointer is the one stored in the list, so use free()
//!        to free the array if the list's node destructor is not NULL
//!
//! @param list The pointer list
//! @param length If not NULL, the array length is stored
//! @return The allocated array
//!
void *ptr_list_to_array(const ptr_list_t *list, size_t *length);

//!
//! @brief Create a pointer list from a NULL-terminated array of pointers
//!
//! @param array Pointer to the array
//! @param destructor The node data destructor for the list.
//!                   If not NULL, the ptr_list grabs the ownership
//!                   of the pointers
//! @return The newly allocated list
//!
ptr_list_t *array_to_ptr_list(const void *array, node_dtor_t destructor);

//!
//! @brief Create a pointer list with default pointers
//!
//! @param destructor The node data destructor for the list.
//!                   If not NULL, the ptr_list grabs the ownership
//!                   of the pointers
//! @param pointers Variadic. All the pointers to store in the list
//! @return (ptr_list_t *) The newly allocated list
//!
#define make_ptr_list(destructor, pointers...)    \
    array_to_ptr_list(_FMT_ARRAY(const void *, pointers, NULL), destructor)
///////////////////////////////////////////////////////////////

///////////// Add data to linked lists ///////////

//!
//! @brief Insert a pointer at a certain index
//!
//! @param list The pointer list
//! @param index (long int) The position
//!              (If negative, the search will begin at the end)
//! @param ptr The pointer to store
//! @return (int) LIST_SUCCESS if it was a success, LIST_ERROR otherwise
//!
#define ptr_list_insert(list, index, ptr) \
    (list)->ptr_insert((list), (index), (ptr))

//!
//! @brief Insert a pointer at the beginning of the list
//!
//! @param list The pointer list
//! @param ptr The pointer to store
//! @return (int) LIST_SUCCESS if it was a success, LIST_ERROR otherwise
//!
#define ptr_list_push_front(list, ptr)   \
    (list)->ptr_push_front((list), (ptr))

//!
//! @brief Insert a pointer at the end of the list
//!
//! @param list The pointer list
//! @param ptr The pointer to store
//! @return (int) LIST_SUCCESS if it was a success, LIST_ERROR otherwise
//!
#define ptr_list_push_back(list, ptr) \
    (list)->ptr_push_back((list), (ptr))
///////////////////////////////////////////////////////////////

///////////// Remove data in list /////////////

//!
//! @brief Remove the first occurence of a pointer from the list.
//!        Will remove the node pointing to the same address
//!
//! @param list The pointer list
//! @param ptr The pointer to remove
//! @return (int) LIST_SUCCESS if it was a success,
//!         LIST_ERROR if the pointer was not found
//!
#define ptr_list_remove(list, ptr) \
    (list)->ptr_remove((list), (ptr))

//!
//! @brief Remove the first occurence of a pointer from the list
//!        using a comparator by passing these pointers as parameter
//!
//! @param list The pointer list
//! @param ptr A pointer to the data to match
//! @param comparator A function to use to compare the data.
//!                   The function must returns 0 if the data match,
//!                   non-zero value otherwise
//! @return (int) LIST_SUCCESS if it was a success,
//!         LIST_ERROR if the data was not found
//!         or if 'comparator' is NULL
//!
#define ptr_list_remove_cmp(list, ptr, comparator) \
    (list)->ptr_remove_cmp((list), (ptr), (data_cmp_t)(comparator))
//////////////////////////////////////////////////

///////////// Find node in list /////////////

//!
//! @brief Find a pointer in a pointer list.
//!        Will find the node pointing to the same address
//!
//! @param list The pointer list
//! @param ptr The pointer to find
//! @return (const node_t *) A node pointer, or NULL
//!         if the pointer was not found
//!
#define ptr_list_find(list, ptr)    \
    (list)->ptr_find((list), (ptr))

//!
//! @brief Find a data in a pointer list using a comparator
//!        by passing these pointers as parameter
//!
//! @param list The pointer list
//! @param ptr A pointer to the data to match
//! @param comparator A function to use to compare the data.
//!                   The function must returns 0 if the data match,
//!                   non-zero value otherwise
//! @return (const node_t *) A node pointer, or NULL
//!         if the pointer was not found
//!         or if 'comparator' is NULL
//!
#define ptr_list_find_cmp(list, ptr, comparator)    \
    (list)->ptr_find_cmp((list), (ptr), (data_cmp_t)(comparator))

//!
//! @brief Check if a pointer is in a pointer list
//!
//! @param list The pointer list
//! @param ptr The pointer to find
//! @return (int) LIST_TRUE if it's true, LIST_FALSE otherwise
//!
#define ptr_list_contains(list, ptr)    \
    (list)->ptr_contains((list), (ptr))
/////////////////////////////////////////////////

#endif /* !PTR_LIST_H_ */
