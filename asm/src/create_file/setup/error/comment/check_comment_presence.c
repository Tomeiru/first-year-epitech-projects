/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_comment_presence
*/

#include "asm.h"

int check_comment_presence(char **file_array, int after_name_line)
{
    int command = 0;
    int other_command = 0;

    for (int i = after_name_line; file_array[i]; i++) {
        command = get_command_value(file_array[i]);
        if (command == 200 && other_command == 0)
            return (i);
        if (command == 200 && other_command == 1)
            return (-2);
        if (command == -2)
            continue;
        other_command = 1;
    }
    return (-1);
}