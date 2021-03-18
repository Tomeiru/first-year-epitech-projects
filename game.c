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
    condition_win(game);
    if (game->current_player == game->p1)
        game->current_player = game->p2;
    else
        game->current_player = game->p1;
    return;
}

void add_piece(game_t *game, int col)
{
    int i = 1;
  
    for (; game->map[i][col] == '.'; i++);
    game->map[i - 1][col] = game->current_player;
    return;
}//OK

int get_col(game_t *game)
{
    int col = -1;
  
    while (col < 1 || col > game->width || game->map[1][col] != '.') {
      //input col
      col = 3;
      if (game->current_player == game->p1)
          col = 2;
    }
    return (col);
}//TO DO : INPUT
