/*
** EPITECH PROJECT, 2020
** check_content
** File description:
** error managing functions for check_content
*/

#include "navy.h"

char *value_to_pos(int value)
{
    char let_list[8] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
    };
    char *pos = malloc(sizeof(char) * 4);

    pos[1] = value % 10 + 49;
    for (int i = 0; i < 8; i++)
        if (value / 10 == i)
            pos[0] = let_list[i];
    pos[2] = ':';
    pos[3] = '\0';
    return (pos);
}

int pos_to_value(char letter, char number)
{
    char let_list[8] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
    };
    int value = 0;

    for (int i = 0; i < 8; i++) {
        if (letter == let_list[i])
            value += (i) * 10;
    }
    value += number - 49;
    return (value);
}

int check_content(char *pos_str)
{
    int first = 0;
    int second = 0;

    for (int i = 0; i < 4; i++) {
        first = pos_to_value(pos_str[i * 8 + 2], pos_str[i * 8 + 3]);
        second = pos_to_value(pos_str[i * 8 + 5], pos_str[i * 8 + 6]);
        if (first != second - (i + 1) * 10 && first != second + (i + 1) * 10
        && first != second - i - 1 && first != second + i + 1)
            return (error_write(2));
    }
    return (0);
}