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

void arg_ptr(unsigned long long number, char *flag)
{
    char *nb = print_x(number);
    char *width_modifier = width_check(flag);
    int length = my_strlen(nb);

    width_modifier[0] = '1';
    print_width(width_modifier, length, nb, flag);
}

void arg_int(char *flag, long long number)
{
    int len_mod = 0;
    void (*ptr_integer[4])(long long, char *) = {
        nint, hint, hhint, llint,
    };

    if (flag[0] == 'c') {
        char_print(number, flag);
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
    char *conv_spe = "oxXubp";
    void (*ptr_uns_integer[6])(unsigned long long, char *) = {
        arg_oct, arg_hexa, arg_hexamaj, arg_uns, arg_bin, arg_ptr
    };

    for (int i = 0; i < 7; i++) {
        if (flag[0] == conv_spe[i])
            ptr_uns_integer[i](number, flag);
    }
}

void arg_str(char *flag, char *str)
{
    char *conv_spe = "sS";
    void (*ptr_str[2])(char *, char *) = {
        print_str, print_alt_string
    };

    for (int i = 0; i < 6; i++) {
        if (flag[0] == conv_spe[i])
            ptr_str[i](str, flag);
    }
}