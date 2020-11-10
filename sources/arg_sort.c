/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** arg_sort
*/

#include "my_printf.h"

int which_len_mod(char *flag)
{
    int h_count = 0;
    int l_count = 0;

    for (int i = 0; flag[i]; i++) {
        if (flag[i] == 'h')
            h_count++;
        if (flag[i] == 'l')
            l_count++;
    }
    if (h_count == 0 && l_count == 0)
        return (0);
    if (h_count > 0)
        return (h_count);
    else
        return (3);
}

void arg_int(char *flag, long long number)
{
    int len_mod = 0;
    void (*ptr_integer[4])(long long, char *) = {
        nint, hint, hhint, llint
    };

    if (flag[0] == 'c') {
        my_putchar(number);
        return;
    }
    len_mod = which_len_mod(flag);
    for (int i = 0; i < 4; i++) {
        if (len_mod == i)
            ptr_integer[i](number, flag);
    }
}

void arg_uns_int(char *flag, unsigned long long number)
{
    char *conv_spe = "oxXub";
    void (*ptr_uns_integer[5])(unsigned long long, char *) = {
        arg_oct, arg_hexa, arg_HEXA, arg_uns, arg_bin
    };

    for (int i = 0; i < 6; i++) {
        if (flag[0] == conv_spe[i])
            ptr_uns_integer[i](number, flag);
    }
}

void arg_str(char *flag, char *str)
{
    char *conv_spe = "sS";
    void (*ptr_str[2])(const char *) = {
        my_putstr, print_S
    };

    for (int i = 0; i < 6; i++) {
        if (my_revstr(flag)[0] == conv_spe[i])
            ptr_str[i](str);
    }
}