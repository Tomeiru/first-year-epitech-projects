/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-BSQ-mathieu.brujan
** File description:
** algorithm
*/

#include "bsq.h"

int find_smallest_value(int value_corner, int value_left, int value_up)
{
    if (value_corner <= value_left && value_corner <= value_up)
        return (value_corner);
    if (value_left <= value_corner && value_left <= value_up)
        return (value_left);
    else
        return (value_up);
}

int free_space(int *number_board, int i, int line_len)
{
    int value_corner = 0;
    int value_left = 0;
    int value_up = 0;
    int smallest_value = 0;

    if (i < line_len || i % line_len == 0)
        return (1);
    value_corner = number_board[i - line_len - 1];
    value_left = number_board[i - 1];
    value_up = number_board[i - line_len];
    smallest_value = find_smallest_value(value_corner, value_left, value_up);
    return (smallest_value + 1);
}

int new_challenger(int max_value, int challenger, int pos_chall, int *max_pos)
{
    if (max_value >= challenger)
        return (max_value);
    *max_pos = pos_chall;
    return (challenger);
}

void print_function(int max_value, int max_pos, int line_len, char *board)
{
    int back_up = max_pos - max_value;

    for (int i = 0; i < max_value; i++) {
        for ( ; max_pos != back_up; max_pos--)
            board[max_pos] = 'x';
        max_pos = max_pos - line_len + max_value;
        back_up -= line_len;
    }
    my_putstr(board);
}

void algorithm(char *board)
{
    int line_len = 1;
    int max_value = 0;
    int max_pos = 0;
    short *number_board;
    int j = 0;

    for ( ; board[j]; j++);
    number_board = malloc(sizeof(short) * (++j));
    number_board[j] = -1;
    for (int i = 0; board[i] != '\n'; i++)
        line_len++;
    for (int i = 0; board[i]; i++) {
        if (board[i] == '\n')
            number_board[i] = -1000;
        if (board[i] == 'o')
            number_board[i] = 0;
        else if (board[i] == '.') {
            number_board[i] = free_space(number_board, i, line_len);
            max_value = new_challenger(max_value, number_board[i], i, &max_pos);
        }
    }
    print_function(max_value, max_pos, line_len, board);
    free(number_board);
}