/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** Function diplaying the lowercase alphabet in ascending order
*/

int my_print_alpha(void)
{
    char c = 97;
    while (c < 123) {
        my_putchar(c);
        c++;
    }
}
