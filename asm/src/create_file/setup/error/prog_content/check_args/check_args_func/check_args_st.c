/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_args_st
*/

#include "asm.h"

int check_args_st(char *line)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    int nb_arg = count_arg(args);
    int ret = 0;

    if (nb_arg != 2)
        return (-1);
    ret = check_register_arg(args[0]);
    if (ret != 0)
        return (ret);
    ret = check_indirect_arg(args[1]);
    if (ret != 0)
        ret = check_register_arg(args[1]);
    return (ret);
}