/*
** EPITECH PROJECT, 2020
** win_condition
** File description:
** functions regarding players winning
*/

#include "navy.h"

int i_won(void)
{
    write(1, game_struct.board, 395);
    write(1, "I won\n\n", 8);
    return (0);
}

int enemy_won(void)
{
    write(1, game_struct.board, 395);
    write(1, "Enemy won\n\n", 12);
    return (1);
}

int check_win(void)
{
    if (game_struct.enemy_hit == 14)
        return (enemy_won());
    if (game_struct.hit == 14)
        return (i_won());
    return (2);
}