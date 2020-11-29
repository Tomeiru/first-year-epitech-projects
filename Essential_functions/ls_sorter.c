/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** ls_no_path
*/

#include "my_ls.h"

void ls_single_file(char *flags, char *filepath)
{
    char *statmode = stat_mode_to_str(filepath);
    char *typeperm = stat_mode_to_typeperm_str(statmode);

    if (typeperm[0] == 'd')
        ls_sorter(flags, filepath);
    else if (typeperm[0] == '-')
        ls_sorter_file(flags, filepath);
    else
        exit(84);
}

void ls_multi_file(char *flags, char *filepath, int i)
{
    char *statmode = stat_mode_to_str(filepath);
    char *typeperm = stat_mode_to_typeperm_str(statmode);

    if (i != 1)
        my_putchar('\n');
    if (typeperm[0] == 'd') {
        if (flags[1] != '1')
            my_printf("%s:\n", slash_cut(filepath));
        ls_sorter(flags, filepath);
    }
    else if (typeperm[0] == '-')
            ls_sorter_file(flags, filepath);
    else
        exit(84);
}

void ls_type(char *flags, char *filepath, int path_counter, int i)
{
    if (path_counter < 2)
        ls_single_file(flags, filepath);
    else
        ls_multi_file(flags, filepath, i);
}

void ls_sorter_file(char *flags, char *filepath)
{
    if (flags[0] == '1')
        single_l(filepath);
    else
        my_printf("%s\n", filepath);
}

void ls_sorter(char *flags, char *filepath)
{
    if (my_strcmp(flags, "00000") == 0)
        no_arguments(filepath);
    if (flags[2] == '1')
        d_flag(flags, filepath);
    if (flags[1] == '1' && flags[2] != '1')
        capr_flag(flags, filepath);
    if (flags[0] == '1' && flags[2] != '1'  && flags[1] != '1')
        l_flag(flags, filepath);
    if (flags[4] == '1' && flags[0] != '1' && flags[2] != '1' &&
    flags[1] != '1')
        if (flags[3] == '1') {
            my_printf("No -tr gestion for the moment\n");
            exit(84);
        }else {
            my_printf("No -t gestion for the moment\n");
            exit(84);
        }
    if (flags[3] == '1' && flags[4] != '1' && flags[0] != '1' &&
    flags[2] != '1'  && flags[1] != '1')
        simple_reverse();
}