/*
** EPITECH PROJECT, 2020
** my_params_to_list
** File description:
** my_params_to_list
*/

#include <stddef.h>
#include "mylist.h"

linked_list_t *pleaselist(linked_list_t *list, char *s)
{
    linked_list_t *prev = malloc(sizeof(linked_list_t));
    prev->data = s;
    prev->next = list;
    list = prev;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list = NULL;
    for(int i = 0; i < ac; i++) {
        pleaselist(list, av[i]);
    }
    return (list);

}
