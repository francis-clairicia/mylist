/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** test_string_list
*/

#ifndef TEST_STRING_LIST_H_
#define TEST_STRING_LIST_H_

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylist/string_list.h"

#define TestList(function, desc, ...)   \
    Test(string_list, function##_##desc, ##__VA_ARGS__)

#endif /* !TEST_STRING_LIST_H_ */
