/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_value
*/

#include "asm.h"

unsigned short get_indirect_value(char *arg)
{
    for (int i = 0; arg[i]; i++)
        if (arg[i] == ':')
            return (0);
    return ((unsigned short) my_getnbr(arg));
}

unsigned int get_direct_value(char *arg)
{
    for (int i = 0; arg[i]; i++)
        if (arg[i] == ':')
            return (0);
    return ((unsigned int) my_getnbr(++arg));
}

unsigned short get_index_value(char *arg)
{
    for (int i = 0; arg[i]; i++)
        if (arg[i] == ':')
            return (0);
    return ((unsigned short) my_getnbr(++arg));
}