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

typedef struct string_linked_list string_list_t;

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
                                const char *str, data_cmp_t comparator);

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
                                        const char *str, data_cmp_t comparator);
    int (*const str_contains)(const string_list_t *this, const char *str);

    const container_list_t __c;
};

/////////// Init a linked list ///////////
// (destructor is a pointer to the function to use to free the node data)
//

// Creates an initializes a new string linked list
string_list_t *string_list_create(void);
//////////////////////////////////////////

/////////// Destroy a linked list ///////////

// Free the whole linked list (nodes + structure)
// allocated by string_list_create() and sets list variable to NULL
void string_list_destroy(string_list_t *list);
///////////////////////////////////////////////////////////////

///////////// Useful functions /////////////

// Create a NULL-terminated array of strings from a string list
// If length is not NULL, the array length is stored
// Each pointer is the one stored in the list, so use free() to free the array
char **string_list_to_array(const string_list_t *list, size_t *length);

// Create a string list from a NULL-terminated array of strings
// Each string is copied
string_list_t *array_to_string_list(const char *const *array);

// Create a string list with default strings
#define make_string_list(strings...)    \
    array_to_string_list(_FMT_ARRAY(const char *, strings, NULL))

// Concatenate a list of string to an allocated str
char *string_list_concat(
    const string_list_t *list,
    const char *separator,
    size_t *length
);
///////////////////////////////////////////////////////////////

///////////// Add data to linked lists ///////////

// Insert a string at a certain index
// (If 'index' is negative the search will begin at the end)
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define string_list_insert(list, index, str) \
    (list)->str_insert((list), (index), (str))

// Insert a string at the beginning of the list
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define string_list_push_front(list, str) \
    (list)->str_push_front((list), (str))

// Insert a string at the end of the list
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define string_list_push_back(list, str) \
    (list)->str_push_back((list), (str))
//////////////////////////////////////////////////

///////////// Remove data in list /////////////

// Remove the first occurence of a string from the list
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
#define string_list_remove(list, str) \
    (list)->str_remove((list), (str))

// Remove the first occurence of a string from the list using a comparator
// The comparator function must returns 0 if the data match,
// non-zero value otherwise
// Returns LIST_SUCCESS (1) if it was a success, LIST_ERROR (0) otherwise
// Returns LIST_ERROR for NULL comparator
#define string_list_remove_cmp(list, str, comparator) \
    (list)->str_remove_cmp((list), (str), (data_cmp_t)(comparator))
//////////////////////////////////////////////////

///////////// Find node in list /////////////

// Find a string in a generic list
// Returns the node, or NULL if the string was not found
#define string_list_find(list, str)    \
    (list)->str_find((list), (str))

// Find a string in a string list using a comparator by passing these strings
// as parameter
// The comparator function must returns 0 if the data match,
// non-zero value otherwise
// Returns the node, or NULL if the string was not found
// Returns NULL for NULL comparator
#define string_list_find_cmp(list, str, comparator)    \
    (list)->str_find_cmp((list), (str), (data_cmp_t)(comparator))

// Check if a string is in a generic list
// Return 1 if it's 1, 0 otherwise
#define string_list_contains(list, str)    \
    (list)->str_contains((list), (str))
/////////////////////////////////////////////////

// Get the string data inside the node (string_list_t)
#define NODE_STR(node) ((char *)((node)->data.ptr))

#endif /* !STRING_LIST_H_ */
