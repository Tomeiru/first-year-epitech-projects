/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** create_struct
*/

#include "solver.h"

static char **malloc_maze(info_t *info_struct, char *maze_str)
{
    char **maze = malloc(sizeof(char *) * (info_struct->y + 1));
    int idx = 0;

    if (maze == NULL)
        exit(84);
    for (int i = 0; i < info_struct->y; i++) {
        maze[i] = malloc(sizeof(char) * (info_struct->x + 1));
        if (maze[i] == NULL)
            exit(84);
        for (int j = 0; j < info_struct->x; j++)
            maze[i][j] = maze_str[idx++];
        maze[i][info_struct->x] = '\0';
        idx++;
    }maze[info_struct->y] = NULL;
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

static int get_total_cell(char *maze_str)
{
    int ret = 0;

    for (int i = 0; maze_str[i]; i++)
        if (maze_str[i] == '*')
            ret++;
    return (ret);
}

static node_t *init_stack(void)
{
    node_t *head = malloc(sizeof(node_t));

    head->x = 0;
    head->y = 0;
    head->next = NULL;
    head->prev = NULL;
    return (head);
}

info_t *create_and_fill_struct(char *maze_str, int len)
{
    info_t *info_struct = malloc(sizeof(info_t));

    if (info_struct == NULL)
        exit(84);
    info_struct->x = get_x_value(maze_str);
    info_struct->y = get_y_value(maze_str);
    error_maze(maze_str, len, info_struct->x, info_struct->y);
    info_struct->current_x = 0;
    info_struct->current_y = 0;
    info_struct->maze = malloc_maze(info_struct, maze_str);
    info_struct->direction = malloc_direction();
    info_struct->cell_visited = 1;
    info_struct->total_cell = get_total_cell(maze_str);
    info_struct->head = init_stack();
    info_struct->last = NULL;
    return (info_struct);
}