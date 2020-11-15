/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** my_putstr
*/

#include "my_printf.h"

static char *zero(char *str)
{
    char *new_str = my_strdup(str);

    if (my_strlen(str) == 3)
        return (str);
    else {
        if (my_strlen(str) == 2) {
            new_str = my_revstr(new_str);
            new_str[2] = '0';
            return (my_revstr(new_str));
        }
        if (my_strlen(str) == 1) {
            new_str[1] = '0';
            new_str[2] = '0';
            return (my_revstr(new_str));
        }
    }
    return ("0");
}

static char *create_alt_string(char const *str)
{
    char *new_string;
    char *val;
    int count = 0;
    int j = 0;

    for (int i = 0; str[i]; i++)
        (str[i] < 32 || str[i] >= 127) ? count++ : 0;
    new_string = malloc(sizeof(char) * (my_strlen(str) + count * 3));
    for (int i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            new_string[j++] = 92;
            val = zero(print_o(str[i]));
            new_string[j++] = val[0];
            new_string[j++] = val[1];
            new_string[j++] = val[2];
        }
        else
            new_string[j++] = str[i];
    }
    return (new_string);
}

void print_alt_string(char *str, char *flag)
{
    char *alt_string = create_alt_string(str);
    char *width_modifier = width_check(flag);
    int length = my_strlen(alt_string);

    print_width(width_modifier, length, alt_string, flag);
}

void print_str(char *str, char *flag)
{
    char *width_modifier = width_check(flag);
    int length = my_strlen(str);

    print_width(width_modifier, length, str, flag);
}