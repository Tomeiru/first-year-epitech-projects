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
    int len_board;
    int line_len = 1;

    if (ac != 2)
        return (84);
    board = file_reader(av[1]);
    if (board[0] == '!')
        return (84);
    for ( ; *board != '\n'; board++);
    board++;
    for (int i = 0; board[i] != '\n'; i++)
        line_len++;
    len_board = my_strlen(board);
    algorithm(board, len_board, line_len);
    return (0);
}