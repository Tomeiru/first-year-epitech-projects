/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** capr_flag
*/

#include "my_ls.h"

void caprtr_flag(char *flags)
{
    if (flags[0] == '1') {
        my_printf("No -Rtrl gestion for the moment\n");
        exit(84);
    } else {
        my_printf("No -Rtr gestion for the moment\n");
        exit(84);
    }
}

void caprtnor_flag(char *flags)
{
    if (flags[0] == '1') {
        my_printf("No -Rtl gestion for the moment\n");
        exit(84);
    } else {
        my_printf("No -Rt gestion for the moment\n");
        exit(84);
    }
}

void caprnotr_flag(char *flags, char *filepath)
{
    if (flags[0] == '1')
        caps_rrl_gestion(filepath);
    else
        caps_rr_gestion(filepath);
}

void caprnotnor_flag(char *flags, char *filepath)
{
    if (flags[0] == '1')
        caps_rl_gestion(filepath);
    else
        caps_r_gestion(filepath);
}

void capr_flag(char *flags, char *filepath)
{
    if (flags[4] == '1')
        if (flags[3] == '1')
            caprtr_flag(flags);
        else
            caprtnor_flag(flags);
    else if (flags[3] == '1')
            caprnotr_flag(flags, filepath);
        else
            caprnotnor_flag(flags, filepath);

}