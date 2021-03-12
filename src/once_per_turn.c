/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-mathieu.brujan
** File description:
** once_per_turn
*/

#include "matchstick.h"

void print_board(game_t *game)
{
    for (int i = 0; i < game->line_size + 2; i++)
        write(1 , "*", 1);
    write(1, "\n", 1);
    for (int i = 0; i < game->lines; i++) {
        write(1 , "*", 1);
        write(1, game->board[i], game->line_size);
        write(1 , "*", 1);
        write(1, "\n", 1);
    }for (int i = 0; i < game->line_size + 2; i++)
        write(1 , "*", 1);
    write(1, "\n", 1);
    
}

void remove_from_board(game_t *game, int line, int matches)
{
    int i = 0;

    game->board_nbr[line - 1] -= matches;
    my_revstr(game->board[line-1]);
    for ( ; game->board[line - 1][i] == ' '; i++);
    for (int j = 0; j < matches; j++)
        game->board[line - 1][i++] = ' ';
    my_revstr(game->board[line-1]);
    write(1, "\n", 1);
    print_board(game);
}

int check_lose(game_t *game)
{
    for (int i = 0; game->board_nbr[i] != -1; i++)
        if (game->board_nbr[i] != 0)
            return (0);
    return (1);
}