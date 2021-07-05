/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** test_node_iterator
*/

#include <criterion/criterion.h>
#include "mylist/generic_list.h"

Test(node_iter_start, initialize_an_iterator)
{
    list_t *list = make_generic_list(NULL, int, 5, 27, -4);
    node_iterator_t node;

    cr_assert_not_null(list);
    node = node_iter_start(list_begin(list), 0);
    cr_assert_eq(node.data.ptr, list_begin(list)->data.ptr);
    cr_assert_eq(node.data.size, list_begin(list)->data.size);
    cr_assert_eq(node.next, list_begin(list)->next);
    cr_assert_eq(node.previous, list_begin(list)->previous);
    cr_assert_eq(node.index, 0);
}

Test(node_iter_start, does_nothing_with_null_pointer)
{
    node_iterator_t node;

    node = node_iter_start(NULL, 0);
    cr_assert_null(node.data.ptr);
    cr_assert_eq(node.data.size, 0);
    cr_assert_null(node.next);
    cr_assert_null(node.previous);
    cr_assert_eq(node.index, 0);
}

Test(list_iter_begin, begin_list_iterator)
{
    list_t *list = make_generic_list(NULL, int, 5, 27, -4);
    node_iterator_t node;

    cr_assert_not_null(list);
    node = list_iter_begin(list);
    cr_assert_eq(node.data.ptr, list_begin(list)->data.ptr);
    cr_assert_eq(node.data.size, list_begin(list)->data.size);
    cr_assert_eq(node.next, list_begin(list)->next);
    cr_assert_eq(node.previous, list_begin(list)->previous);
    cr_assert_eq(node.index, 0);
}

Test(list_iter_end, end_list_iterator)
{
    list_t *list = make_generic_list(NULL, int, 5, 27, -4);
    node_iterator_t node;

    cr_assert_not_null(list);
    node = list_iter_end(list);
    cr_assert_eq(node.data.ptr, list_end(list)->data.ptr);
    cr_assert_eq(node.data.size, list_end(list)->data.size);
    cr_assert_eq(node.next, list_end(list)->next);
    cr_assert_eq(node.previous, list_end(list)->previous);
    cr_assert_eq(node.index, 2);
}

Test(node_iter_next, go_to_next_node)
{
    list_t *list = make_generic_list(NULL, int, 5, 27, -4);
    node_iterator_t node;

    cr_assert_not_null(list);
    node = list_iter_begin(list);
    cr_assert_eq(NODE_DATA(&node, int), 5);
    cr_assert_eq(node.index, 0);
    node_iter_next(&node);
    cr_assert_eq(NODE_DATA(&node, int), 27);
    cr_assert_eq(node.index, 1);
    node_iter_next(&node);
    cr_assert_eq(NODE_DATA(&node, int), -4);
    cr_assert_eq(node.index, 2);
    node_iter_next(&node);
    cr_assert_null(node.data.ptr);
}

Test(node_iter_next, does_nothing_with_null_pointer)
{
    node_iter_next(NULL);
}

Test(node_iter_prev, go_to_previous_node)
{
    list_t *list = make_generic_list(NULL, int, 5, 27, -4);
    node_iterator_t node;

    cr_assert_not_null(list);
    node = list_iter_end(list);
    cr_assert_eq(NODE_DATA(&node, int), -4);
    cr_assert_eq(node.index, 2);
    node_iter_prev(&node);
    cr_assert_eq(NODE_DATA(&node, int), 27);
    cr_assert_eq(node.index, 1);
    node_iter_prev(&node);
    cr_assert_eq(NODE_DATA(&node, int), 5);
    cr_assert_eq(node.index, 0);
    node_iter_prev(&node);
    cr_assert_null(node.data.ptr);
}

Test(node_iter_prev, does_nothing_with_null_pointer)
{
    node_iter_prev(NULL);
}
