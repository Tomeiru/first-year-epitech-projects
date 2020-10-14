/*
** EPITECH PROJECT, 2020
** my_delete_nodes
** File description:
** my_delete_nodes
*/

#include <stddef.h>
#include "mylist.h"

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *list = *begin;

    while (begin != NULL) {
        if (cmp(list->data, data_ref) == 0)
            *begin = list->next;
        list = list->next;
    }
    *begin = list;
}