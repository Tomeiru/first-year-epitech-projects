/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** bsq
*/

#include "bsq.h"

int bsq(int ac, char **av)
{
    char *board;

    if (ac != 2)
        return (84);
    board = file_reader(av[1]);
    if (board[0] == '!')
        return (84);
    for ( ; *board != '\n'; board++);
    board++;
    algorithm(board);
    return (0);
}