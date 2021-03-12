/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-mathieu.brujan
** File description:
** ini_struct
*/

#include "matchstick.h"

void board_generator(game_t *game)
{
    int line_size = 1 + ((game->lines - 1) * 2);
    int stick = 1;
    int space = (line_size - 1) / 2;
    int idx = 0;

    game->line_size = line_size;
    game->board = malloc(sizeof(char *) * (game->lines + 1));
    for (int i = 0; i < game->lines; i++) {
        game->board[i] = malloc(sizeof(char) * (line_size + 1));
        for (int j = 0; j < space; j++)
            game->board[i][idx++] = ' ';
        for (int j = 0; j < stick; j++)
            game->board[i][idx++] = '|';
        for (int j = 0; j < space; j++)
            game->board[i][idx++] = ' ';
        game->board[i][idx] = '\0';
        idx = 0;
        space -= 1;
        stick += 2;
    }game->board[game->lines] = NULL;
}

void board_nbr_generator(game_t *game)
{
    int stick = 1;

    game->board_nbr = malloc(sizeof(int) * (game->lines + 1));
    for (int i = 0; i < game->lines; i++) {
        game->board_nbr[i] = stick;
        stick += 2;
    }game->board_nbr[game->lines] = -1;
}

game_t *ini_struct(char **av)
{
    game_t *game = malloc(sizeof(game_t));

    game->lines = my_getnbr(av[1]);
    game->max = my_getnbr(av[2]);
    board_generator(game);
    board_nbr_generator(game);
    return (game);
}