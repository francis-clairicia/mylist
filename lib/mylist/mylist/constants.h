/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** constants
*/

#ifndef MY_LIST_CONSTANTS_H_
#define MY_LIST_CONSTANTS_H_

//!
//! @brief enum to state an action on a linked list
//!
enum ENUM_LIST_RESULT
{
    LIST_ERROR = 0,   // An error occured
    LIST_SUCCESS = 1  // The action was a success
};

//!
//! @brief simple boolean state
//!
enum ENUM_LIST_BOOL
{
    LIST_FALSE = 0, // 'false' boolean
    LIST_TRUE = 1   // 'true' boolean
};

/////////// Internal functions/Macros used for linked lists ///////////

#define _FMT_DATA(data, type) ((type const [1]){(data)})
#define _FMT_ARRAY(type, values...) ((type const []){values})
#define _FMT_ARRAY_SIZE(type, values...)    \
    (sizeof(_FMT_ARRAY(type, values)) / sizeof(type))

//////////////////////////////////////////////////////////////////////

#endif /* !MY_LIST_CONSTANTS_H_ */
