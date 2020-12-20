/*
** EPITECH PROJECT, 2020
** modify_board
** File description:
** functions to place x or o depending on if player hits or misses enemy boat
*/

#include "navy.h"

char *put_x(char *board, int coordinate)
{
    int line = coordinate / 10;
    int column = line * 10;
    int i = 52 + (18 * line) + (2 * (coordinate - column));

    board[i] = 'x';
    return (board);
}

char *put_o(char *board, int coordinate)
{
    int line = coordinate / 10;
    int column = line * 10;
    int i = 52 + (18 * line) + (2 * (coordinate - column));

    board[i] = 'o';
    return (board);
}