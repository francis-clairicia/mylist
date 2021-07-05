/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_to_array
*/

#include <stdlib.h>
#include "mylist/string_list.h"

char **string_list_to_array(const string_list_t *list, size_t *length)
{
    size_t nmemb = (list) ? list_len(list) : 0;
    char **array = (list) ? calloc(nmemb + 1, sizeof(*array)) : NULL;
    size_t start = 0;

    if (array) {
        list_foreach(node, list) {
            array[start++] = NODE_STR(node);
        }
    } else {
        nmemb = 0;
    }
    if (length)
        *length = nmemb;
    return array;
}