/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** d_flag
*/

#include "my_ls.h"

void d_flag(char *flags, char *filepath)
{
    if (flags[0] == '1') {
        single_l(filepath);
        exit(EXIT_SUCCESS);
    }else {
        my_printf("%s\n", filepath);
        exit(EXIT_SUCCESS);
    }
}