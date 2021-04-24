/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** my_sokoban
*/

#include "my_sokoban.h"

int my_sokoban(int ac, char **av)
{
    struct game_struct *game = ini_struct();
    struct node *head_boxes = NULL;
    struct node *head_storages = NULL;
    int len = 0;

    error_args(ac, av);
    game->map = file_reader(av[1], &len);
    error_file(game->map, game);
    set_heigth_and_width(game, len);
    map_str_to_map_arr(game);
    head_boxes = create_box_linked_list(game);
    head_storages = create_storage_linked_list(game);
    run_game(game, head_boxes, head_storages);
    return (0);
}