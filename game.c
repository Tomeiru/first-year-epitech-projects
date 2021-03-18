/*
** EPITECH PROJECT, 2021
** duo_stumper2
** File description:
** game
*/

#include "stumper.h"

int error_input(char *col, unsigned long size)
{
    for (int i = 0; col[i]; i++)
        if (col[i] < '0' || col[i] > '9')
            return (-1);
    return (atoi(col));
}

int get_col_input(void)
{
    char *col = NULL;
    int num = 0;
    unsigned long size = 0;

    if (getline(&col, &size, stdin) == -1)
        exit(0);
    size = strlen(col) - 1;
    col[size] = '\0';
    num = error_input(col, size);
    if (num == -1)
        return (-1);
    return (num);
}


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
        printf("Player %c, where do you want to play: ", game->current_player);
        col = get_col_input();
    }
    return (col);
}//TO DO : INPUT
