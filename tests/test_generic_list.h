/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** test_generic_list
*/

#ifndef TEST_GENERIC_LIST_H_
#define TEST_GENERIC_LIST_H_

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylist/generic_list.h"

#define TestList(function, desc, ...)   \
    Test(generic_list, function##_##desc, ##__VA_ARGS__)

#endif /* !TEST_GENERIC_LIST_H_ */
