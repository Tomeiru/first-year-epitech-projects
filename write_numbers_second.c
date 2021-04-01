/*
** EPITECH PROJECT, 2021
** duo_stumper3
** File description:
** writ_numbers_first
*/

#include "stumper.h"

void write_five(info_t *info, int i)
{
    info->array[0][i] = info->chars[5 % info->lenght_chars];
    info->array[0][i + 1] = info->chars[5 % info->lenght_chars];
    info->array[0][i + 2] = info->chars[5 % info->lenght_chars];
    info->array[0][i + 3] = info->chars[5 % info->lenght_chars];
    info->array[0][i + 4] = info->chars[5 % info->lenght_chars];
    info->array[1][i] = info->chars[5 % info->lenght_chars];
    info->array[2][i] = info->chars[5 % info->lenght_chars];
    info->array[2][i + 1] = info->chars[5 % info->lenght_chars];
    info->array[2][i + 2] = info->chars[5 % info->lenght_chars];
    info->array[2][i + 3] = info->chars[5 % info->lenght_chars];
    info->array[3][i + 4] = info->chars[5 % info->lenght_chars];
    info->array[4][i] = info->chars[5 % info->lenght_chars];
    info->array[4][i + 1] = info->chars[5 % info->lenght_chars];
    info->array[4][i + 2] = info->chars[5 % info->lenght_chars];
    info->array[4][i + 3] = info->chars[5 % info->lenght_chars];
}

void write_six(info_t *info, int i)
{
    info->array[0][i + 1] = info->chars[6 % info->lenght_chars];
    info->array[0][i + 2] = info->chars[6 % info->lenght_chars];
    info->array[0][i + 3] = info->chars[6 % info->lenght_chars];
    info->array[1][i] = info->chars[6 % info->lenght_chars];
    info->array[2][i] = info->chars[6 % info->lenght_chars];
    info->array[2][i + 1] = info->chars[6 % info->lenght_chars];
    info->array[2][i + 2] = info->chars[6 % info->lenght_chars];
    info->array[2][i + 3] = info->chars[6 % info->lenght_chars];
    info->array[3][i] = info->chars[6 % info->lenght_chars];
    info->array[3][i + 4] = info->chars[6 % info->lenght_chars];
    info->array[4][i + 1] = info->chars[6 % info->lenght_chars];
    info->array[4][i + 2] = info->chars[6 % info->lenght_chars];
    info->array[4][i + 3] = info->chars[6 % info->lenght_chars];
}

void write_seven(info_t *info, int i)
{
    info->array[0][i] = info->chars[7 % info->lenght_chars];
    info->array[0][i + 1] = info->chars[7 % info->lenght_chars];
    info->array[0][i + 2] = info->chars[7 % info->lenght_chars];
    info->array[0][i + 3] = info->chars[7 % info->lenght_chars];
    info->array[0][i + 4] = info->chars[7 % info->lenght_chars];
    info->array[1][i + 4] = info->chars[7 % info->lenght_chars];
    info->array[2][i + 3] = info->chars[7 % info->lenght_chars];
    info->array[3][i + 2] = info->chars[7 % info->lenght_chars];
    info->array[4][i + 1] = info->chars[7 % info->lenght_chars];
}

void write_eight(info_t *info, int i)
{
    info->array[0][i + 1] = info->chars[8 % info->lenght_chars];
    info->array[0][i + 2] = info->chars[8 % info->lenght_chars];
    info->array[0][i + 3] = info->chars[8 % info->lenght_chars];
    info->array[1][i] = info->chars[8 % info->lenght_chars];
    info->array[1][i + 4] = info->chars[8 % info->lenght_chars];
    info->array[2][i + 1] = info->chars[8 % info->lenght_chars];
    info->array[2][i + 2] = info->chars[8 % info->lenght_chars];
    info->array[2][i + 3] = info->chars[8 % info->lenght_chars];
    info->array[3][i] = info->chars[8 % info->lenght_chars];
    info->array[3][i + 4] = info->chars[8 % info->lenght_chars];
    info->array[4][i + 1] = info->chars[8 % info->lenght_chars];
    info->array[4][i + 2] = info->chars[8 % info->lenght_chars];
    info->array[4][i + 3] = info->chars[8 % info->lenght_chars];
}

void write_nine(info_t *info, int i)
{
    info->array[0][i + 1] = info->chars[9 % info->lenght_chars];
    info->array[0][i + 2] = info->chars[9 % info->lenght_chars];
    info->array[0][i + 3] = info->chars[9 % info->lenght_chars];
    info->array[1][i] = info->chars[9 % info->lenght_chars];
    info->array[1][i + 4] = info->chars[9 % info->lenght_chars];
    info->array[2][i + 1] = info->chars[9 % info->lenght_chars];
    info->array[2][i + 2] = info->chars[9 % info->lenght_chars];
    info->array[2][i + 3] = info->chars[9 % info->lenght_chars];
    info->array[2][i + 4] = info->chars[9 % info->lenght_chars];
    info->array[3][i + 4] = info->chars[9 % info->lenght_chars];
    info->array[4][i + 1] = info->chars[9 % info->lenght_chars];
    info->array[4][i + 2] = info->chars[9 % info->lenght_chars];
    info->array[4][i + 3] = info->chars[9 % info->lenght_chars];
}
