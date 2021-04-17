/*
** EPITECH PROJECT, 2021
** Temp
** File description:
** solver
*/

#include "solver.h"

static void print_solved_maze(info_t *info_struct)
{
    for (int i = 0; info_struct->maze[i]; i++) {
        if (info_struct->maze[i + 1] == NULL)
            printf("%s", info_struct->maze[i]);
        else
            printf("%s\n", info_struct->maze[i]);
    }
}

static void post_processing(info_t *info_struct)
{
    for (int i = 0; info_struct->maze[i]; i++)
        for (int j = 0; info_struct->maze[i][j]; j++)
            if (info_struct->maze[i][j] == 'v')
                info_struct->maze[i][j] = '*';
}

static int get_random_dir(info_t *info_struct, int number_dir)
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

static void check_unsolvable(info_t *info_struct)
{
    if (!(info_struct->current_x == 0 && info_struct->current_y == 0))
        return;
    if (info_struct->x == 1) {
        if (info_struct->maze[1][0] != '*') {
            printf("no solution found\n");
            exit(0);
        }return;
    }if (info_struct->y == 1) {
        if (info_struct->maze[0][1] != '*') {
            printf("no solution found\n");
            exit(0);
        }return;
    }if (info_struct->maze[1][0] != '*' && info_struct->maze[0][1] != '*') {
        printf("no solution found\n");
        exit(0);
    }
}

void solver(info_t *info_struct)
{
    int number_dir = 0;
    int direction = 0;

    while (info_struct->cell_visited != info_struct->total_cell) {
        number_dir = check_possible_direction(info_struct);
        if (number_dir == 0) {
            check_unsolvable(info_struct);
            info_struct->maze[info_struct->current_y]
            [info_struct->current_x] = 'v';
            remove_last_node(&info_struct->last);
            update_current_coord(info_struct, &info_struct->last);
            continue;
        } direction = get_random_dir(info_struct, number_dir);
        apply_direction(info_struct, direction);
        if (info_struct->maze[info_struct->y - 1]
            [info_struct->x - 1] == 'o')
            break;
    }post_processing(info_struct);
    print_solved_maze(info_struct);
}