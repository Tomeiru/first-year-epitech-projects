/*
** EPITECH PROJECT, 2020
** my_apply_on_matching_nodes
** File description:
** my_apply_on_matching_nodes
*/

#include <stddef.h>
#include "mylist.h"

int my_apply_on_matching_nodes(linked_list_t *begin , int (*f)(), void const *data_ref, int (*cmp)())
{
    while (begin != NULL) {
        if (cmp(begin->data, data_ref))
            (*f)(begin->data);
        begin = begin->next;
    }
}