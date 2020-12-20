/*
** EPITECH PROJECT, 2020
** check_format
** File description:
** function that checks format
*/

#include "navy.h"

int check_format(char *pos_str)
{
    int letter_char[16] = {
        2, 5, 10, 13, 18, 21, 26, 29, 3, 6, 11, 14, 19, 22, 27, 30
    };
    int double_points[16] = {
        0, 8, 16, 24, 7, 15, 23, 31, 1, 4, 9, 12, 17, 20, 25, 28
    };
    int comp = 2;

    for (int i = 0; i < 16; i++)
        if ((i < 8 && (pos_str[letter_char[i]] < 'A' ||
        pos_str[letter_char[i]] > 'H')) ||
        (i > 7 && pos_str[double_points[i]] != ':') ||
        (i > 7 && (pos_str[letter_char[i]] < '1' ||
        pos_str[letter_char[i]] > '9')) ||
        (i < 4 && pos_str[double_points[i]] != 48 + comp++) ||
        (i > 3 && i < 8 && pos_str[double_points[i]] != '\n'))
            return (error_write(2));
    return (0);
}