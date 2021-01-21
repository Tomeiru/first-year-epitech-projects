/*
** EPITECH PROJECT, 2020
** my_putstr_err
** File description:
** prints char array given as argument in error channel
*/

#include "my.h"

void my_putstr_err(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar_err(str[i]);
    return;
}