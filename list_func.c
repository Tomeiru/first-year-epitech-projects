/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-mathieu.brujan
** File description:
** list_func
*/

#include "pushswap.h"

void add_end(node **last, int data)
{
    node *new_node = malloc(sizeof(node));

    new_node->data = data;
    new_node->next = NULL;
    (*last)->next = new_node;
    (*last) = (*last)->next;
}

node *add_beg(node *head, int data)
{
    node *new_node = malloc(sizeof(node));

    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return (head);
}

node *args_to_list(int ac, char **av, node *head)
{
    for (int i = 1; i < ac; i++)
        head = add_beg(head, my_getnbr(av[i]));
    return (head);
}

node *pb_to_list(int ac, node *head, node **last)
{
    for (int i = 1; i < ac; i++)
        head = add_beg(head, 0);
    for ((*last) = head; (*last)->next != NULL; *last = (*last)->next);
    return (head);
}