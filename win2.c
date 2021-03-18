/*
** EPITECH PROJECT, 2021
** duo_stumper2
** File description:
** game
*/

#include "stumper.h"

void check_char(game_t *game, int i, int j)
{
    if (game->map[i][j] != game->current_player)
        return;
    win_horinzontal(game, i, j);
    win_vertical(game, i, j);
    win_diagonal_r(game, i, j);
    win_diagonal_l(game, i, j);
}

int condition_win(game_t *game)
{
    for (int i = 0; game->map[i]; i++) {
        for (int j = 0; game->map[i][j]; j++)
	    check_char(game, i, j);
    }
}

void check_win(game_t *game)
{
    tie(game);
    condition_win(game);
    if (game->current_player == game->p1 && game->win == 0)
        game->current_player = game->p2;
    else if (game->win == 0)
        game->current_player = game->p1;
    return;
}
