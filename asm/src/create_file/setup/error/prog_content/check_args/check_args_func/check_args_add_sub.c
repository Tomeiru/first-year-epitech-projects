/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_args_add
*/

#include "asm.h"

int check_args_add_sub(char *line)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    int nb_arg = count_arg(args);
    int ret = 0;

    if (nb_arg != 3)
        return (-1);
    ret = check_register_arg(args[0]);
    if (ret != 0)
        return (ret);
    ret = check_register_arg(args[1]);
    if (ret != 0)
        return (ret);
    return (check_register_arg(args[2]));
}