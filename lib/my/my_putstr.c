/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** my_putstr
*/

int my_putstr(char const *str)
{
    int l;

    while (str[l] != '\0') {
        my_putchar(str[l]);
        l = l + 1;
    }
}
