/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_args_str
*/

#include "asm.h"

static int get_args_nb(char *line, int label)
{
    int idx = 0;
    int ret = 1;

    for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
    for ( ; line[idx] != ' ' && line[idx] != 9 && line[idx] != '\0'; idx++);
    if (label == 1) {
        for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
        for ( ; line[idx] != ' ' && line[idx] != 9 && line[idx] != '\0'; idx++);
    }
    for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
    for ( ; line[idx] != '\0'; idx++)
        if (line[idx] == ',')
            ret++;
    return (ret);
}

char **get_args_arr(char *line, int label)
{
    int nb = get_args_nb(line, label);
    char **args = malloc(sizeof(char *) * (nb + 1));

    for (int i = 0; i < nb; i++)
        args[i] = get_arg_str(line, label, i);
    args[nb] = NULL;
    return (args);
}