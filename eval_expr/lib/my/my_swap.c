/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** my_swap
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
