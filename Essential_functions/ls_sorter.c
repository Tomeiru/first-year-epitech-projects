/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** ls_no_path
*/

#include "my_ls.h"

void ls_sorter(char *flags, char *filepath)
{
    if (flags[2] == '1')
        d_flag(flags, filepath);
    if (flags[1] == '1')
        capr_flag(flags, filepath);
    if (flags[0] == '1')
        l_flag(flags, filepath);
    if (flags[4] == '1')
        if (flags[3] == '1') {
            my_printf("No -tr gestion for the moment\n");
            exit(84);
        }else {
            my_printf("No -t gestion for the moment\n");
            exit(84);
        }
    if (flags[3] == '1') {
        simple_reverse();
        exit(EXIT_SUCCESS);
    }
}