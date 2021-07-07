/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list
*/

#ifndef GENERIC_LIST_H_
#define GENERIC_LIST_H_

#include "container.h"
#include "base_list.h"

typedef struct generic_linked_list list_t;

//!
//! @brief Structure for generic linked list object
//!
struct generic_linked_list
{
    int (*const insert)(list_t *this, ssize_t idx,
                        const void *data, size_t size);
    int (*const push_front)(list_t *this, const void *data, size_t size);
    int (*const push_back)(list_t *this, const void *data, size_t size);

    void *(*const emplace)(list_t *this, ssize_t idx, size_t size);
    void *(*const emplace_front)(list_t *this, size_t size);
    void *(*const emplace_back)(list_t *this, size_t size);

    void (*const pop)(list_t *this, ssize_t index);
    void (*const pop_front)(list_t *this);
    void (*const pop_back)(list_t *this);
    int (*const remove)(list_t *this, const void *data, size_t size);
    int (*const remove_cmp)(list_t *this, const void *data,
                            data_cmp_t comparator);

    void (*const clear)(list_t *this);
    list_t *(*const duplicate)(const list_t *this);
    void (*const merge)(list_t *this, list_t *other);
    void (*const reverse)(list_t *this);
    void (*const rotate_begin)(list_t *this);
    void (*const rotate_end)(list_t *this);

    int (*const empty)(const list_t *this);
    const node_t *(*const get)(const list_t *this, ssize_t index);

    size_t (*const __len__)(const list_t *this);
    const node_t *(*const __begin__)(const list_t *this);
    const node_t *(*const __end__)(const list_t *this);
    node_dtor_t (*const __get_dtor__)(const list_t *this);

    const node_t *(*const find)(const list_t *this,
                                const void *data, size_t size);
    const node_t *(*const find_cmp)(const list_t *this, const void *data,
                                    data_cmp_t comparator);
    int (*const contains)(const list_t *this, const void *data, size_t size);

    const container_list_t __c;
};

/////////// Init/destroy a linked list ///////////

//!
//! @brief Create and initialize a new generic linked list
//!
//! @param destructor A pointer to the function to use to free the node data,
//!                   or NULL if there is no function to use
//! @return The newly allocated list, or NULL in case of failure
//!
list_t *generic_list_create(node_dtor_t destructor);

//!
//! @brief Free the whole linked list (nodes + structure),
//!        allocated by generic_list_create()
//!
//! @param list The list to destroy
//!
void generic_list_destroy(list_t *list);
///////////////////////////////////////////////////////////////

///////////// Useful functions /////////////

//!
//! @brief Create an array from a generic list. If the list is empty,
//!        this functions returns NULL and sets length to 0
//!
//! @param list The generic list
//! @param length If not NULL, the array length is stored
//! @return The allocated array
//!
void *generic_list_to_array(const list_t *list, size_t *length);

//!
//! @brief Create a generic list of nmemb elements from an array
//!        of nmemb elements each size bytes long
//!
//! @param array Pointer to the array
//! @param size The size of an element
//! @param nmemb The number of elements
//! @param destructor The node data destructor for the list
//! @return The newly allocated list
//!
list_t *array_to_generic_list(
    const void *array,
    size_t size,
    size_t nmemb,
    node_dtor_t destructor
);

//!
//! @brief Create a generic list with default values
//!
//! @param destructor The node data destructor fo the list
//! @param type the type of the elements to put in the list
//! @param values Variadic. All the value to put in the list
//! @return (list_t *) The newly allocated list
//!
#define make_generic_list(destructor, type, values...)              \
    array_to_generic_list(_FMT_ARRAY(type, values), sizeof(type),   \
                        _FMT_ARRAY_SIZE(type, values), destructor)
///////////////////////////////////////////////////////////////

///////////// Add data to linked lists ///////////

//!
//! @brief Insert a data at a certain index
//!
//! @param list The generic list pointer
//! @param index (long int) The position
//!              (If negative, the search will begin at the end)
//! @param data The data to store (copied)
//! @param type The data type
//! @return (int) LIST_SUCCESS if it was a success, LIST_ERROR otherwise
//!
#define generic_list_insert(list, index, data, type) \
    (list)->insert((list), (index), _FMT_DATA(data, type), sizeof(type))

//!
//! @brief Insert a data at a certain index.
//!        Optimized version of generic_list_insert() for variables
//!
//! @param list The generic list pointer
//! @param index (long int) The position
//!              (If negative, the search will begin at the end)
//! @param data The data variable to store (copied)
//! @param type The data type
//! @return (int) LIST_SUCCESS if it was a success, LIST_ERROR otherwise
//!
#define generic_list_insert_var(list, index, data, type) \
    (list)->insert((list), (index), &(data), sizeof(type))

//!
//! @brief Insert a data at the beginning of the list
//!
//! @param list The generic list pointer
//! @param data The data to store (copied)
//! @param type The data type
//! @return (int) LIST_SUCCESS if it was a success, LIST_ERROR otherwise
//!
#define generic_list_push_front(list, data, type)    \
    (list)->push_front((list), _FMT_DATA(data, type), sizeof(type))

//!
//! @brief Insert a data at the beginning of the list.
//!        Optimized version of generic_list_push_front() for variables
//!
//! @param list The generic list pointer
//! @param data The data variable to store (copied)
//! @param type The data type
//! @return (int) LIST_SUCCESS if it was a success, LIST_ERROR otherwise
//!
#define generic_list_push_front_var(list, data, type)    \
    (list)->push_front((list), &(data), sizeof(type))

//!
//! @brief Insert a data at the end of the list
//!
//! @param list The generic list pointer
//! @param data The data to store (copied)
//! @param type The data type
//! @return (int) LIST_SUCCESS if it was a success, LIST_ERROR otherwise
//!
#define generic_list_push_back(list, data, type) \
    (list)->push_back((list), _FMT_DATA(data, type), sizeof(type))

//!
//! @brief Insert a data at the end of the list.
//!        Optimized version of generic_list_push_back() for variables
//!
//! @param list The generic list pointer
//! @param data The data variable to store (copied)
//! @param type The data type
//! @return (int) LIST_SUCCESS if it was a success, LIST_ERROR otherwise
//!
#define generic_list_push_back_var(list, data, type) \
    (list)->push_back((list), &(data), sizeof(type))

//!
//! @brief Emplace a storage data at a certain index
//!
//! @param list The generic list pointer
//! @param index (long int) The position
//!              (If negative the search will begin at the end)
//! @param type The data type
//! @return (type *) A pointer to the allocated storage,
//!         or NULL in case of failure
//!
#define generic_list_emplace(list, index, type) \
    ((type *)((list)->emplace((list), (index), sizeof(type))))

//!
//! @brief Emplace a storage data at the beginning of the list
//!
//! @param list The generic list pointer
//! @param type The data type
//! @return (type *) A pointer to the allocated storage,
//!         or NULL in case of failure
//!
#define generic_list_emplace_front(list, type) \
    ((type *)((list)->emplace_front((list), sizeof(type))))

//!
//! @brief Emplace a storage data at the end of the list
//!
//! @param list The generic list pointer
//! @param type The data type
//! @return (type *) A pointer to the allocated storage,
//!         or NULL in case of failure
//!
#define generic_list_emplace_back(list, type) \
    ((type *)((list)->emplace_back((list), sizeof(type))))
//////////////////////////////////////////////////

///////////// Remove data in list /////////////

//!
//! @brief Remove the first occurence of a data from the list
//!
//! @param list The generic list pointer
//! @param data The data to remove
//! @param type The data type
//! @return (int) LIST_SUCCESS if it was a success,
//!         LIST_ERROR if the data was not found
//!
#define generic_list_remove(list, data, type) \
    (list)->remove((list), _FMT_DATA(data, type), sizeof(type))

//!
//! @brief Remove the first occurence of a data from the list.
//!        Optimized version of generic_list_remove() for variables
//!
//! @param list The generic list pointer
//! @param data The data variable to remove
//! @param type The data type
//! @return (int) LIST_SUCCESS if it was a success,
//!         LIST_ERROR if the data was not found
//!
#define generic_list_remove_var(list, data, type) \
    (list)->remove((list), &(data), sizeof(type))

//!
//! @brief Remove the first occurence of a data from the list using a comparator
//!
//! @param list The generic list pointer
//! @param data The data to remove
//! @param type The data type
//! @param comparator A function to use to compare the data.
//!                   The function must returns 0 if the data match,
//!                   non-zero value otherwise
//! @return (int) LIST_SUCCESS if it was a success,
//!         LIST_ERROR if the data was not found
//!
#define generic_list_remove_cmp(list, data, type, comparator) \
    (list)->remove_cmp((list), _FMT_DATA(data, type), (data_cmp_t)(comparator))

//!
//! @brief Remove the first occurence of a data from the list
//!        using a comparator.
//!        Optimized version of generic_list_remove_cmp() for variables
//!
//! @param list The generic list pointer
//! @param data The data variable to remove
//! @param comparator A function to use to compare the data.
//!                   The function must returns 0 if the data match,
//!                   non-zero value otherwise
//! @return (int) LIST_SUCCESS if it was a success,
//!         LIST_ERROR if the data was not found
//!
#define generic_list_remove_cmp_var(list, data, comparator) \
    (list)->remove_cmp((list), &(data), (data_cmp_t)(comparator))
//////////////////////////////////////////////////

///////////// Find node in list /////////////

//!
//! @brief Find a data in a generic list
//!
//! @param list The generic list pointer
//! @param data The data to find
//! @param type The data type
//! @return (const node_t *) A node pointer, or NULL if the data was not found
//!
#define generic_list_find(list, data, type)    \
    (list)->find((list), _FMT_DATA(data, type), sizeof(type))

//!
//! @brief Find a data in a generic list.
//!        Optimized version of generic_list_find() for variables
//!
//! @param list The generic list pointer
//! @param data The data variable to find
//! @param type The data type
//! @return (const node_t *) A node pointer, or NULL if the data was not found
//!
#define generic_list_find_var(list, data, type)    \
    (list)->find((list), &(data), sizeof(type))

//!
//! @brief Find a data in a generic list using a comparator
//!
//! @param list The generic list pointer
//! @param data The data to find
//! @param type The data type
//! @param comparator A function to use to compare the data.
//!                   The function must returns 0 if the data match,
//!                   non-zero value otherwise
//! @return (const node_t *) A node pointer, or NULL if the data was not found
//!         or if 'comparator' is NULL
//!
#define generic_list_find_cmp(list, data, type, comparator)    \
    (list)->find_cmp((list), _FMT_DATA(data, type), (data_cmp_t)(comparator))

//!
//! @brief Find a data in a generic list using a comparator.
//!        Optimized version of generic_list_find_cmp() for variables
//!
//! @param list The generic list pointer
//! @param data The data variable to find
//! @param comparator A function to use to compare the data.
//!                   The function must returns 0 if the data match,
//!                   non-zero value otherwise
//! @return (const node_t *) A node pointer, or NULL if the data was not found
//!         or if 'comparator' is NULL
//!
#define generic_list_find_cmp_var(list, data, comparator)    \
    (list)->find_cmp((list), &(data), (data_cmp_t)(comparator))

//!
//! @brief Check if a data is in a generic list
//!
//! @param list The generic list pointer
//! @param data The data to find
//! @param type The data type
//! @return (int) LIST_TRUE if it's true, LIST_FALSE otherwise
//!
#define generic_list_contains(list, data, type)    \
    (list)->contains((list), _FMT_DATA(data, type), sizeof(type))

//!
//! @brief Check if a data is in a generic list.
//!        Optimized version of generic_list_contains() for variables
//!
//! @param list The generic list pointer
//! @param data The data variable to find
//! @param type The data type
//! @return (int) LIST_TRUE if it's true, LIST_FALSE otherwise
//!
#define generic_list_contains_var(list, data, type)    \
    (list)->contains((list), &(data), sizeof(type))
//////////////////////////////////////////////////

#endif /* !GENERIC_LIST_H_ */
