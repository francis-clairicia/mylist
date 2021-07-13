/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list
*/

#ifndef STRING_LIST_H_
#define STRING_LIST_H_

#include "container.h"
#include "base_list.h"

//!
//! @brief The string comparator function type.
//!        The function must returns 0 if the data match,
//!        non-zero value otherwise
//!
typedef int (*string_cmp_t)(const char *, const char *);

typedef struct string_linked_list string_list_t;

//!
//! @brief Structure for a linked list of strings. The strings are a specific
//!        type of data which need a dedicated list implementation.
//!
struct string_linked_list
{
    int (*const str_insert)(string_list_t *this, ssize_t idx, const char *str);
    int (*const str_push_front)(string_list_t *this, const char *str);
    int (*const str_push_back)(string_list_t *this, const char *str);

    void (*const pop)(string_list_t *this, ssize_t index);
    void (*const pop_front)(string_list_t *this);
    void (*const pop_back)(string_list_t *this);
    int (*const str_remove)(string_list_t *this, const char *str);
    int (*const str_remove_cmp)(string_list_t *this,
                                const char *str, string_cmp_t comparator);

    void (*const clear)(string_list_t *this);
    string_list_t *(*const duplicate)(const string_list_t *this);
    void (*const merge)(string_list_t *this, string_list_t *other);
    void (*const reverse)(string_list_t *this);
    void (*const rotate_begin)(string_list_t *this);
    void (*const rotate_end)(string_list_t *this);

    int (*const empty)(const string_list_t *this);
    const node_t *(*const get)(const string_list_t *this, ssize_t index);

    size_t (*const __len__)(const string_list_t *this);
    const node_t *(*const __begin__)(const string_list_t *this);
    const node_t *(*const __end__)(const string_list_t *this);

    const node_t *(*const str_find)(const string_list_t *this, const char *str);
    const node_t *(*const str_find_cmp)(const string_list_t *this,
                                        const char *str,
                                        string_cmp_t comparator);
    int (*const str_contains)(const string_list_t *this, const char *str);

    const container_list_t __c;
};

/////////// Init/destroy a linked list ///////////

//!
//! @brief Create an initialize a new string linked list
//!
//! @return The newly allocated list, or NULL in case of failure
//!
string_list_t *string_list_create(void);

//!
//! @brief Free the whole linked list (nodes + structure),
//!        allocated by string_list_create()
//!
//! @param list The list to destroy
//!
void string_list_destroy(string_list_t *list);
///////////////////////////////////////////////////////////////

///////////// Useful functions /////////////

//!
//! @brief Create a NULL-terminated array of strings from a string list.
//!        Each pointer is the one stored in the list, so use free()
//!        to free the array
//!
//! @param list The string list
//! @param length If not NULL, the array length is stored
//! @return The allocated array
//!
char **string_list_to_array(const string_list_t *list, size_t *length);

//!
//! @brief Create a string list from a NULL-terminated array of strings.
//!        Each string is copied
//!
//! @param array Pointer to the array
//! @return The newly allocated list
//!
string_list_t *array_to_string_list(const char *const *array);

//!
//! @brief Create a string list with default strings.
//!        Each string is copied
//!
//! @param strings Variadic. All the strings to store in the list
//! @return (string_list_t *) The newly allocated list
//!
#define make_string_list(strings...)    \
    array_to_string_list(_FMT_ARRAY(char *, strings, NULL))

//!
//! @brief Concatenate a list of string to an allocated str
//!
//! @param list The string list
//! @param separator The string to put between each string from the list.
//!                  Can be NULL or an empty string
//! @param length If not NULL, the string length is stored
//! @return A new allocated string
//!
char *string_list_concat(
    const string_list_t *list,
    const char *separator,
    size_t *length
);
///////////////////////////////////////////////////////////////

///////////// Add data to linked lists ///////////

//!
//! @brief Insert a string at a certain index
//!
//! @param list The string list
//! @param index (signed long int) The position
//!              (If negative, the search will begin at the end)
//! @param str The string to store (copied)
//! @return (int) LIST_SUCCESS if it was a success, LIST_ERROR otherwise
//!
#define string_list_insert(list, index, str) \
    (list)->str_insert((list), (index), (str))

//!
//! @brief Insert a string at the beginning of the list
//!
//! @param list The string list
//! @param str The string to store (copied)
//! @return (int) LIST_SUCCESS if it was a success, LIST_ERROR otherwise
//!
#define string_list_push_front(list, str) \
    (list)->str_push_front((list), (str))

//!
//! @brief Insert a string at the end of the list
//!
//! @param list The string list
//! @param str The string to store (copied)
//! @return (int) LIST_SUCCESS if it was a success, LIST_ERROR otherwise
//!
#define string_list_push_back(list, str) \
    (list)->str_push_back((list), (str))
//////////////////////////////////////////////////

///////////// Remove data in list /////////////

//!
//! @brief Remove the first occurence of a string from the list
//!
//! @param list The string list
//! @param str The string to remove
//! @return (int) LIST_SUCCESS if it was a success,
//!         LIST_ERROR if the string was not found
//!
#define string_list_remove(list, str) \
    (list)->str_remove((list), (str))

//!
//! @brief Remove the first occurence of a string from the list
//!        using a comparator by passing these strings as parameter
//!
//! @param list The string list
//! @param str The string to remove
//! @param comparator A function to use to compare the data.
//!                   The function must returns 0 if the data match,
//!                   non-zero value otherwise
//! @return (int) LIST_SUCCESS if it was a success,
//!         LIST_ERROR if the string was not found
//!         or if 'comparator' is NULL
//!
#define string_list_remove_cmp(list, str, comparator) \
    (list)->str_remove_cmp((list), (str), (comparator))
//////////////////////////////////////////////////

///////////// Find node in list /////////////

//!
//! @brief Find a string in a string list
//!
//! @param list The string list
//! @param str The string to find
//! @return (const node_t *) A node pointer, or NULL
//!         if the string was not found
//!
#define string_list_find(list, str)    \
    (list)->str_find((list), (str))

//!
//! @brief Find a string in a string list
//!        using a comparator by passing these strings as parameter
//!
//! @param list The string list
//! @param str The string to find
//! @param comparator A function to use to compare the data.
//!                   The function must returns 0 if the data match,
//!                   non-zero value otherwise
//! @return (const node_t *) A node pointer, or NULL
//!         if the string was not found
//!         or if 'comparator' is NULL
//!
#define string_list_find_cmp(list, str, comparator)    \
    (list)->str_find_cmp((list), (str), (comparator))

//!
//! @brief Check if a string is in a string list
//!
//! @param list The string list
//! @param ptr The string to find
//! @return (int) LIST_TRUE if it's true, LIST_FALSE otherwise
//!
#define string_list_contains(list, str)    \
    (list)->str_contains((list), (str))
/////////////////////////////////////////////////

#endif /* !STRING_LIST_H_ */
