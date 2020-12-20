/*
** EPITECH PROJECT, 2020
** check_format
** File description:
** function that checks format
*/

#include "navy.h"

int check_format(char *pos_str)
{
    char letter_char[8] = {
        2, 5, 10, 13, 18, 21, 26, 29
    };
    char number_char[8] = {
        3, 6, 11, 14, 19, 22, 27, 30
    };
    char double_points[8] = {
        1, 4, 9, 12, 17, 20, 25, 28
    };
    char length[8] = {
        0, 8, 16, 24, 7, 15, 23, 31
    };
    int comp = 2;

    for (int i = 0; i < 8; i++)
        if ((pos_str[letter_char[i]] < 'A' || pos_str[letter_char[i]] > 'H') ||
        (pos_str[double_points[i]] != ':') || 
        (pos_str[number_char[i]] < '1' || pos_str[number_char[i]] > '9') ||
        (i < 4 && pos_str[length[i]] != 48 + comp++) ||
        (i > 3 && pos_str[length[i]] != '\n'))
            return (error_write(2));
    return (0);
}