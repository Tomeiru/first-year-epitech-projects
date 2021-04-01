/*
** EPITECH PROJECT, 2021
** duo_stumper3
** File description:
** writ_numbers_first
*/

#include "stumper.h"

void write_zero(info_t *info, int i)
{
    info->array[0][i + 1] = info->chars[0];
    info->array[0][i + 2] = info->chars[0];
    info->array[0][i + 3] = info->chars[0];
    info->array[1][i] = info->chars[0];
    info->array[1][i + 4] = info->chars[0];
    info->array[2][i] = info->chars[0];
    info->array[2][i + 4] = info->chars[0];
    info->array[3][i] = info->chars[0];
    info->array[3][i + 4] = info->chars[0];
    info->array[4][i + 1] = info->chars[0];
    info->array[4][i + 2] = info->chars[0];
    info->array[4][i + 3] = info->chars[0];
}

void write_one(info_t *info, int i)
{
    info->array[0][i + 1] = info->chars[1 % info->lenght_chars];
    info->array[0][i + 2] = info->chars[1 % info->lenght_chars];
    info->array[0][i + 3] = info->chars[1 % info->lenght_chars];
    info->array[1][i] = info->chars[1 % info->lenght_chars];
    info->array[1][i + 2] = info->chars[1 % info->lenght_chars];
    info->array[1][i + 3] = info->chars[1 % info->lenght_chars];
    info->array[2][i + 2] = info->chars[1 % info->lenght_chars];
    info->array[2][i + 3] = info->chars[1 % info->lenght_chars];
    info->array[3][i + 2] = info->chars[1 % info->lenght_chars];
    info->array[3][i + 3] = info->chars[1 % info->lenght_chars];
    info->array[4][i + 1] = info->chars[1 % info->lenght_chars];
    info->array[4][i + 2] = info->chars[1 % info->lenght_chars];
    info->array[4][i + 3] = info->chars[1 % info->lenght_chars];
    info->array[4][i + 4] = info->chars[1 % info->lenght_chars];
}

void write_two(info_t *info, int i)
{
    info->array[0][i + 1] = info->chars[2 % info->lenght_chars];
    info->array[0][i + 2] = info->chars[2 % info->lenght_chars];
    info->array[0][i + 3] = info->chars[2 % info->lenght_chars];
    info->array[1][i] = info->chars[2 % info->lenght_chars];
    info->array[1][i + 4] = info->chars[2 % info->lenght_chars];
    info->array[2][i + 3] = info->chars[2 % info->lenght_chars];
    info->array[3][i + 1] = info->chars[2 % info->lenght_chars];
    info->array[4][i] = info->chars[2 % info->lenght_chars];
    info->array[4][i + 1] = info->chars[2 % info->lenght_chars];
    info->array[4][i + 2] = info->chars[2 % info->lenght_chars];
    info->array[4][i + 3] = info->chars[2 % info->lenght_chars];
    info->array[4][i + 4] = info->chars[2 % info->lenght_chars];
}

void write_three(info_t *info, int i)
{
    info->array[0][i] = info->chars[3 % info->lenght_chars];
    info->array[0][i + 1] = info->chars[3 % info->lenght_chars];
    info->array[0][i + 2] = info->chars[3 % info->lenght_chars];
    info->array[0][i + 3] = info->chars[3 % info->lenght_chars];
    info->array[1][i + 4] = info->chars[3 % info->lenght_chars];
    info->array[2][i + 1] = info->chars[3 % info->lenght_chars];
    info->array[2][i + 2] = info->chars[3 % info->lenght_chars];
    info->array[2][i + 3] = info->chars[3 % info->lenght_chars];
    info->array[3][i + 4] = info->chars[3 % info->lenght_chars];
    info->array[4][i] = info->chars[3 % info->lenght_chars];
    info->array[4][i + 1] = info->chars[3 % info->lenght_chars];
    info->array[4][i + 2] = info->chars[3 % info->lenght_chars];
    info->array[4][i + 3] = info->chars[3 % info->lenght_chars];
}

void write_four(info_t *info, int i)
{
    info->array[0][i + 2] = info->chars[4 % info->lenght_chars];
    info->array[0][i + 3] = info->chars[4 % info->lenght_chars];
    info->array[1][i + 1] = info->chars[4 % info->lenght_chars];
    info->array[1][i + 3] = info->chars[4 % info->lenght_chars];
    info->array[2][i + 0] = info->chars[4 % info->lenght_chars];
    info->array[2][i + 3] = info->chars[4 % info->lenght_chars];
    info->array[3][i] = info->chars[4 % info->lenght_chars];
    info->array[3][i + 1] = info->chars[4 % info->lenght_chars];
    info->array[3][i + 2] = info->chars[4 % info->lenght_chars];
    info->array[3][i + 3] = info->chars[4 % info->lenght_chars];
    info->array[3][i + 4] = info->chars[4 % info->lenght_chars];
    info->array[4][i + 3] = info->chars[4 % info->lenght_chars];
}
