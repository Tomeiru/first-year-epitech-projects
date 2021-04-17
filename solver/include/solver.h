/*
** EPITECH PROJECT, 2021
** Temp
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

typedef struct node_s {
    int x;
    int y;
    struct node_s *next;
    struct node_s *prev;
} node_t;

typedef struct info_s {
    int x;
    int y;
    int current_x;
    int current_y;
    char **maze;
    char *direction;
    int cell_visited;
    int total_cell;
    node_t *head;
    node_t *last;
} info_t;

void solver(info_t *info_struct);
void error(int ac, char **av);
void error_map(char *map);
void error_arg(int ac);
info_t *create_and_fill_struct(char *maze_str, int len);
int get_y_value(char *maze_str);
int get_x_value(char *maze_str);
void error_maze(char *maze, int len, int x, int y);
char *file_reader(char *filepath, int *len);
void add_end(info_t *info_struct, node_t **last);
void add_end_first(info_t *info_struct, node_t **head, node_t **last);
void update_current_coord(info_t *info_struct, node_t **last);
void remove_last_node(node_t **last);
int check_possible_direction(info_t *info_struct);
void apply_direction(info_t *info_struct, int direction);

#endif /* !SOLVER_H_ */
