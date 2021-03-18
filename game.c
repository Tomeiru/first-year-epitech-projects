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

void add_piece(game_t *game, int col)
{
    int i = 1;
  
    for (; game->map[i][col] == '.'; i++);
    game->map[i - 1][col] = game->current_player;
    return;
}

int get_col(game_t *game)
{
    int col = -1;
  
    while (col < 1 || col > game->width || game->map[1][col] != '.') {
        printf("Player %c, where do you want to play: ", game->current_player);
        col = get_col_input();
    }
    return (col);
}
