/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** swaps contents of two integers
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int c;

    c = *b;
    *b = *a;
    *a = c;
    return;
}
