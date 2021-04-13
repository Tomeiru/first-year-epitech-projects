/*
** EPITECH PROJECT, 2021
** Temp
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdlib.h>
#include <string.h>
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
    int perfect;
    char **maze;
    char *direction;
    int cell_visited;
    int total_cell;
    node_t *head;
    node_t *last;
} info_t;

void generator(info_t *info_struct);
void error(int ac, char **av);
info_t *create_and_fill_struct(int ac, char **av);
void apply_direction(info_t *info_struct, int direction);
int check_possible_direction(info_t *info_struct);
void generate_perfect_maze(info_t *info_struct);

#endif /* !GENERATOR_H_ */