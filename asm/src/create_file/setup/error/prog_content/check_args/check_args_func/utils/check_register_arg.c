/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_register
*/

#include "asm.h"

int check_register_arg(char *arg)
{
    if (arg[0] != 'r')
        return (-2);
    arg++;
    if (arg[0] == '\0')
        return (-2);
    for (int i = 0; arg[i]; i++) {
        if (!(arg[i] >= '0' && arg[i] <= '9'))
            return (-2);
    }if (my_strlen(arg) > 2 || my_getnbr(arg) > 16)
        return (-2);
    return (0);
}