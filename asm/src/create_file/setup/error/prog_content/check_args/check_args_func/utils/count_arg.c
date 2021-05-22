/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** count_arg
*/

#include "asm.h"

int count_arg(char **arg)
{
    int ret = 0;

    for (int i = 0; arg[i]; i++)
        ret++;
    return (ret);
}