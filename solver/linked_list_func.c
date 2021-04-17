/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** linked_list_func
*/

#include "solver.h"

void add_end(info_t *info_struct, node_t **last)
{
    node_t *new_node = malloc(sizeof(node_t));

    new_node->x = info_struct->current_x;
    new_node->y = info_struct->current_y;
    new_node->next = NULL;
    new_node->prev = *last;
    (*last)->next = new_node;
    *last = (*last)->next;
}

void add_end_first(info_t *info_struct, node_t **head, node_t **last)
{
    node_t *new_node = malloc(sizeof(node_t));

    new_node->x = info_struct->current_x;
    new_node->y = info_struct->current_y;
    new_node->next = NULL;
    new_node->prev = *head;
    *last = new_node;
    (*head)->next = *last;
}

void update_current_coord(info_t *info_struct, node_t **last)
{
    info_struct->current_x = (*last)->x;
    info_struct->current_y = (*last)->y;
}

void remove_last_node(node_t **last)
{
    *last = (*last)->prev;
    (*last)->next = NULL;
}