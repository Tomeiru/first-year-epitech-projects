/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-BSQ-mathieu.brujan
** File description:
** algorithm
*/

#include "bsq.h"

int am_i_edgy(char *board, int location, int line_len, int actual_exp)
{
    int i = location;
    int next_objective = location + line_len * actual_exp;

    for ( ; i < next_objective && board[i] != '\0'; i++);
    if (board[location + actual_exp] == '\n' || board[i] == '\0')
        return (1);
    return (0);
}

int can_i_expand(char *board, int location, int line_len, int actual_exp)
{
    int corner = 0;
    int horizontal = 0;
    int vertical = 0;

    if (am_i_edgy(board, location, line_len, actual_exp) == 1)
        return (0);
    corner = location + actual_exp + actual_exp * line_len;
    horizontal = location + actual_exp * line_len;
    vertical = location + actual_exp;
    if (board[corner] == 'o')
        return (0);
    for (vertical; vertical != corner; vertical += line_len)
        if (board[vertical] == 'o')
            return (0);
    for (horizontal; horizontal != corner; horizontal++)
        if (board[horizontal] == 'o')
            return (0);
    return (1);
}

int square_size (char *board, int location, int line_len, int line_num, int champ)
{
    int res = 1;
    int j = location;
    int l = location;

    for (int i = 0; i < champ; i++)
    for (j; board[j] != '\0' && board[j] != '\n' && board[j] != 'o'; j++);
    if (j - location <= champ)
        return (res);
    for (j = location; board[l] != 'o' && l < line_len * line_num; l += line_len)
        j++;
    if (j - location <= champ)
        return (res);
    l = location;
    for (j = location; board[l] != 'o' && l < line_len * line_num && 
    board[j] != '\0' && board[j] != '\n'; l += (line_len + 1))
        j++;
    if (j - location <= champ)
        return (res);
    for (res; can_i_expand(board, location, line_len, res) == 1; res++);
    return (res);
}


int who_is_larger(int champ, int new_chall, int *champ_pos, int pos)
{
    if (champ < new_chall) {
        *champ_pos = pos;
        return (new_chall);
    }
    if (champ >= new_chall)
        return (champ);
    return (0);
}

void print_map(char *board, int champ_pos, int champ, int len)
{
    int pos_hoz = champ_pos;
    int pos_vert = champ_pos;
    int goal = champ_pos + champ;

    for (pos_vert; pos_vert != champ_pos + len * champ; pos_vert += len) {
        for (pos_hoz; pos_hoz != goal; pos_hoz++)
            board[pos_hoz] = 'x';
        pos_hoz += (len - champ);
        goal += len;
    }
    my_putstr (board);
}

void algorithm(char *board, int line_num)
{
    int new_chall = 0;
    int champ = 0;
    int champ_pos = 0;
    int line_len = 1;

    for (int i = 0; board[i] != '\n'; i++)
        line_len++;
    for (int i = 0; board[i]; i++) {
        if (board[i] == '.') {
            new_chall = square_size(board, i, line_len, line_num, champ);
            champ = who_is_larger(champ, new_chall, &champ_pos, i);
        }
    }
    print_map(board, champ_pos, champ, line_len);
}