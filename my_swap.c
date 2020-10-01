/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** Function that swaps the content of two integers
*/

void my_swap(int *a, int *b)
{
    int *c;
    int d;
    
    d = b;
    c = &b;
    *c = a;
    a = d;
}
