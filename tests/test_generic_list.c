/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** test_generic_list
*/

#include <stdlib.h>
#include <time.h>
#include "test_generic_list.h"

static void test_methods(const list_t *list)
{
    cr_assert_not_null(list->insert);
    cr_assert_not_null(list->push_front);
    cr_assert_not_null(list->push_back);
    cr_assert_not_null(list->emplace);
    cr_assert_not_null(list->emplace_front);
    cr_assert_not_null(list->emplace_back);
    cr_assert_not_null(list->pop);
    cr_assert_not_null(list->pop_front);
    cr_assert_not_null(list->pop_back);
    cr_assert_not_null(list->remove);
    cr_assert_not_null(list->remove_cmp);
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
    cr_assert_not_null(list->find);
    cr_assert_not_null(list->find_cmp);
    cr_assert_not_null(list->contains);
}

static void custom_int_destructor(int *value)
{
    printf("Destroying a node containing %d\n", *value);
    fflush(stdout);
    free(value);
}

TestList(generic_list_create, allocate_a_generic_list)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_not_null(list);
    test_methods(list);
    cr_assert(list_empty(list));
    cr_assert_null(list_begin(list));
    cr_assert_null(list_end(list));
}

TestList(generic_list_create, allocate_a_generic_list_with_a_node_destructor)
{
    list_t *list = generic_list_create((node_dtor_t)&custom_int_destructor);

    cr_assert_not_null(list);
    cr_assert_eq(list_destructor(list), &custom_int_destructor);
}

TestList(generic_list_push_front, insert_at_begin_of_list)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list_len(list), 0);
    cr_assert_eq(generic_list_push_front(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 1);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 5);
    cr_assert_eq(generic_list_push_front(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 27);
    cr_assert_eq(generic_list_push_front(list, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_DATA(list_begin(list), int), -4);
}

TestList(generic_list_push_front, do_not_insert_for_null_data)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list->push_front(list, NULL, sizeof(int)), LIST_ERROR);
    cr_assert(list_empty(list));
}

TestList(generic_list_push_front, do_not_insert_for_null_size)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list->push_front(list, _FMT_DATA(5, int), 0), LIST_ERROR);
    cr_assert(list_empty(list));
}

TestList(generic_list_push_back, insert_at_end_of_list)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list_len(list), 0);
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 1);
    cr_assert_eq(NODE_DATA(list_end(list), int), 5);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_end(list), int), 27);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_DATA(list_end(list), int), -4);
}

TestList(generic_list_push_back, do_not_insert_for_null_data)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list->push_back(list, NULL, sizeof(int)), LIST_ERROR);
    cr_assert(list_empty(list));
}

TestList(generic_list_push_back, do_not_insert_for_null_size)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list->push_back(list, _FMT_DATA(5, int), 0), LIST_ERROR);
    cr_assert(list_empty(list));
}

TestList(generic_list_insert, insert_at_begin_of_list)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list_len(list), 0);
    cr_assert_eq(generic_list_insert(list, 0, 5, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 1);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 5);
    cr_assert_eq(generic_list_insert(list, 0, 27, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 27);
    cr_assert_eq(generic_list_insert(list, 0, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_DATA(list_begin(list), int), -4);
}

TestList(generic_list_insert, insert_at_begin_of_list_with_negative_index)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list_len(list), 0);
    cr_assert_eq(generic_list_insert(list, -1, 5, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 1);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 5);
    cr_assert_eq(generic_list_insert(list, -2, 27, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 27);
    cr_assert_eq(generic_list_insert(list, -256, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_DATA(list_begin(list), int), -4);
}

TestList(generic_list_insert, insert_at_end_of_list)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list_len(list), 0);
    cr_assert_eq(generic_list_insert(list, -1, 5, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 1);
    cr_assert_eq(NODE_DATA(list_end(list), int), 5);
    cr_assert_eq(generic_list_insert(list, -1, 27, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_end(list), int), 27);
    cr_assert_eq(generic_list_insert(list, -1, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_DATA(list_end(list), int), -4);
}

TestList(generic_list_insert, insert_at_end_of_list_with_negative_index)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list_len(list), 0);
    cr_assert_eq(generic_list_insert(list, 1, 5, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 1);
    cr_assert_eq(NODE_DATA(list_end(list), int), 5);
    cr_assert_eq(generic_list_insert(list, 2, 27, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_end(list), int), 27);
    cr_assert_eq(generic_list_insert(list, 456, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_DATA(list_end(list), int), -4);
}

TestList(generic_list_insert, insert_in_middle_of_a_list)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list_len(list), 0);
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 27);
    cr_assert_eq(generic_list_insert(list, 1, 987, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 4);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 987);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), 27);
}

TestList(generic_list_insert, insert_in_middle_of_a_list_with_negative_index)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list_len(list), 0);
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_DATA(list_get(list, -1), int), -4);
    cr_assert_eq(generic_list_insert(list, -2, 987, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 4);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), 987);
    cr_assert_eq(NODE_DATA(list_get(list, 3), int), -4);
}

TestList(generic_list_insert, do_not_insert_for_null_data)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list->insert(list, 0, NULL, sizeof(int)), LIST_ERROR);
    cr_assert(list_empty(list));
}

TestList(generic_list_insert, do_not_insert_for_null_size)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_eq(list->insert(list, 0, _FMT_DATA(5, int), 0), LIST_ERROR);
    cr_assert(list_empty(list));
}

TestList(generic_list_emplace_front, creates_empty_storage_in_the_list)
{
    list_t *list = generic_list_create(NULL);
    int *data = NULL;

    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    data = generic_list_emplace_front(list, int);
    cr_assert_eq(list_len(list), 4);
    cr_assert_not_null(data);
    cr_assert_eq(*data, 0);
    *data = 42;
    cr_assert_eq(NODE_DATA(list_begin(list), int), 42);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), 27);
    cr_assert_eq(NODE_DATA(list_get(list, 3), int), -4);
}

TestList(generic_list_emplace_front, do_not_insert_for_null_size)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list->emplace_front(list, 0));
    cr_assert(list_empty(list));
}

TestList(generic_list_emplace_back, creates_empty_storage_in_the_list)
{
    list_t *list = generic_list_create(NULL);
    int *data = NULL;

    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    data = generic_list_emplace_back(list, int);
    cr_assert_eq(list_len(list), 4);
    cr_assert_not_null(data);
    cr_assert_eq(*data, 0);
    *data = 42;
    cr_assert_eq(NODE_DATA(list_get(list, 0), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 27);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), -4);
    cr_assert_eq(NODE_DATA(list_end(list), int), 42);
}

TestList(generic_list_emplace_back, do_not_insert_for_null_size)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list->emplace_back(list, 0));
    cr_assert(list_empty(list));
}

TestList(generic_list_emplace, creates_empty_storage_at_start)
{
    list_t *list = generic_list_create(NULL);
    int *data = NULL;

    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    data = generic_list_emplace(list, 0, int);
    cr_assert_eq(list_len(list), 4);
    cr_assert_not_null(data);
    cr_assert_eq(*data, 0);
    *data = 42;
    cr_assert_eq(NODE_DATA(list_begin(list), int), 42);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), 27);
    cr_assert_eq(NODE_DATA(list_get(list, 3), int), -4);
}

TestList(generic_list_emplace, creates_empty_storage_at_end)
{
    list_t *list = generic_list_create(NULL);
    int *data = NULL;

    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    data = generic_list_emplace(list, -1, int);
    cr_assert_eq(list_len(list), 4);
    cr_assert_not_null(data);
    cr_assert_eq(*data, 0);
    *data = 42;
    cr_assert_eq(NODE_DATA(list_get(list, 0), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 27);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), -4);
    cr_assert_eq(NODE_DATA(list_end(list), int), 42);
}

TestList(generic_list_emplace, creates_empty_storage_at_index)
{
    list_t *list = generic_list_create(NULL);
    int *data = NULL;

    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    data = generic_list_emplace(list, 1, int);
    cr_assert_eq(list_len(list), 4);
    cr_assert_not_null(data);
    cr_assert_eq(*data, 0);
    *data = 42;
    cr_assert_eq(NODE_DATA(list_get(list, 0), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 42);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), 27);
    cr_assert_eq(NODE_DATA(list_get(list, 3), int), -4);
}

TestList(generic_list_emplace, creates_empty_storage_at_negative_index)
{
    list_t *list = generic_list_create(NULL);
    int *data = NULL;

    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 3);
    data = generic_list_emplace(list, -2, int);
    cr_assert_eq(list_len(list), 4);
    cr_assert_not_null(data);
    cr_assert_eq(*data, 0);
    *data = 42;
    cr_assert_eq(NODE_DATA(list_get(list, 0), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 27);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), 42);
    cr_assert_eq(NODE_DATA(list_get(list, 3), int), -4);
}

TestList(generic_list_emplace, do_not_insert_for_null_size)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list->emplace(list, 0, 0));
    cr_assert(list_empty(list));
}

TestList(generic_list_get, get_a_node_in_a_list)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_get(list, 0), list_begin(list));
    cr_assert_eq(NODE_DATA(list_get(list, 0), int), 5);
    cr_assert_eq(list_get(list, 1), list_begin(list)->next);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 27);
    cr_assert_eq(list_get(list, 2), list_begin(list)->next->next);
    cr_assert_eq(list_get(list, 2), list_end(list));
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), -4);
    cr_assert_null(list_get(list, 3));
}

TestList(generic_list_get, get_a_node_in_a_list_with_negative_index)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_get(list, -1), list_end(list));
    cr_assert_eq(NODE_DATA(list_get(list, -1), int), -4);
    cr_assert_not_null(list_get(list, -2));
    cr_assert_eq(NODE_DATA(list_get(list, -2), int), 27);
    cr_assert_eq(list_get(list, -3), list_begin(list));
    cr_assert_eq(NODE_DATA(list_get(list, -3), int), 5);
    cr_assert_null(list_get(list, -4));
}

TestList(generic_list_pop_front, delete_the_first_data)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop_front(list);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 27);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), -4);
    cr_assert_null(list_get(list, 2));
}

TestList(generic_list_pop_front, delete_the_first_data_custom_destructor,
        .init = cr_redirect_stdout)
{
    list_t *list = generic_list_create((node_dtor_t)&custom_int_destructor);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop_front(list);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 27);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), -4);
    cr_assert_null(list_get(list, 2));
    cr_assert_stdout_eq_str("Destroying a node containing 5\n");
}

TestList(generic_list_pop_front, do_nothing_the_list_empty)
{
    list_t *list = generic_list_create(NULL);

    list_pop_front(list);
}

TestList(generic_list_pop_back, delete_the_last_data)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop_back(list);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 27);
    cr_assert_null(list_get(list, 2));
}

TestList(generic_list_pop_back, delete_the_last_data_custom_destructor,
        .init = cr_redirect_stdout)
{
    list_t *list = generic_list_create((node_dtor_t)&custom_int_destructor);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop_back(list);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 27);
    cr_assert_null(list_get(list, 2));
    cr_assert_stdout_eq_str("Destroying a node containing -4\n");
}

TestList(generic_list_pop_back, do_nothing_the_list_empty)
{
    list_t *list = generic_list_create(NULL);

    list_pop_back(list);
}

TestList(generic_list_pop, delete_the_first_data)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop(list, 0);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 27);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), -4);
    cr_assert_null(list_get(list, 2));
}

TestList(generic_list_pop, delete_the_first_data_using_a_custom_destructor,
        .init = cr_redirect_stdout)
{
    list_t *list = generic_list_create((node_dtor_t)&custom_int_destructor);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop(list, 0);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 27);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), -4);
    cr_assert_null(list_get(list, 2));
    cr_assert_stdout_eq_str("Destroying a node containing 5\n");
}

TestList(generic_list_pop, delete_the_first_data_with_negative_index)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop(list, -3);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 27);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), -4);
    cr_assert_null(list_get(list, 2));
}

TestList(generic_list_pop, delete_the_last_data)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop(list, 2);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 27);
    cr_assert_null(list_get(list, 2));
}

TestList(generic_list_pop, delete_the_last_data_using_a_custom_destructor,
        .init = cr_redirect_stdout)
{
    list_t *list = generic_list_create((node_dtor_t)&custom_int_destructor);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop(list, 2);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 27);
    cr_assert_null(list_get(list, 2));
    cr_assert_stdout_eq_str("Destroying a node containing -4\n");
}

TestList(generic_list_pop, delete_the_last_data_with_negative_index)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop(list, -1);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 27);
    cr_assert_null(list_get(list, 2));
}

TestList(generic_list_pop, delete_data)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop(list, 1);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), -4);
    cr_assert_null(list_get(list, 2));
}

TestList(generic_list_pop, delete_data_using_a_custom_destructor,
        .init = cr_redirect_stdout)
{
    list_t *list = generic_list_create((node_dtor_t)&custom_int_destructor);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop(list, 1);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), -4);
    cr_assert_null(list_get(list, 2));
    cr_assert_stdout_eq_str("Destroying a node containing 27\n");
}

TestList(generic_list_pop, delete_data_with_negative_index)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop(list, -2);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), -4);
    cr_assert_null(list_get(list, 2));
}

TestList(generic_list_pop, out_of_bound_error)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_pop(list, -35);
    list_pop(list, 123);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_DATA(list_get(list, 0), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 27);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), -4);
}

TestList(generic_list_pop, do_nothing_the_list_empty)
{
    list_t *list = generic_list_create(NULL);

    list_pop(list, 123);
    list_pop(list, -25);
    cr_assert(list_empty(list));
}

TestList(generic_list_clear, erase_all_nodes)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_clear(list);
    cr_assert_eq(list_len(list), 0);
    cr_assert_null(list_begin(list));
    cr_assert_null(list_end(list));
}

TestList(generic_list_clear, erase_all_nodes_using_a_custom_destructor,
        .init = cr_redirect_stdout)
{
    list_t *list = generic_list_create((node_dtor_t)&custom_int_destructor);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    list_clear(list);
    cr_assert_eq(list_len(list), 0);
    cr_assert_null(list_begin(list));
    cr_assert_null(list_end(list));
    cr_assert_stdout_eq_str("Destroying a node containing 5\n"
                            "Destroying a node containing 27\n"
                            "Destroying a node containing -4\n");
}

TestList(generic_list_destroy, destroy_a_linked_list)
{
    list_t *list = generic_list_create(NULL);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    generic_list_destroy(list);
}

TestList(generic_list_destroy, destroy_a_linked_list_using_a_destructor,
        .init = cr_redirect_stdout)
{
    list_t *list = generic_list_create((node_dtor_t)&custom_int_destructor);

    cr_assert_null(list_get(list, 0));
    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    generic_list_destroy(list);
    cr_assert_stdout_eq_str("Destroying a node containing 5\n"
                            "Destroying a node containing 27\n"
                            "Destroying a node containing -4\n");
}

TestList(generic_list_destroy, do_nothing_if_null_is_given)
{
    generic_list_destroy(NULL);
}

TestList(generic_list_duplicate, duplicate_a_linked_list)
{
    list_t *list1 = generic_list_create(NULL);
    list_t *list2 = NULL;
    const size_t size = 10;

    srand(time(NULL));
    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list1, rand(), int);
    cr_assert_eq(list_len(list1), size);
    list2 = list_dup(list1);
    cr_assert_not_null(list2);
    cr_assert_eq(list_len(list2), list_len(list1));
    for (size_t i = 0; i < size; ++i) {
        const node_t *n1 = list_get(list1, i);
        const node_t *n2 = list_get(list2, i);
        cr_assert_eq(NODE_DATA(n2, int), NODE_DATA(n1, int));
    }
}

TestList(generic_list_duplicate, duplicate_an_empty_list)
{
    list_t *list1 = generic_list_create(NULL);
    list_t *list2 = NULL;

    cr_assert_eq(list_len(list1), 0);
    list2 = list_dup(list1);
    cr_assert_not_null(list2);
    cr_assert_eq(list_len(list2), list_len(list1));
}

TestList(generic_list_duplicate, should_not_have_destructor)
{
    list_t *list1 = generic_list_create((node_dtor_t)&custom_int_destructor);
    list_t *list2 = list_dup(list1);

    cr_assert_null(list_destructor(list2));
}

TestList(generic_list_merge, merge_two_linked_lists)
{
    list_t *list1 = generic_list_create(NULL);
    list_t *list2 = generic_list_create(list_destructor(list1));
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list1, i, size_t);
    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list2, size + i, size_t);
    cr_assert_eq(list_len(list1), size);
    cr_assert_eq(list_len(list2), size);
    list_merge(list1, list2);
    cr_assert_not_null(list2);
    cr_assert_eq(list_len(list1), size * 2);
    cr_assert_eq(list_len(list2), 0);
    for (size_t i = 0; i < size * 2; ++i) {
        cr_assert_eq(NODE_DATA(list_get(list1, i), int), i);
    }
}

TestList(generic_list_merge, swap_empty_linked_list_with_a_non_empty)
{
    list_t *list1 = generic_list_create(NULL);
    list_t *list2 = generic_list_create(list_destructor(list1));
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list2, i, size_t);
    cr_assert_eq(list_len(list1), 0);
    cr_assert_eq(list_len(list2), size);
    list_merge(list1, list2);
    cr_assert_not_null(list2);
    cr_assert_eq(list_len(list1), size);
    cr_assert_eq(list_len(list2), 0);
    for (size_t i = 0; i < size; ++i) {
        cr_assert_eq(NODE_DATA(list_get(list1, i), int), i);
    }
}

TestList(generic_list_merge, do_nothing_with_empty_list_to_merge)
{
    list_t *list1 = generic_list_create(NULL);
    list_t *list2 = generic_list_create(list_destructor(list1));
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list1, i, size_t);
    cr_assert_eq(list_len(list1), size);
    cr_assert_eq(list_len(list2), 0);
    list_merge(list1, list2);
    cr_assert_not_null(list2);
    cr_assert_eq(list_len(list1), size);
    cr_assert_eq(list_len(list2), 0);
    for (size_t i = 0; i < size; ++i) {
        cr_assert_eq(NODE_DATA(list_get(list1, i), int), i);
    }
}

TestList(generic_list_merge, do_nothing_with_null_list_to_merge)
{
    list_t *list1 = generic_list_create(NULL);
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list1, i, size_t);
    cr_assert_eq(list_len(list1), size);
    list_merge(list1, NULL);
    cr_assert_eq(list_len(list1), size);
    for (size_t i = 0; i < size; ++i) {
        cr_assert_eq(NODE_DATA(list_get(list1, i), int), i);
    }
}

TestList(generic_list_reverse, reverse_a_list)
{
    list_t *list = generic_list_create(NULL);
    const long size = 10;

    for (long i = 0; i < size; ++i)
        generic_list_push_back(list, i, long);
    list_reverse(list);
    for (long i = size - 1; i >= 0; --i) {
        const node_t *node = list_get(list, (list_len(list) - 1) - i);
        cr_assert_eq(NODE_DATA(node, long), i);
    }
    cr_assert_eq(NODE_DATA(list_begin(list), long), size - 1);
    cr_assert_eq(NODE_DATA(list_end(list), long), 0);
}

TestList(generic_list_reverse, do_nothing_with_an_empty_list)
{
    list_t *list = generic_list_create(NULL);

    cr_assert(list_empty(list));
    list_reverse(list);
    cr_assert(list_empty(list));
}

TestList(generic_list_reverse, do_nothing_with_a_single_element_in_list)
{
    list_t *list = generic_list_create(NULL);

    cr_assert(generic_list_push_back(list, 5, int));
    list_reverse(list);
    cr_assert_eq(list_len(list), 1);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 5);
}

TestList(generic_list_rotate_begin, put_the_first_node_at_end)
{
    list_t *list = generic_list_create(NULL);
    const node_t *head = NULL;

    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    head = list_begin(list);
    list_rotate_begin(list);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(list_end(list), head);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 27);
}

TestList(generic_list_rotate_begin, do_nothing_for_an_empty_list)
{
    list_t *list = generic_list_create(NULL);

    cr_assert(list_empty(list));
    list_rotate_begin(list);
    cr_assert(list_empty(list));
}

TestList(generic_list_rotate_begin, do_nothing_for_a_single_node)
{
    list_t *list = generic_list_create(NULL);
    const node_t *head = NULL;

    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    head = list_begin(list);
    list_rotate_begin(list);
    cr_assert_eq(list_len(list), 1);
    cr_assert_eq(list_end(list), head);
    cr_assert_eq(list_begin(list), head);
    cr_assert_eq(NODE_DATA(list_begin(list), int), 5);
}

TestList(generic_list_rotate_end, put_the_last_node_at_end)
{
    list_t *list = generic_list_create(NULL);
    const node_t *tail = NULL;

    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    tail = list_end(list);
    list_rotate_end(list);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(list_begin(list), tail);
    cr_assert_eq(NODE_DATA(list_end(list), int), 27);
}

TestList(generic_list_rotate_end, do_nothing_for_an_empty_list)
{
    list_t *list = generic_list_create(NULL);

    cr_assert(list_empty(list));
    list_rotate_end(list);
    cr_assert(list_empty(list));
}

TestList(generic_list_rotate_end, do_nothing_for_a_single_node)
{
    list_t *list = generic_list_create(NULL);
    const node_t *tail = NULL;

    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    tail = list_end(list);
    list_rotate_end(list);
    cr_assert_eq(list_len(list), 1);
    cr_assert_eq(list_begin(list), tail);
    cr_assert_eq(list_end(list), tail);
    cr_assert_eq(NODE_DATA(list_end(list), int), 5);
}

TestList(generic_list_find, find_a_data_in_a_linked_list)
{
    list_t *list = generic_list_create(NULL);
    const node_t *result;
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list, i, size_t);
    cr_assert_eq(list_len(list), size);
    result = generic_list_find(list, 5, size_t);
    cr_assert_not_null(result);
    cr_assert_eq(NODE_DATA(result, size_t), 5);
}

TestList(generic_list_find, returns_null_if_data_was_not_found)
{
    list_t *list = generic_list_create(NULL);
    const node_t *result;
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list, i, size_t);
    cr_assert_eq(list_len(list), size);
    result = generic_list_find(list, 45, size_t);
    cr_assert_null(result);
}

TestList(generic_list_find, returns_null_if_data_have_not_the_same_size)
{
    list_t *list = generic_list_create(NULL);
    const node_t *result;
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list, i, size_t);
    cr_assert_eq(list_len(list), size);
    result = generic_list_find(list, 5, int);
    cr_assert_null(result);
}

TestList(generic_list_find, returns_null_for_null_data)
{
    list_t *list = generic_list_create(NULL);
    const node_t *result;
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list, i, size_t);
    cr_assert_eq(list_len(list), size);
    result = list->find(list, NULL, sizeof(int));
    cr_assert_null(result);
}

TestList(generic_list_find, returns_null_for_null_size)
{
    list_t *list = generic_list_create(NULL);
    const node_t *result;
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list, i, size_t);
    cr_assert_eq(list_len(list), size);
    result = list->find(list, _FMT_DATA(5, int), 0);
    cr_assert_null(result);
}

static int int_comparator(const int *first, const int *second)
{
    return *first - *second;
}

TestList(generic_list_find_cmp, find_a_data_in_a_linked_list_using_a_comparator)
{
    list_t *list = generic_list_create(NULL);
    const node_t *result;
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list, i, int);
    cr_assert_eq(list_len(list), size);
    result = generic_list_find_cmp(list, 5, int, &int_comparator);
    cr_assert_not_null(result);
    cr_assert_eq(NODE_DATA(result, int), 5);
}

TestList(generic_list_find_cmp, returns_null_if_data_was_not_found)
{
    list_t *list = generic_list_create(NULL);
    const node_t *result;
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list, i, int);
    cr_assert_eq(list_len(list), size);
    result = generic_list_find_cmp(list, 45, int, &int_comparator);
    cr_assert_null(result);
}

TestList(generic_list_find_cmp, returns_null_if_comparator_is_null)
{
    list_t *list = generic_list_create(NULL);
    const node_t *result;
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list, i, int);
    cr_assert_eq(list_len(list), size);
    result = generic_list_find_cmp(list, 5, int, NULL);
    cr_assert_null(result);
}

TestList(generic_list_find_cmp, returns_null_for_null_data)
{
    list_t *list = generic_list_create(NULL);
    const node_t *result;
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list, i, int);
    cr_assert_eq(list_len(list), size);
    result = list->find_cmp(list, NULL, (data_cmp_t)&int_comparator);
    cr_assert_null(result);
}

TestList(generic_list_contains, find_a_data_in_a_linked_list)
{
    list_t *list = generic_list_create(NULL);
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list, i, size_t);
    cr_assert_eq(list_len(list), size);
    cr_assert(generic_list_contains(list, 5, size_t));
}

TestList(generic_list_contains, returns_false_if_data_was_not_found)
{
    list_t *list = generic_list_create(NULL);
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list, i, size_t);
    cr_assert_eq(list_len(list), size);
    cr_assert_not(generic_list_contains(list, 45, size_t));
}

TestList(generic_list_contains, returns_false_if_data_have_not_the_same_size)
{
    list_t *list = generic_list_create(NULL);
    const size_t size = 10;

    for (size_t i = 0; i < size; ++i)
        generic_list_push_back(list, i, size_t);
    cr_assert_eq(list_len(list), size);
    cr_assert_not(generic_list_contains(list, 5, int));
}

TestList(generic_list_remove, remove_a_specific_data_in_a_list)
{
    list_t *list = make_generic_list(NULL, int, 5, 27, -4);

    cr_assert_eq(generic_list_remove(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
    cr_assert_eq(generic_list_remove(list, -4, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 1);
    cr_assert_eq(generic_list_remove(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 0);
}

TestList(generic_list_remove, returns_an_error_for_unknown_data)
{
    list_t *list = make_generic_list(NULL, int, 5, 27, -4);

    cr_assert_eq(generic_list_remove(list, 43, int), LIST_ERROR);
    cr_assert_eq(list_len(list), 3);
}

TestList(generic_list_remove_cmp, remove_a_specific_data_in_a_list)
{
    list_t *list = make_generic_list(NULL, int, 5, 27, -4);

    cr_assert_eq(generic_list_remove_cmp(list, 27, int, &int_comparator), LIST_SUCCESS);
    cr_assert_eq(list_len(list), 2);
}

TestList(generic_list_remove_cmp, returns_an_error_for_unknown_data)
{
    list_t *list = make_generic_list(NULL, int, 5, 27, -4);

    cr_assert_eq(generic_list_remove_cmp(list, 43, int, &int_comparator), LIST_ERROR);
    cr_assert_eq(list_len(list), 3);
}

TestList(generic_list_remove_cmp, returns_an_error_for_null_comparator)
{
    list_t *list = make_generic_list(NULL, int, 5, 27, -4);

    cr_assert_eq(generic_list_remove_cmp(list, 43, int, NULL), LIST_ERROR);
    cr_assert_eq(list_len(list), 3);
}

TestList(generic_list_to_array, make_an_allocated_array_from_a_list)
{
    list_t *list = generic_list_create(NULL);
    int *array = NULL;

    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    array = generic_list_to_array(list, NULL);
    cr_assert_not_null(array);
    cr_assert_eq(array[0], 5);
    cr_assert_eq(array[1], 27);
    cr_assert_eq(array[2], -4);
}

TestList(generic_list_to_array, make_an_allocated_array_from_a_list_with_size)
{
    list_t *list = generic_list_create(NULL);
    int *array = NULL;
    size_t array_size = 0;

    cr_assert_eq(generic_list_push_back(list, 5, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, 27, int), LIST_SUCCESS);
    cr_assert_eq(generic_list_push_back(list, -4, int), LIST_SUCCESS);
    array = generic_list_to_array(list, &array_size);
    cr_assert_not_null(array);
    cr_assert_eq(array_size, list_len(list));
    cr_assert_eq(array[0], 5);
    cr_assert_eq(array[1], 27);
    cr_assert_eq(array[2], -4);
}

TestList(generic_list_to_array, returns_null_if_the_list_is_empty)
{
    list_t *list = generic_list_create(NULL);
    int *array = NULL;
    size_t array_size = 0;

    array = generic_list_to_array(list, &array_size);
    cr_assert_null(array);
    cr_assert_eq(array_size, 0);
}

TestList(generic_list_to_array, returns_null_if_the_list_is_null)
{
    int *array = NULL;
    size_t array_size = 0;

    array = generic_list_to_array(NULL, &array_size);
    cr_assert_null(array);
    cr_assert_eq(array_size, 0);
}

TestList(array_to_generic_list, make_a_generic_list_from_an_array)
{
    int array[] = {5, 27, -4};
    const size_t length = sizeof(array) / sizeof(*array);
    list_t *list = array_to_generic_list(array, sizeof(*array), length, NULL);
    size_t index = 0;

    cr_assert_not_null(list);
    cr_assert_eq(list_len(list), length);
    list_foreach(node, list) {
        cr_assert_eq(NODE_DATA(node, int), array[index++]);
    }
}

TestList(array_to_generic_list, do_nothing_for_null_array)
{
    list_t *list = array_to_generic_list(NULL, sizeof(int), 3, NULL);

    cr_assert_null(list);
}

TestList(array_to_generic_list, do_nothing_for_null_member_size)
{
    const int array[] = {5, 27, -4};
    const size_t length = sizeof(array) / sizeof(*array);
    list_t *list = array_to_generic_list(array, 0, length, NULL);

    cr_assert_null(list);
}

TestList(array_to_generic_list, create_empty_list_for_null_nmemb)
{
    int array[] = {5, 27, -4};
    list_t *list = array_to_generic_list(array, sizeof(*array), 0, NULL);

    cr_assert_not_null(list);
    cr_assert(list_empty(list));
}

TestList(make_generic_list, creates_a_list_with_default_values)
{
    list_t *list = make_generic_list(NULL, int, 5, 27, -4);

    cr_assert_not_null(list);
    cr_assert_eq(list_len(list), 3);
    cr_assert_eq(NODE_DATA(list_get(list, 0), int), 5);
    cr_assert_eq(NODE_DATA(list_get(list, 1), int), 27);
    cr_assert_eq(NODE_DATA(list_get(list, 2), int), -4);
}
