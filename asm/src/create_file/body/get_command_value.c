/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_command_value
*/

#include "asm.h"

int get_command_value(char *line)
{
    int label = get_info_label(line);
    char *command = get_command_str(line, label);

    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(command, op_tab[i].mnemonique) == 0)
            return (i);
        if (my_strcmp(command, ".name") == 0)
            return (100);
        if (my_strcmp(command, ".comment") == 0)
            return (200);
        if (my_strcmp(command, "") == 0)
            return (-2);
    }
    return (-1);
}