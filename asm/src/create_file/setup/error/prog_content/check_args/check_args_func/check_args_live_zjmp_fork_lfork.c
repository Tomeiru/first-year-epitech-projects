/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_args_live
*/

#include "asm.h"

int check_args_live_zjmp_fork_lfork(char *line)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    int nb_arg = count_arg(args);

    if (nb_arg != 1)
        return (-1);
    return (check_direct_arg(args[0]));
}