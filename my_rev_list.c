/*
** EPITECH PROJECT, 2020
** my_rev_list
** File description:
** my_rev_list
*/

#include <stddef.h>
#include "mylist.h" 

void my_rev_list(linked_list_t const **begin)
{
    linked_list_t *list = *begin;
    linked_list_t *cpynext = NULL;
    linked_list_t *cpypre = NULL;

    while (list != NULL) {
        cpynext = list->next;
        list->next = cpypre;
        cpypre = list;
        list = cpynext;
    }
    *begin = cpypre;
}