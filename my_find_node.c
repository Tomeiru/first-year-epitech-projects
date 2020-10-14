/*
** EPITECH PROJECT, 2020
** my_find_nodes
** File description:
** my_find_nodes
*/

#include <stddef.h>
#include "mylist.h"

int my_find_node(linked_list_t const *begin, int (*f)(), void const *data_ref, int (*cmp)())
{
    while (begin != NULL) {
        if (cmp(begin->data, data_ref) == 0)
            return (begin);
        begin = begin->next;
    }
}