/*
** EPITECH PROJECT, 2020
** second_print
** File description:
** second_print
*/

#include <unistd.h>
#include "rush.h"

void second_print(int j)
{
    if (j > 1)
        my_putstr(" || ");
    if (j == 1)
        my_putchar('\n');
}