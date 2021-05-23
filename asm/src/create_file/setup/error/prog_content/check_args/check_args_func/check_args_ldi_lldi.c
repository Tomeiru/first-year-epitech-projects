/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_args_ldi_lldi
*/

#include "asm.h"

static int check_first_arg(char *arg)
{
    int ret = 0;

    ret = check_direct_arg(arg);
    if (ret != 0)
        ret = check_indirect_arg(arg);
    if (ret != 0)
        ret = check_register_arg(arg);
    return (ret);
}

int check_args_ldi_lldi(char *line)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    int nb_arg = count_arg(args);
    int ret = 0;

    if (nb_arg != 3)
        return (-1);
    ret = check_first_arg(args[0]);
    if (ret != 0)
        return (ret);
    ret = check_direct_arg(args[1]);
    if (ret != 0)
        ret = check_register_arg(args[1]);
    if (ret != 0)
        return (ret);
    return (check_register_arg(args[2]));
}