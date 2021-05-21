/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_body
*/

#include "asm.h"

void write_body(char **file_array, int cor_file, int body_line)
{
    int command = 0;

    for (int i = body_line; file_array[i]; i++) {
        command = get_command_value(file_array[i]);
        if (command < 0 || command != 100 || command != 200)
            write_command(file_array[i], cor_file, command);
    }
}
