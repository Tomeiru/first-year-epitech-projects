/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** second_print_width
*/

#include "my_printf.h"

int len_cho(int length, char *width_mod, char *flag)
{
    int precision_value = 0;
    char *copy = my_strdup(flag);

    if (width_mod[3] == '0')
        return (length);
    for ( ; *copy != '.'; copy++);
    copy++;
    precision_value = my_getnbr(copy);
    copy = my_revstr(copy);
    if (copy[0] == 'd' || copy[0] == 'i' || copy[0] == 'o' || copy[0] == 'u' ||
    copy[0] == 'x' || copy[0] == 'X' || copy[0] == 'b')
        if (precision_value > length)
            return (precision_value);
    if (copy[0] == 's' || copy[0] == 'S')
        if (precision_value < length)
            return (precision_value);
    return (length);
}

void print_with_precision(char *width_mod, int length, char *print, char *flag)
{
    int precision_value = 0;
    char *copy = my_strdup(flag);

    if (width_mod[3] == '0')
        return (my_putstr(print));
    for ( ; *copy != '.'; copy++);
    copy++;
    precision_value = my_getnbr(copy);
    copy = my_revstr(copy);
    copy[0] == 'o' && width_mod[0] == '1' ? length++ : 0;
    if (copy[0] == 'd' || copy[0] == 'i' || copy[0] == 'o' || copy[0] == 'u' ||
    copy[0] == 'x' || copy[0] == 'X' || copy[0] == 'b') {
        for (int i = length; i < precision_value; i++)
            my_putchar('0');
        my_putstr(print);
    }
    if (copy[0] == 's' || copy[0] == 'S')
        for (int i = 0; i < precision_value && print[i] != '\0'; i++)
            my_putchar(print[i]);
    return;
}