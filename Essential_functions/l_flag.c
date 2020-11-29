/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** l_flag
*/

#include "my_ls.h"

void l_flag(char *flags, char *filepath)
{
    if (flags[4] == '1')
        if (flags[3] == '1') {
            my_printf("No -ltr gestion for the moment\n");
            exit(84);
        }else {
            my_printf("No -lt gestion for the moment\n");
            exit(84);
        }
    else if (flags[3] == '1')
            dash_l_reverse(filepath);
        else
            dash_l(filepath);
}