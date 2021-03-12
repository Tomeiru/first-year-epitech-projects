/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-mathieu.brujan
** File description:
** matchstick
*/

#include "matchstick.h"

int matchstick(char **av)
{
    game_t *game = ini_struct(av);

    print_board(game);
    return (user_turn(game));
}