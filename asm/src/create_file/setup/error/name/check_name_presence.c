/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_name_presence
*/

#include "asm.h"

int check_name_presence(char **file_array)
{
    int command = 0;
    int other_command = 0;

    for (int i = 0; file_array[i]; i++) {
        command = get_command_value(file_array[i]);
        if (command == 100 && other_command == 0)
            return (i);
        if (command == 100 && other_command == 1)
            return (-2);
        if (command == -2)
            continue;
        other_command = 1;
    }
    return (-1);
}