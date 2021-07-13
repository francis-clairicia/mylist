/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** test_node
*/

#include <criterion/criterion.h>
#include <mylist/node.h>

Test(create_node, creates_a_new_node_and_copy_the_data)
{
    int data = 27;
    node_t *node = create_node(&data, sizeof(data));

    cr_assert_not_null(node);
    cr_assert_not_null(NODE_PTR(node, int));
    cr_assert_neq(NODE_PTR(node, int), &data);
    cr_assert_eq(NODE_DATA(node, int), data);
    cr_assert_eq(NODE_SIZE(node), sizeof(data));
}

Test(create_node, returns_null_for_null_data)
{
    cr_assert_null(create_node(NULL, sizeof(int)));
}

Test(create_node, returns_null_for_null_size)
{
    int data = 27;

    cr_assert_null(create_node(&data, 0));
}

Test(create_empty_node, creates_a_new_node_with_zero_init_data)
{
    node_t *node = create_empty_node(sizeof(long));

    cr_assert_not_null(node);
    cr_assert_not_null(NODE_PTR(node, long));
    cr_assert_eq(NODE_DATA(node, long), 0);
    cr_assert_eq(NODE_SIZE(node), sizeof(long));
}

Test(create_empty_node, returns_null_for_null_size)
{
    cr_assert_null(create_empty_node(0));
}

Test(create_ptr_node, creates_a_new_node_giving_a_data_pointer)
{
    int data = 27;
    node_t *node = create_ptr_node(&data);

    cr_assert_not_null(node);
    cr_assert_eq(NODE_PTR(node, int), &data);
    cr_assert_eq(NODE_SIZE(node), 0);
}

Test(create_ptr_node, returns_null_for_null_pointer)
{
    cr_assert_null(create_ptr_node(NULL));
}

Test(create_string_node, creates_a_new_node_and_copy_string)
{
    const char *str = "A string";
    node_t *node = create_string_node(str);

    cr_assert_not_null(node);
    cr_assert_not_null(NODE_STR(node));
    cr_assert_neq(NODE_STR(node), str);
    cr_assert_str_eq(NODE_STR(node), str);
    cr_assert_eq(NODE_SIZE(node), strlen(str));
}

Test(create_string_node, returns_null_for_null_string)
{
    cr_assert_null(create_string_node(NULL));
}
