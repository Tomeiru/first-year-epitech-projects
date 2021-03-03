/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-mathieu.brujan
** File description:
** map_str_to_map_arr
*/

#include "my_sokoban.h"

void map_str_to_map_arr(struct game_struct *game)
{
    int idx = 0;

    game->map_arr = malloc(sizeof(char *) * (game->height_map + 1));
    game->edited_map_arr = malloc(sizeof(char *) * (game->height_map + 1));
    for (int i = 0; i < game->height_map; i++) {
        game->map_arr[i] = malloc(sizeof(char) * game->width_map + 1);
        game->edited_map_arr[i] = malloc(sizeof(char) * game->width_map + 1);
        for (int j = 0; j < game->width_map; j++) {
            game->map_arr[i][j] = game->map[idx];
            game->edited_map_arr[i][j] = game->map[idx++];
        }idx++;
        game->map_arr[i][game->width_map] = '\0';
        game->edited_map_arr[i][game->width_map] = '\0';
    }game->map_arr[game->height_map] = NULL;
    game->edited_map_arr[game->height_map] = NULL;
}