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
    int line_num = 0;

    if (ac != 2)
        return (84);
    board = file_reader(av[1]);
    if (board[0] == '!')
        return (84);
    line_num = my_get_first_line(board);
    for ( ; *board != '\n'; *board++);
    *board++;
    algorithm(board, line_num);
    return (0);
}