/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-mathieu.brujan
** File description:
** create_linked_list
*/

#include "my_sokoban.h"

void assign_storage_coord(struct node *storage, int idx, char **arr)
{
    int j = 0;
    int stop = 0;
    int O_count = 0;

    for (int i = 0; arr[i]; i++) {
        for (j = 0; arr[i][j]; j++) {
            if (arr[i][j] == 'O')
                O_count++;
            if (O_count == idx) {
                storage->x = j;
                storage->y = i;
                stop = 1;
                break;
            }
        }if (stop == 1)
            break;
    }
}

void assign_box_coord(struct node *box, int idx, char **arr)
{
    int j = 0;
    int stop = 0;
    int X_count = 0;

    for (int i = 0; arr[i]; i++) {
        for (j = 0; arr[i][j]; j++) {
            if (arr[i][j] == 'X')
                X_count++;
            if (X_count == idx) {
                box->x = j;
                box->y = i;
                stop = 1;
                break;
            }
        }if (stop == 1)
            break;
    }
}

struct node *create_storage_linked_list(struct game_struct *game)
{
    struct node *head_storages = malloc(sizeof(struct node));
    struct node *back_up = head_storages;
    int idx = 1;
    
    head_storages->idx = idx++;
    assign_storage_coord(head_storages, head_storages->idx, game->map_arr);
    for (int i = 1; i < game->nb_of_boxes; i++) {
        back_up->next = malloc(sizeof(struct node));
        back_up = back_up->next;
        back_up->idx = idx++;
        assign_storage_coord(back_up, back_up->idx, game->map_arr);
    }back_up->next = head_storages;
    return (head_storages);
}

struct node *create_box_linked_list(struct game_struct *game)
{
    struct node *head_boxes = malloc(sizeof(struct node));
    struct node *back_up = head_boxes;
    int idx = 1;
    
    head_boxes->idx = idx++;
    assign_box_coord(head_boxes, head_boxes->idx, game->map_arr);
    for (int i = 1; i < game->nb_of_boxes; i++) {
        back_up->next = malloc(sizeof(struct node));
        back_up = back_up->next;
        back_up->idx = idx++;
        assign_box_coord(back_up, back_up->idx, game->map_arr);
    }back_up->next = head_boxes;
    return (head_boxes);
}