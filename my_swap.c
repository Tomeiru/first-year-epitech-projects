/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** Function that swaps the content of two integers
*/

void my_swap(int *a, int *b)
{
    int z;

    z = *a;
    *a = *b;
    *b = z;
}
