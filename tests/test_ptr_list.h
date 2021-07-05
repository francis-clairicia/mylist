/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** test_ptr_list
*/

#ifndef TEST_PTR_LIST_H_
#define TEST_PTR_LIST_H_

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylist/ptr_list.h"

#define TestList(function, desc, ...)   \
    Test(ptr_list, function##_##desc, ##__VA_ARGS__)

#endif /* !TEST_PTR_LIST_H_ */
