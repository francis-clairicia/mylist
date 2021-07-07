/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** test_ptr_list
*/

#include "test_ptr_list.h"

static void test_methods(const ptr_list_t *list)
{
    cr_assert_not_null(list->ptr_insert);
    cr_assert_not_null(list->ptr_push_front);
    cr_assert_not_null(list->ptr_push_back);
    cr_assert_not_null(list->pop);
    cr_assert_not_null(list->pop_front);
    cr_assert_not_null(list->pop_back);
    cr_assert_not_null(list->ptr_remove);
    cr_assert_not_null(list->ptr_remove_cmp);
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
    cr_assert_not_null(list->ptr_find);
    cr_assert_not_null(list->ptr_find_cmp);
    cr_assert_not_null(list->ptr_contains);
}

static void custom_int_destructor(int *value)
{
    printf("Destroying an int pointer containing %d\n", *value);
    fflush(stdout);
    free(value);
}

TestList(ptr_list_create, allocate_a_ptr_list)
{
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_not_null(list);
    test_methods(list);
    cr_assert(list_empty(list));
    cr_assert_null(list_begin(list));
    cr_assert_null(list_end(list));
}

TestList(ptr_list_create, allocate_a_ptr_list_with_a_node_destructor)
{
    ptr_list_t *list = ptr_list_create((node_dtor_t)&custom_int_destructor);

    cr_assert_not_null(list);
    cr_assert_eq(list_destructor(list), &custom_int_destructor);
}

TestList(ptr_list_push_front, insert_at_begin_of_list)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_front(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_front(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_front(list, &value3), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value3);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value2);
    cr_assert_eq(NODE_PTR(list_get(list, 2), int), &value1);
    cr_assert_eq(NODE_DATA(list_get(list, 0), int), value3);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), value2);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), value1);
}

TestList(ptr_list_push_front, do_not_insert_for_null_pointer)
{
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_front(list, NULL), LIST_ERROR);
    cr_assert(list_empty(list));
}

TestList(ptr_list_push_back, insert_at_end_of_list)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value2);
    cr_assert_eq(NODE_PTR(list_get(list, 2), int), &value3);
    cr_assert_eq(NODE_DATA(list_get(list, 0), int), value1);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), value2);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), value3);
}

TestList(ptr_list_push_back, do_not_insert_for_null_pointer)
{
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, NULL), LIST_ERROR);
    cr_assert(list_empty(list));
}

TestList(ptr_list_insert, insert_at_begin_of_list)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_insert(list, 0, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, 0, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, 0, &value3), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value3);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value2);
    cr_assert_eq(NODE_PTR(list_get(list, 2), int), &value1);
    cr_assert_eq(NODE_DATA(list_get(list, 0), int), value3);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), value2);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), value1);
}

TestList(ptr_list_insert, insert_at_end_of_list)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_insert(list, -1, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, -1, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, -1, &value3), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value2);
    cr_assert_eq(NODE_PTR(list_get(list, 2), int), &value3);
    cr_assert_eq(NODE_DATA(list_get(list, 0), int), value1);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), value2);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), value3);
}

TestList(ptr_list_insert, insert_at_index)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    int value4 = 42;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, 1, &value4), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 4);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value4);
    cr_assert_eq(NODE_PTR(list_get(list, 2), int), &value2);
    cr_assert_eq(NODE_PTR(list_get(list, 3), int), &value3);
    cr_assert_eq(NODE_DATA(list_get(list, 0), int), value1);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), value4);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), value2);
    cr_assert_eq(NODE_DATA(list_get(list, 3), int), value3);
}

TestList(ptr_list_get, get_a_node_in_a_list)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    cr_assert_eq(list_get(list, 0), list_begin(list));
    cr_assert_eq(NODE_DATA(list_get(list, 0), int), value1);
    cr_assert_eq(list_get(list, 1), list_begin(list)->next);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), value2);
    cr_assert_eq(list_get(list, 2), list_begin(list)->next->next);
    cr_assert_eq(list_get(list, 2), list_end(list));
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), value3);
    cr_assert_null(list_get(list, 3));
}

TestList(ptr_list_pop_front, delete_first_data)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    list_pop_front(list);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value2);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value3);
}

TestList(ptr_list_pop_front, do_nothing_the_list_empty)
{
    ptr_list_t *list = ptr_list_create(NULL);

    list_pop_front(list);
    cr_assert(list_empty(list));
}

TestList(ptr_list_pop_back, delete_last_data)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    list_pop_back(list);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value2);
}

TestList(ptr_list_pop_back, do_nothing_the_list_empty)
{
    ptr_list_t *list = ptr_list_create(NULL);

    list_pop_back(list);
    cr_assert(list_empty(list));
}

TestList(ptr_list_pop, delete_first_data)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    list_pop(list, 0);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value2);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value3);
}

TestList(ptr_list_pop, delete_last_data)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    list_pop(list, -1);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value2);
}

TestList(ptr_list_pop, delete_middle_data)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    list_pop(list, 1);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value3);
}

TestList(ptr_list_pop, delete_middle_data_with_negative_index)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    list_pop(list, -2);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value3);
}

TestList(ptr_list_pop, out_of_bound_error)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_insert(list, -1, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, -1, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, -1, &value3), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    list_pop(list, -35);
    list_pop(list, 123);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value2);
    cr_assert_eq(NODE_PTR(list_get(list, 2), int), &value3);
}

TestList(ptr_list_pop, do_nothing_the_list_empty)
{
    ptr_list_t *list = ptr_list_create(NULL);

    list_pop(list, 123);
    list_pop(list, -25);
    cr_assert(list_empty(list));
}

TestList(ptr_list_clear, delete_all_nodes)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_insert(list, -1, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, -1, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, -1, &value3), LIST_SUCCESS);
    list_clear(list);
    cr_assert(list_empty(list));
}

TestList(ptr_list_clear, use_destructor_to_free_the_pointers,
        .init = cr_redirect_stdout)
{
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    int *value3 = malloc(sizeof(int));
    ptr_list_t *list = ptr_list_create((node_dtor_t)&custom_int_destructor);

    *value1 = 5;
    *value2 = 27;
    *value3 = -4;
    cr_assert_eq(ptr_list_insert(list, -1, value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, -1, value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, -1, value3), LIST_SUCCESS);
    list_clear(list);
    cr_assert(list_empty(list));
    cr_assert_stdout_eq_str("Destroying an int pointer containing 5\n"
                            "Destroying an int pointer containing 27\n"
                            "Destroying an int pointer containing -4\n");
}

TestList(ptr_list_destroy, destroy_a_linked_list)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_insert(list, -1, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, -1, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, -1, &value3), LIST_SUCCESS);
    ptr_list_destroy(list);
}

TestList(ptr_list_destroy, use_destructor_to_free_the_pointers,
        .init = cr_redirect_stdout)
{
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    int *value3 = malloc(sizeof(int));
    ptr_list_t *list = ptr_list_create((node_dtor_t)&custom_int_destructor);

    *value1 = 5;
    *value2 = 27;
    *value3 = -4;
    cr_assert_eq(ptr_list_insert(list, -1, value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, -1, value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_insert(list, -1, value3), LIST_SUCCESS);
    ptr_list_destroy(list);
    cr_assert_stdout_eq_str("Destroying an int pointer containing 5\n"
                            "Destroying an int pointer containing 27\n"
                            "Destroying an int pointer containing -4\n");
}

TestList(ptr_list_dup, duplicate_a_linked_list)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);
    ptr_list_t *list2 = NULL;

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    list2 = list_dup(list);
    cr_assert_not_null(list2);
    cr_assert_eq(list_len(list), list_len(list2));
    cr_assert_eq(NODE_PTR(list_get(list2, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list2, 1), int), &value2);
    cr_assert_eq(NODE_PTR(list_get(list2, 2), int), &value3);
}

TestList(ptr_list_dup, duplicate_an_empty_list)
{
    ptr_list_t *list = ptr_list_create(NULL);
    ptr_list_t *list2 = list_dup(list);

    cr_assert_not_null(list2);
    cr_assert(list_empty(list2));
}

TestList(ptr_list_merge, merge_two_linked_lists)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    int value4 = 42;
    ptr_list_t *list = ptr_list_create(NULL);
    ptr_list_t *list2 = ptr_list_create(list_destructor(list));

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list2, &value3), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list2, &value4), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(list_len(list2), 2);
    list_merge(list, list2);
    cr_assert_eq(list_len(list), 4);
    cr_assert_eq(list_len(list2), 0);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value2);
    cr_assert_eq(NODE_PTR(list_get(list, 2), int), &value3);
    cr_assert_eq(NODE_PTR(list_get(list, 3), int), &value4);
}

TestList(ptr_list_merge, swap_with_list2_if_list1_is_empty)
{
    int value1 = 5;
    int value2 = 27;
    ptr_list_t *list = ptr_list_create(NULL);
    ptr_list_t *list2 = ptr_list_create(list_destructor(list));

    cr_assert_eq(ptr_list_push_back(list2, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list2, &value2), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 0);
    cr_assert_eq(list_len(list2), 2);
    list_merge(list, list2);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(list_len(list2), 0);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value2);
}

TestList(ptr_list_merge, do_nothing_if_list2_is_empty)
{
    int value1 = 5;
    int value2 = 27;
    ptr_list_t *list = ptr_list_create(NULL);
    ptr_list_t *list2 = ptr_list_create(list_destructor(list));

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(list_len(list2), 0);
    list_merge(list, list2);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(list_len(list2), 0);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value2);
}

TestList(ptr_list_merge, do_nothing_if_list2_is_null)
{
    int value1 = 5;
    int value2 = 27;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    list_merge(list, NULL);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value2);
}

TestList(ptr_list_reverse, reverse_a_linked_list)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    list_reverse(list);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value3);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value2);
    cr_assert_eq(NODE_PTR(list_get(list, 2), int), &value1);
}

TestList(ptr_list_reverse, do_nothing_if_there_is_a_single_element)
{
    int value1 = 5;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    list_reverse(list);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
}

TestList(ptr_list_reverse, do_nothing_if_the_list_is_empty)
{
    ptr_list_t *list = ptr_list_create(NULL);

    list_reverse(list);
}

TestList(ptr_list_rotate_begin, put_the_first_node_at_end)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    list_rotate_begin(list);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value2);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value3);
    cr_assert_eq(NODE_PTR(list_get(list, 2), int), &value1);
}

TestList(ptr_list_rotate_begin, do_nothing_if_there_is_a_single_element)
{
    int value1 = 5;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    list_rotate_begin(list);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
}

TestList(ptr_list_rotate_begin, do_nothing_if_the_list_is_empty)
{
    ptr_list_t *list = ptr_list_create(NULL);

    list_rotate_begin(list);
}

TestList(ptr_list_rotate_end, put_the_last_node_at_start)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    list_rotate_end(list);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value3);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 2), int), &value2);
}

TestList(ptr_list_rotate_end, do_nothing_if_there_is_a_single_element)
{
    int value1 = 5;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    list_rotate_end(list);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
}

TestList(ptr_list_rotate_end, do_nothing_if_the_list_is_empty)
{
    ptr_list_t *list = ptr_list_create(NULL);

    list_rotate_end(list);
}

TestList(ptr_list_find, find_a_pointer_in_the_list)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);
    const node_t *node = NULL;

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    node = ptr_list_find(list, &value2);
    cr_assert_not_null(node);
    cr_assert_eq(NODE_PTR(node, int), &value2);
}

TestList(ptr_list_find, returns_null_if_data_was_not_found)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    int value4 = 42;
    ptr_list_t *list = ptr_list_create(NULL);
    const node_t *node = NULL;

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    node = ptr_list_find(list, &value4);
    cr_assert_null(node);
}

TestList(ptr_list_find, returns_null_if_data_is_null)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);
    const node_t *node = NULL;

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    node = ptr_list_find(list, NULL);
    cr_assert_null(node);
}

static int int_comparator(const int *first, const int *second)
{
    return *first - *second;
}

TestList(ptr_list_find_cmp, finds_a_pointer_by_comparing_their_data)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    int value4 = 27;
    ptr_list_t *list = ptr_list_create(NULL);
    const node_t *node = NULL;

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    node = ptr_list_find_cmp(list, &value2, &int_comparator);
    cr_assert_not_null(node);
    cr_assert_eq(NODE_PTR(node, int), &value2);
    node = ptr_list_find_cmp(list, &value4, &int_comparator);
    cr_assert_not_null(node);
    cr_assert_eq(NODE_PTR(node, int), &value2);
}

TestList(ptr_list_find_cmp, returns_null_if_data_was_not_found)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    int value4 = 42;
    ptr_list_t *list = ptr_list_create(NULL);
    const node_t *node = NULL;

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    node = ptr_list_find_cmp(list, &value4, &int_comparator);
    cr_assert_null(node);
}

TestList(ptr_list_find_cmp, returns_null_if_data_is_null)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);
    const node_t *node = NULL;

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    node = ptr_list_find_cmp(list, NULL, &int_comparator);
    cr_assert_null(node);
}

TestList(ptr_list_find_cmp, returns_null_if_comparator_is_null)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);
    const node_t *node = NULL;

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    node = ptr_list_find_cmp(list, &value3, NULL);
    cr_assert_null(node);
}

TestList(ptr_list_contains, check_if_a_pointer_is_in_list)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    int value4 = 42;
    ptr_list_t *list = ptr_list_create(NULL);

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    cr_assert(ptr_list_contains(list, &value1));
    cr_assert(ptr_list_contains(list, &value2));
    cr_assert(ptr_list_contains(list, &value3));
    cr_assert_not(ptr_list_contains(list, &value4));
    cr_assert_not(ptr_list_contains(list, NULL));
}

TestList(ptr_list_remove, remove_a_specific_pointer)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = make_ptr_list(NULL, &value1, &value2, &value3);

    cr_assert_not_null(list);
    cr_assert_eq(ptr_list_remove(list, &value2), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value3);
}

TestList(ptr_list_remove, returns_error_for_unknown_pointer)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    int value4 = 27;
    ptr_list_t *list = make_ptr_list(NULL, &value1, &value2, &value3);

    cr_assert_not_null(list);
    cr_assert_eq(ptr_list_remove(list, &value4), LIST_ERROR);
    cr_assert_eq(list_len(list), 3);
}

TestList(ptr_list_remove, do_nothing_with_null_pointer)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = make_ptr_list(NULL, &value1, &value2, &value3);

    cr_assert_not_null(list);
    cr_assert_eq(ptr_list_remove(list, NULL), LIST_ERROR);
    cr_assert_eq(list_len(list), 3);
}

TestList(ptr_list_remove_cmp, remove_a_specific_pointer)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    int value4 = 27;
    ptr_list_t *list = make_ptr_list(NULL, &value1, &value2, &value3);

    cr_assert_not_null(list);
    cr_assert_eq(ptr_list_remove_cmp(list, &value4, &int_comparator), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value3);
}

TestList(ptr_list_remove_cmp, do_nothing_with_null_comparator)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = make_ptr_list(NULL, &value1, &value2, &value3);

    cr_assert_not_null(list);
    cr_assert_eq(ptr_list_remove_cmp(list, &value2, NULL), LIST_ERROR);
    cr_assert_eq(list_len(list), 3);
}

TestList(ptr_list_to_array, make_an_allocated_array_from_a_list)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);
    int **array = NULL;

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    array = ptr_list_to_array(list, NULL);
    cr_assert_not_null(array);
    cr_assert_eq(array[0], &value1);
    cr_assert_eq(array[1], &value2);
    cr_assert_eq(array[2], &value3);
    cr_assert_null(array[3]);
}

TestList(ptr_list_to_array, make_an_allocated_array_from_a_list_with_list)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = ptr_list_create(NULL);
    int **array = NULL;
    size_t array_size;

    cr_assert_eq(ptr_list_push_back(list, &value1), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value2), LIST_SUCCESS);
    cr_assert_eq(ptr_list_push_back(list, &value3), LIST_SUCCESS);
    array = ptr_list_to_array(list, &array_size);
    cr_assert_not_null(array);
    cr_assert_eq(array_size, list_len(list));
    cr_assert_eq(array[0], &value1);
    cr_assert_eq(array[1], &value2);
    cr_assert_eq(array[2], &value3);
    cr_assert_null(array[array_size]);
}

TestList(ptr_list_to_array, create_empty_array_if_list_is_empty)
{
    ptr_list_t *list = ptr_list_create(NULL);
    size_t array_size;
    int **array = ptr_list_to_array(list, &array_size);

    cr_assert_not_null(array);
    cr_assert_eq(array_size, 0);
    cr_assert_null(array[array_size]);
}

TestList(ptr_list_to_array, returns_null_if_list_is_null)
{
    size_t array_size;
    int **array = ptr_list_to_array(NULL, &array_size);

    cr_assert_null(array);
    cr_assert_eq(array_size, 0);
}

TestList(array_to_ptr_list, make_a_list_from_an_array)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    int *array[] = {&value1, &value2, &value3, NULL};
    ptr_list_t *list = array_to_ptr_list(array, NULL);
    size_t index = 0;

    cr_assert_not_null(list);
    cr_assert_eq(list_len(list), 3);
    list_foreach(node, list) {
        cr_assert_eq(NODE_PTR(node, int), array[index++]);
    }
}

TestList(array_to_ptr_list, do_nothing_for_null_array)
{
    ptr_list_t *list = array_to_ptr_list(NULL, NULL);

    cr_assert_null(list);
}

TestList(make_ptr_list, create_a_list_with_default_values)
{
    int value1 = 5;
    int value2 = 27;
    int value3 = -4;
    ptr_list_t *list = make_ptr_list(NULL, &value1, &value2, &value3);

    cr_assert_not_null(list);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_PTR(list_get(list, 0), int), &value1);
    cr_assert_eq(NODE_PTR(list_get(list, 1), int), &value2);
    cr_assert_eq(NODE_PTR(list_get(list, 2), int), &value3);
}
