/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <curses.h>

struct game_struct
{
    char *map;
    char **map_arr;
    char **edited_map_arr;
    int height_map;
    int width_map;
    int height_window;
    int width_window;
    int need_resize;
    int cursor_x;
    int cursor_y;
    int x_to_center;
    int y_to_center;
    int initial_p_x;
    int initial_p_y;
    int reset;
    int nb_of_boxes;
};

struct node
{
    int x;
    int y;
    int idx;
    struct node *next;
};

#endif /* !SOKOBAN_H_ */
