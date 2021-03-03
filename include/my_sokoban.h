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
#include <stdlib.h>

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

int my_sokoban(int ac, char **av);
void check_win_or_lose(struct game_struct *game, struct node *head_boxes,
struct node *head_storages);
void get_window_info(struct game_struct *game);
void init_p(struct game_struct *game, int y, int x);
void key_up_gestion(struct game_struct *game, struct node *head_boxes);
void key_left_gestion(struct game_struct *game, struct node *head_boxes);
void key_down_gestion(struct game_struct *game, struct node *head_boxes);
void key_right_gestion(struct game_struct *game, struct node *head_boxes);
void run_game(struct game_struct *game, struct node *head_boxes,
struct node *head_storages);
struct node *create_box_linked_list(struct game_struct *game);
struct node *create_storage_linked_list(struct game_struct *game);
void map_str_to_map_arr(struct game_struct *game);
void set_heigth_and_width(struct game_struct *game);
void error_file(char *file, struct game_struct *game);
char *file_reader(char *filepath);
void error_args(int ac, char **av);
struct game_struct *ini_struct(void);
void change_linked_list_down(struct game_struct *game, struct node *head_boxes);
void change_linked_list_up(struct game_struct *game, struct node *head_boxes);
void change_linked_list_left(struct game_struct *game, struct node *head_boxes);
void change_linked_list_right(struct game_struct *game,
struct node *head_boxes);
int condition_up(struct game_struct *game);
int condition_down(struct game_struct *game);
int condition_left(struct game_struct *game);
int condition_right(struct game_struct *game);
int my_strcmp(char const *s1, char const *s2);

#endif /* !SOKOBAN_H_ */
