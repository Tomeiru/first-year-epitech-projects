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
    }
    return (-1);
}