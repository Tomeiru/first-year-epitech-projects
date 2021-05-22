/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_prog
*/

#include "asm.h"

int error_prog(char **file_array, int comment_line)
{
    int check_command = 0;
    int check_args = 0;

    if (comment_line == -84)
        return (-comment_line);
    check_command = check_command_prog(file_array, comment_line + 1);
    check_args = check_args_prog(file_array, comment_line + 1, check_command);
    return (check_args);
}
