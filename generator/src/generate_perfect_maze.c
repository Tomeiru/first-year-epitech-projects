/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** generate_perfect_maze
*/

#include "generator.h"

int get_random_dir(info_t *info_struct, int number_dir)
{
    int rand_num = 0;
    int direction = 0;

    rand_num = rand();
    rand_num = rand_num % number_dir + 1;
    for (int i = 0; info_struct->direction[i]; i++) {
        if (info_struct->direction[i] == '0')
            continue;
        direction++;
        if (direction == rand_num)
            return (i);
    }return (0);
}

void add_escape(info_t *info_struct)
{
    int x_odd = info_struct->x % 2;
    int y_odd = info_struct->y % 2;

    info_struct->maze[info_struct->y - 1][info_struct->x - 1] = '*';
    if (x_odd == 0 && y_odd == 0)
        info_struct->maze[info_struct->y - 1][info_struct->x - 2] = '*';
}

void generate_perfect_maze(info_t *info_struct)
{
    int number_dir = 0;
    int direction = 0;

    while (info_struct->cell_visited != info_struct->total_cell) {
        number_dir = check_possible_direction(info_struct);
        if (number_dir == 0) {
            //remove_last_node(&info_struct->head);
            //update_current_coord(info_struct, &info_struct->head, number_dir);
            continue;
        } direction = get_random_dir(info_struct, number_dir);
        apply_direction(info_struct, direction);
    }
    add_escape(info_struct);
    for (int i = 0; info_struct->maze[i]; i++) {
        if (info_struct->maze[i + 1] == NULL)
            printf("%s", info_struct->maze[i]);
        else
            printf("%s\n", info_struct->maze[i]);
    }
}
