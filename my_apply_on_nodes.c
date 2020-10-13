/*
** EPITECH PROJECT, 2020
** my_apply_on_nodes
** File description:
** my_apply_on_nodes
*/

#include <stddef.h>
#include "mylist.h"

int my_apply_on_nodes(linked_list_t *begin , int (*f)(void *))
{
    while (begin != NULL) {
        (*f)(begin->data);
        begin = begin->next;
    }
}