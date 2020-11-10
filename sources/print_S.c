/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** my_putstr
*/

#include "my_printf.h"

static void zero(char const *str)
{
    char *zero[2] = {
        "00", "0"
    };
    if (my_strlen(str) == 3)
        return;
    for (int i = 0; i < 2; i++)
        if (my_strlen(str) == i + 1) {
            my_putstr(zero[i]);
        }
    return;
}

void print_S(char const *str)
{
    char *val;

    for (int i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar(92);
            val = print_o(str[i]);
            zero(val);
            my_putstr(val);
        }
        else
            my_putchar(str[i]);
    }
}