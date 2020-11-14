/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** unsint_printer
*/

#include "my_printf.h"

void arg_oct(unsigned long long number, char *flag)
{
    int len_mod = which_len_mod(flag);
    void (*ptr_oct[4])(unsigned long long, char *) = {
        noct, hoct, hhoct, lloct
    };

    for (int i = 0; i < 4; i++) {
        if (len_mod == i)
            ptr_oct[i](number, flag);
    }
}

void arg_hexa(unsigned long long number, char *flag)
{
    int len_mod = which_len_mod(flag);
    void (*ptr_hexa[4])(unsigned long long, char *) = {
        nhexa, hhexa, hhhexa, llhexa
    };

    for (int i = 0; i < 4; i++) {
        if (len_mod == i)
            ptr_hexa[i](number, flag);
    }
}

void arg_hexamaj(unsigned long long number, char *flag)
{
    int len_mod = which_len_mod(flag);
    void (*ptr_HEXA[4])(unsigned long long, char *) = {
        nhexamaj, hhexamaj, hhhexamaj, llhexamaj
    };

    for (int i = 0; i < 4; i++) {
        if (len_mod == i)
            ptr_HEXA[i](number, flag);
    }
}

void arg_uns(unsigned long long number, char *flag)
{
    int len_mod = which_len_mod(flag);
    void (*ptr_uns[4])(unsigned long long, char *) = {
        nuns, huns, hhuns, lluns
    };

    for (int i = 0; i < 4; i++) {
        if (len_mod == i)
            ptr_uns[i](number, flag);
    }
}

void arg_bin(unsigned long long number, char *flag)
{
    int len_mod = which_len_mod(flag);
    void (*ptr_bin[4])(unsigned long long, char *) = {
        nbin, hbin, hhbin, llbin
    };

    for (int i = 0; i < 4; i++) {
        if (len_mod == i)
            ptr_bin[i](number, flag);
    }
}