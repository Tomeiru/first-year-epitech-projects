/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-mathieu.brujan
** File description:
** my_swap
*/

#include "navy.h"

void my_swap(int* a, int* b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}