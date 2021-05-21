/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_info_label
*/

#include "asm.h"

int get_info_label(char *line)
{
    int idx = 0;
    int label = 0;

    for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
    for ( ; line[idx] != ' ' && line[idx] != 9 && line[idx] != '\0'; idx++)
        if (line[idx] == ':')
            label = 1;
    return (label);
}