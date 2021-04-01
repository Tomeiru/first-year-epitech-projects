/*
** EPITECH PROJECT, 2021
** duo_stumper3
** File description:
** writ_numbers_first
*/

#include "stumper.h"

void write_five(info_t *info, int i)
{
    info->array[0][i] = info->chars[info->lenght_chars % 5];
    info->array[0][i + 1] = info->chars[info->lenght_chars % 5];
    info->array[0][i + 2] = info->chars[info->lenght_chars % 5];
    info->array[0][i + 3] = info->chars[info->lenght_chars % 5];
    info->array[0][i + 4] = info->chars[info->lenght_chars % 5];

    info->array[1][i] = info->chars[info->lenght_chars % 5];

    info->array[2][i] = info->chars[info->lenght_chars % 5];
    info->array[2][i + 1] = info->chars[info->lenght_chars % 5];
    info->array[2][i + 2] = info->chars[info->lenght_chars % 5];
    info->array[2][i + 3] = info->chars[info->lenght_chars % 5];

    info->array[3][i + 4] = info->chars[info->lenght_chars % 5];

    info->array[4][i] = info->chars[info->lenght_chars % 5];
    info->array[4][i + 1] = info->chars[info->lenght_chars % 5];
    info->array[4][i + 2] = info->chars[info->lenght_chars % 5];
    info->array[4][i + 3] = info->chars[info->lenght_chars % 5];
}

void write_six(info_t *info, int i)
{
    info->array[0][i + 1] = info->chars[info->lenght_chars % 6];
    info->array[0][i + 2] = info->chars[info->lenght_chars % 6];
    info->array[0][i + 3] = info->chars[info->lenght_chars % 6];

    info->array[1][i] = info->chars[info->lenght_chars % 6];

    info->array[2][i] = info->chars[info->lenght_chars % 6];
    info->array[2][i + 1] = info->chars[info->lenght_chars % 6];
    info->array[2][i + 2] = info->chars[info->lenght_chars % 6];
    info->array[2][i + 3] = info->chars[info->lenght_chars % 6];

    info->array[3][i] = info->chars[info->lenght_chars % 6];
    info->array[3][i + 4] = info->chars[info->lenght_chars % 6];

    info->array[4][i + 1] = info->chars[info->lenght_chars % 6];
    info->array[4][i + 2] = info->chars[info->lenght_chars % 6];
    info->array[4][i + 3] = info->chars[info->lenght_chars % 6];
}

void write_seven(info_t *info, int i)
{
    info->array[0][i] = info->chars[info->lenght_chars % 7];
    info->array[0][i + 1] = info->chars[info->lenght_chars % 7];
    info->array[0][i + 2] = info->chars[info->lenght_chars % 7];
    info->array[0][i + 3] = info->chars[info->lenght_chars % 7];
    info->array[0][i + 4] = info->chars[info->lenght_chars % 7];
    info->array[1][i + 4] = info->chars[info->lenght_chars % 7];
    info->array[2][i + 3] = info->chars[info->lenght_chars % 7];
    info->array[3][i + 2] = info->chars[info->lenght_chars % 7];
    info->array[4][i + 1] = info->chars[info->lenght_chars % 7];
}

void write_eight(info_t *info, int i)
{
    info->array[0][i + 1] = info->chars[info->lenght_chars % 8];
    info->array[0][i + 2] = info->chars[info->lenght_chars % 8];
    info->array[0][i + 3] = info->chars[info->lenght_chars % 8];
    info->array[1][i] = info->chars[info->lenght_chars % 8];
    info->array[1][i + 4] = info->chars[info->lenght_chars % 8];
    info->array[2][i + 1] = info->chars[info->lenght_chars % 8];
    info->array[2][i + 2] = info->chars[info->lenght_chars % 8];
    info->array[2][i + 3] = info->chars[info->lenght_chars % 8];
    info->array[3][i] = info->chars[info->lenght_chars % 8];
    info->array[3][i + 4] = info->chars[info->lenght_chars % 8];
    info->array[4][i + 1] = info->chars[info->lenght_chars % 8];
    info->array[4][i + 2] = info->chars[info->lenght_chars % 8];
    info->array[4][i + 3] = info->chars[info->lenght_chars % 8];
}

void write_nine(info_t *info, int i)
{
    info->array[0][i + 1] = info->chars[info->lenght_chars % 9];
    info->array[0][i + 2] = info->chars[info->lenght_chars % 9];
    info->array[0][i + 3] = info->chars[info->lenght_chars % 9];

    info->array[1][i] = info->chars[info->lenght_chars % 9];
    info->array[1][i + 4] = info->chars[info->lenght_chars % 9];

    info->array[2][i + 1] = info->chars[info->lenght_chars % 9];
    info->array[2][i + 2] = info->chars[info->lenght_chars % 9];
    info->array[2][i + 3] = info->chars[info->lenght_chars % 9];
    info->array[2][i + 4] = info->chars[info->lenght_chars % 9];

    info->array[3][i + 4] = info->chars[info->lenght_chars % 9];

    info->array[4][i + 1] = info->chars[info->lenght_chars % 9];
    info->array[4][i + 2] = info->chars[info->lenght_chars % 9];
    info->array[4][i + 3] = info->chars[info->lenght_chars % 9];
}
