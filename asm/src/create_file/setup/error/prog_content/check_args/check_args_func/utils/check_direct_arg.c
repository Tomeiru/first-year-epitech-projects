/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_direct_arg
*/

#include "asm.h"

int check_direct_arg(char *arg)
{
    int label_arg = 0;
    int ret = 0;

    if (arg[0] != '%')
        return (-2);
    label_arg = get_info_label(++arg);
    if (label_arg == 1) {
        ret = check_label_arg(arg);
        return (ret);
    }if (arg[0] == '\0')
        return (-2);
    if (*arg == '-')
        arg++;
    if (arg[0] == '\0')
        return (-2);
    for (int i = 0; arg[i]; i++) {
        if (!(arg[i] >= '0' && arg[i] <= '9'))
            return (-2);
    }return (0);
}