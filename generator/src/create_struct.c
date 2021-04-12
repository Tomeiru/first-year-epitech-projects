/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** create_struct
*/

#include "generator.h"

static char **malloc_maze(info_t *info_struct)
{
    char **maze = malloc(sizeof(char *) * (info_struct->y + 1));

    if (maze == NULL)
        exit(84);
    for (int i = 0; i < info_struct->y; i++) {
        maze[i] = malloc(sizeof(char) * (info_struct->x + 1));
        if (maze[i] == NULL)
            exit(84);
        for (int j = 0; j < info_struct->x; j++)
            maze[i][j] = 'X';
        maze[i][info_struct->x] = '\0';
    }maze[info_struct->y] = NULL;
    maze[0][0] = '*';
    return (maze);
}

static char *malloc_direction(void)
{
    char *direction = malloc(sizeof(char) * 5);

    if (direction == NULL)
        exit(84);
    for (int i = 0; i < 4; i++)
        direction[i] = '0';
    direction[4] = '\0';
    return (direction);
}

static int get_total_cell(int x, int y)
{
    int total = 0;
    int new_x = 0;
    int new_y = 0;

    if (x % 2 == 1)
        new_x = (x / 2) + 1;
    else
        new_x = x / 2;
    if (y % 2 == 1)
        new_y = (y / 2) + 1;
    else
        new_y = y / 2;
    total = new_x * new_y;
    return (total);
}

static node_t *init_stack(void)
{
    node_t *head = malloc(sizeof(node_t));

    head->x = 0;
    head->y = 0;
    head->next = NULL;
    return (head);
}

info_t *create_and_fill_struct(int ac, char **av)
{
    info_t *info_struct = malloc(sizeof(info_t));

    if (info_struct == NULL)
        exit(84);
    info_struct->x = atoi(av[1]);
    info_struct->y = atoi(av[2]);
    info_struct->current_x = 0;
    info_struct->current_y = 0;
    if (ac == 4)
        info_struct->perfect = 1;
    else
        info_struct->perfect = 0;
    info_struct->maze = malloc_maze(info_struct);
    info_struct->direction = malloc_direction();
    info_struct->cell_visited = 1;
    info_struct->total_cell = get_total_cell(info_struct->x, info_struct->y);
    info_struct->head = init_stack();
    return (info_struct);
}