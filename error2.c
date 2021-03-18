/*
** EPITECH PROJECT, 2021
** duo_stumper2
** File description:
** main
*/

#include "stumper.h"
#include <stdlib.h>

int check_nb_arg(int ac)
{
    if (ac > 11)
        exit(84);
    if (ac % 2 != 1)
        exit(84);
    return (0);
}

int which_param(char *str)
{
    if (strcmp(str, "-w") == 0)
        return (0);
    if (strcmp(str, "-h") == 0)
        return (1);
    if (strcmp(str, "-p1") == 0)
        return (2);
    if (strcmp(str, "-p2") == 0)
        return (3);
    if (strcmp(str, "-a") == 0)
        return (4);
    exit(84);
}

char *create_flags(void)
{
    char *flags = malloc(sizeof(char) * (6));

    for (int i = 0; i < 5; i++)
        flags[i] = '0';
    flags[5] = '\0';
    return (flags);
}
