/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** test_string_list
*/

#include <string.h>
#include "test_string_list.h"

static void test_methods(const string_list_t *list)
{
    cr_assert_not_null(list->str_insert);
    cr_assert_not_null(list->str_push_front);
    cr_assert_not_null(list->str_push_back);
    cr_assert_not_null(list->pop);
    cr_assert_not_null(list->pop_front);
    cr_assert_not_null(list->pop_back);
    cr_assert_not_null(list->str_remove);
    cr_assert_not_null(list->str_remove_cmp);
    cr_assert_not_null(list->clear);
    cr_assert_not_null(list->duplicate);
    cr_assert_not_null(list->merge);
    cr_assert_not_null(list->reverse);
    cr_assert_not_null(list->rotate_begin);
    cr_assert_not_null(list->rotate_end);
    cr_assert_not_null(list->empty);
    cr_assert_not_null(list->get);
    cr_assert_not_null(list->__len__);
    cr_assert_not_null(list->__begin__);
    cr_assert_not_null(list->__end__);
    cr_assert_not_null(list->__get_dtor__);
    cr_assert_not_null(list->str_find);
    cr_assert_not_null(list->str_find_cmp);
    cr_assert_not_null(list->str_contains);
}

TestList(string_list_create, allocate_a_string_list)
{
    string_list_t *list = string_list_create();

    cr_assert_not_null(list);
    test_methods(list);
    cr_assert(list_empty(list));
    cr_assert_null(list_begin(list));
    cr_assert_null(list_end(list));
}

TestList(string_list_push_front, push_a_copy_of_a_string_in_list)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_front(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_front(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_front(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_c");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 2)), "string_a");
}

TestList(string_list_push_front, do_not_insert_for_null_pointer)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_front(list, NULL), LIST_ERROR);
    cr_assert(list_empty(list));
}

TestList(string_list_push_back, push_a_copy_of_a_string_in_list)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 2)), "string_c");
}

TestList(string_list_push_back, do_not_insert_for_null_pointer)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, NULL), LIST_ERROR);
    cr_assert(list_empty(list));
}


TestList(string_list_insert, inset_at_start)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_insert(list, 0, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_insert(list, 0, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_insert(list, 0, "string_c"), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_c");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 2)), "string_a");
}

TestList(string_list_insert, insert_at_end)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_insert(list, -1, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_insert(list, -1, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_insert(list, -1, "string_c"), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 2)), "string_c");
}

TestList(string_list_insert, inset_at_index)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_insert(list, 1, "string_d"), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 4);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_d");
    cr_assert_str_eq(NODE_STR(list_get(list, 2)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 3)), "string_c");
}

TestList(string_list_insert, inset_at_negative_index)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_insert(list, -2, "string_d"), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 4);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 2)), "string_d");
    cr_assert_str_eq(NODE_STR(list_get(list, 3)), "string_c");
}

TestList(string_list_get, get_a_node_from_a_list)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(list_get(list, 0), list_begin(list));
    cr_assert_eq(list_get(list, 1), list_begin(list)->next);
    cr_assert_eq(list_get(list, 2), list_begin(list)->next->next);
    cr_assert_eq(list_get(list, 2), list_end(list));
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 2)), "string_c");
}

TestList(string_list_pop_front, delete_first_string)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    list_pop_front(list);
    cr_assert_eq(list_len(list), 2);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_c");
}

TestList(string_list_pop_front, do_nothing_if_the_list_is_empty)
{
    string_list_t *list = string_list_create();

    list_pop_front(list);
}

TestList(string_list_pop_back, delete_last_string)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    list_pop_back(list);
    cr_assert_eq(list_len(list), 2);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
}

TestList(string_list_pop_back, do_nothing_if_the_list_is_empty)
{
    string_list_t *list = string_list_create();

    list_pop_back(list);
}

TestList(string_list_pop, delete_first_string)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    list_pop(list, 0);
    cr_assert_eq(list_len(list), 2);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_c");
}

TestList(string_list_pop, delete_last_string)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    list_pop(list, -1);
    cr_assert_eq(list_len(list), 2);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
}

TestList(string_list_pop, delete_middle_data)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    list_pop(list, 1);
    cr_assert_eq(list_len(list), 2);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_c");
}

TestList(string_list_pop, delete_middle_data_with_negative_index)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    list_pop(list, -2);
    cr_assert_eq(list_len(list), 2);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_c");
}

TestList(string_list_pop, do_nothing_the_list_empty)
{
    string_list_t *list = string_list_create();

    list_pop(list, 123);
    list_pop(list, -25);
    cr_assert(list_empty(list));
}

TestList(string_list_clear, delete_all_nodes)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    list_clear(list);
    cr_assert(list_empty(list));
}

TestList(string_list_destroy, destroy_the_linked_list)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    string_list_destroy(list);
}

TestList(string_list_destructor, should_be_null)
{
    string_list_t *list = string_list_create();

    cr_assert_null(list_destructor(list));
}

TestList(string_list_dup, duplicate_list)
{
    string_list_t *list = string_list_create();
    string_list_t *list2 = NULL;

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    list2 = list_dup(list);
    cr_assert_not_null(list2);
    cr_assert_eq(list_len(list), list_len(list2));
    const node_t *n1 = list_begin(list);
    const node_t *n2 = list_begin(list2);
    for (; n1 && n2; n1 = n1->next, n2 = n2->next) {
        cr_assert_str_eq(NODE_STR(n1), NODE_STR(n2));
    }
}

TestList(string_list_merge, merge_two_linked_lists)
{
    string_list_t *list = string_list_create();
    string_list_t *list2 = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list2, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list2, "string_d"), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(list_len(list2), 2);
    list_merge(list, list2);
    cr_assert_eq(list_len(list), 4);
    cr_assert_eq(list_len(list2), 0);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 2)), "string_c");
    cr_assert_str_eq(NODE_STR(list_get(list, 3)), "string_d");
}

TestList(string_list_merge, swap_if_this_is_empty)
{
    string_list_t *list = string_list_create();
    string_list_t *list2 = string_list_create();

    cr_assert_eq(string_list_push_back(list2, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list2, "string_b"), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 0);
    cr_assert_eq(list_len(list2), 2);
    list_merge(list, list2);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(list_len(list2), 0);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
}

TestList(string_list_merge, do_nothing_if_list2_is_empty)
{
    string_list_t *list = string_list_create();
    string_list_t *list2 = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(list_len(list2), 0);
    list_merge(list, list2);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(list_len(list2), 0);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
}

TestList(string_list_merge, do_nothing_if_list2_is_null)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    list_merge(list, NULL);
    cr_assert_eq(list_len(list), 2);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
}

TestList(string_list_reverse, reverse_a_linked_list)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_d"), LIST_SUCCESS);
    list_reverse(list);
    cr_assert_eq(list_len(list), 4);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_d");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_c");
    cr_assert_str_eq(NODE_STR(list_get(list, 2)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 3)), "string_a");
}

TestList(string_list_rotate_begin, put_first_node_at_end)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_d"), LIST_SUCCESS);
    list_rotate_begin(list);
    cr_assert_eq(list_len(list), 4);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_c");
    cr_assert_str_eq(NODE_STR(list_get(list, 2)), "string_d");
    cr_assert_str_eq(NODE_STR(list_get(list, 3)), "string_a");
}

TestList(string_list_rotate_end, put_last_node_at_start)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_d"), LIST_SUCCESS);
    list_rotate_end(list);
    cr_assert_eq(list_len(list), 4);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_d");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 2)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 3)), "string_c");
}

TestList(string_list_find, find_a_string_in_list)
{
    string_list_t *list = string_list_create();
    const node_t *node = NULL;

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_d"), LIST_SUCCESS);
    node = string_list_find(list, "string_c");
    cr_assert_not_null(node);
    cr_assert_eq(node, list_get(list, 2));
}

TestList(string_list_find, returns_null_if_string_was_not_found)
{
    string_list_t *list = string_list_create();
    const node_t *node = NULL;

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_d"), LIST_SUCCESS);
    node = string_list_find(list, "unknown");
    cr_assert_null(node);
}

TestList(string_list_find, returns_null_if_string_is_null)
{
    string_list_t *list = string_list_create();
    const node_t *node = NULL;

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_d"), LIST_SUCCESS);
    node = string_list_find(list, NULL);
    cr_assert_null(node);
}

TestList(string_list_find_cmp, find_a_string_in_list_using_comparator)
{
    string_list_t *list = string_list_create();
    const node_t *node = NULL;

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_d"), LIST_SUCCESS);
    node = string_list_find_cmp(list, "STRING_C", &strcasecmp);
    cr_assert_not_null(node);
    cr_assert_eq(node, list_get(list, 2));
}

TestList(string_list_find_cmp, returns_null_if_comparator_is_null)
{
    string_list_t *list = string_list_create();
    const node_t *node = NULL;

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_d"), LIST_SUCCESS);
    node = string_list_find_cmp(list, "string_c", NULL);
    cr_assert_null(node);
}

TestList(string_list_find_cmp, returns_null_if_string_is_null)
{
    string_list_t *list = string_list_create();
    const node_t *node = NULL;

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_d"), LIST_SUCCESS);
    node = string_list_find_cmp(list, NULL, &strcmp);
    cr_assert_null(node);
}

TestList(string_list_contains, find_a_string_in_list)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_d"), LIST_SUCCESS);
    cr_assert(string_list_contains(list, "string_c"));
}

TestList(string_list_contains, returns_false_if_string_was_not_found)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_d"), LIST_SUCCESS);
    cr_assert_not(string_list_contains(list, "unknown"));
}

TestList(string_list_contains, returns_false_if_string_is_null)
{
    string_list_t *list = string_list_create();

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_d"), LIST_SUCCESS);
    cr_assert_not(string_list_contains(list, NULL));
}

TestList(string_list_remove, remove_a_specific_string)
{
    string_list_t *list = make_string_list("string_a", "string_b", "string_c");

    cr_assert_not_null(list);
    cr_assert_eq(string_list_remove(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_c");
}

TestList(string_list_remove, returns_error_for_unknown_pointer)
{
    string_list_t *list = make_string_list("string_a", "string_b", "string_c");

    cr_assert_not_null(list);
    cr_assert_eq(string_list_remove(list, "STRING_B"), LIST_ERROR);
    cr_assert_eq(list_len(list), 3);
}

TestList(string_list_remove, do_nothing_with_null_pointer)
{
    string_list_t *list = make_string_list("string_a", "string_b", "string_c");

    cr_assert_not_null(list);
    cr_assert_eq(string_list_remove(list, NULL), LIST_ERROR);
    cr_assert_eq(list_len(list), 3);
}

TestList(string_list_remove_cmp, remove_a_specific_string)
{
    string_list_t *list = make_string_list("string_a", "string_b", "string_c");

    cr_assert_not_null(list);
    cr_assert_eq(string_list_remove_cmp(list, "STRING_B", &strcasecmp), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_c");
}

TestList(string_list_remove_cmp, do_nothing_with_null_comparator)
{
    string_list_t *list = make_string_list("string_a", "string_b", "string_c");

    cr_assert_not_null(list);
    cr_assert_eq(string_list_remove_cmp(list, "string_b", NULL), LIST_ERROR);
    cr_assert_eq(list_len(list), 3);
}

TestList(string_list_to_array, make_a_string_array_from_list)
{
    string_list_t *list = string_list_create();
    char **array = NULL;

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    array = string_list_to_array(list, NULL);
    cr_assert_not_null(array);
    cr_assert_str_eq(array[0], "string_a");
    cr_assert_str_eq(array[1], "string_b");
    cr_assert_str_eq(array[2], "string_c");
    cr_assert_null(array[3]);
}

TestList(string_list_to_array, make_a_string_array_from_list_with_size)
{
    string_list_t *list = string_list_create();
    char **array = NULL;
    size_t array_size;

    cr_assert_eq(string_list_push_back(list, "string_a"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_b"), LIST_SUCCESS);
    cr_assert_eq(string_list_push_back(list, "string_c"), LIST_SUCCESS);
    array = string_list_to_array(list, &array_size);
    cr_assert_not_null(array);
    cr_assert_eq(array_size, 3);
    cr_assert_str_eq(array[0], "string_a");
    cr_assert_str_eq(array[1], "string_b");
    cr_assert_str_eq(array[2], "string_c");
    cr_assert_null(array[array_size]);
}

TestList(string_list_to_array, returns_empty_array_if_list_is_empty)
{
    string_list_t *list = string_list_create();
    char **array = NULL;
    size_t array_size;

    array = string_list_to_array(list, &array_size);
    cr_assert_not_null(array);
    cr_assert_eq(array_size, 0);
    cr_assert_null(array[array_size]);
}

TestList(string_list_to_array, returns_null_if_list_is_null)
{
    char **array = NULL;
    size_t array_size;

    array = string_list_to_array(NULL, &array_size);
    cr_assert_null(array);
    cr_assert_eq(array_size, 0);
}

TestList(array_to_string_list, make_a_list_from_an_array)
{
    const char *array[] = {"string_a", "string_b", "string_c", NULL};
    string_list_t *list = array_to_string_list(array);

    cr_assert_not_null(list);
    cr_assert_eq(list_len(list), 3);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 2)), "string_c");
}

TestList(array_to_string_list, do_nothing_for_null_array)
{
    string_list_t *list = array_to_string_list(NULL);

    cr_assert_null(list);
}

TestList(make_string_list, create_a_list_with_default_values)
{
    string_list_t *list = make_string_list("string_a", "string_b", "string_c");

    cr_assert_not_null(list);
    cr_assert_eq(list_len(list), 3);
    cr_assert_str_eq(NODE_STR(list_get(list, 0)), "string_a");
    cr_assert_str_eq(NODE_STR(list_get(list, 1)), "string_b");
    cr_assert_str_eq(NODE_STR(list_get(list, 2)), "string_c");
}

TestList(string_list_concat, concatenate_all_string_into_a_single_one)
{
    string_list_t *list = make_string_list("string_a", "string_b", "string_c");
    char *str = string_list_concat(list, NULL, NULL);

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "string_astring_bstring_c");
}

TestList(string_list_concat, with_empty_separator)
{
    string_list_t *list = make_string_list("string_a", "string_b", "string_c");
    char *str = string_list_concat(list, "", NULL);

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "string_astring_bstring_c");
}

TestList(string_list_concat, with_separators)
{
    string_list_t *list = make_string_list("string_a", "string_b", "string_c");
    char *str = string_list_concat(list, "----", NULL);

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "string_a----string_b----string_c");
}

TestList(string_list_concat, fill_length_pointer)
{
    string_list_t *list = make_string_list("string_a", "string_b", "string_c");
    size_t length;
    char *str = string_list_concat(list, "----", &length);
    const char expected[] = "string_a----string_b----string_c";

    cr_assert_not_null(str);
    cr_assert_str_eq(str, expected);
    cr_assert_eq(length, strlen(expected));
}

TestList(string_list_concat, does_nothing_with_null_list)
{
    size_t length;
    char *str = string_list_concat(NULL, ", ", &length);

    cr_assert_null(str);
    cr_assert_eq(length, 0);
}

TestList(string_list_concat, creates_an_empty_string_if_the_list_is_empty)
{
    size_t length;
    string_list_t *list = string_list_create();
    char *str = string_list_concat(list, ", ", &length);

    cr_assert_not_null(str);
    cr_assert_str_empty(str);
    cr_assert_eq(length, 0);
}
