/*
** EPITECH PROJECT, 2020
** my_print_revalpha.c
** File description:
** Function displaying the lowercase alphabet in descending order
*/

int     my_print_revalpha(void)
{
    char c = 122;
    while (c > 96)
    {
        my_putchar(c);
        c--;
    }
}
