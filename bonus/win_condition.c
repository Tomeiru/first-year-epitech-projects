/*
** EPITECH PROJECT, 2020
** win_condition
** File description:
** functions regarding players winning
*/

#include "navy.h"

void i_won(void)
{
    printf(game_struct.board);
    write(1, "I won\n\n", 8);
    exit(0);
}

void enemy_won(void)
{
    printf(game_struct.board);
    write(1, "Enemy won\n\n", 12);
    exit(1);
}

void check_win(void)
{
    if (game_struct.enemy_hit == 14)
        enemy_won();
    if (game_struct.hit == 14)
        i_won();
}