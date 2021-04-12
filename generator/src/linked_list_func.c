/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** linked_list_func
*/

#include "generator.h"

/*void add_end(info_t *info_struct, node_t **last)
{
    node_t *new_node = malloc(sizeof(node_t));

    new_node->x = info_struct->current_x;
    new_node->y = info_struct->current_y;
    new_node->next = NULL;
    *last->next = new_node;
    *last = new_node;
}*/

void add_end(info_t *info_struct, node_t **head)
{
    node_t *new_node = malloc(sizeof(node_t));
    node_t *backup = *head;

    new_node->x = info_struct->current_x;
    new_node->y = info_struct->current_y;
    new_node->next = NULL;
    for ( ; backup->next != NULL; backup = backup->next);
    backup->next = new_node;
}

void update_current_coord(info_t *info_struct, node_t **head)
{
    node_t *backup = *head;

    for ( ; backup->next != NULL; backup = backup->next);
    info_struct->current_x = backup->x;
    info_struct->current_y = backup->y;
}

void remove_last_node(node_t **head)
{
    node_t *backup = *head;
    node_t *backup_bef = *head;
    int i = 0;

    for ( ; backup->next != NULL; backup = backup->next) {
        if (i != 0)
            backup_bef = backup_bef->next;
        i++;
    }backup_bef->next = NULL;
}