/*
** EPITECH PROJECT, 2020
** my_putchar_err
** File description:
** prints character in error channel
*/

#include "my.h"

void my_putchar_err(char c)
{
    write(2, &c, 1);
}