/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_args_prog
*/

#include "asm.h"

int check_args_prog(char **file_array, int after_comment_line,
int status_command)
{
    int command = 0;
    int line_error = 0;
    int status = 0;

    if (status_command == 84)
        return (status_command);
    for (int i = after_comment_line; file_array[i]; i++) {
        command = get_command_value(file_array[i]);
        if (command != -2)
            status = check_args_line(file_array[i], command);
        if (status != 0) {
            line_error = i + 1;
            break;
        }
    }
    if (status == 0)
        return (0);
    write(2, "Line ", 5);
    my_put_nbr(line_error);
    return (check_error_code_args(status));
}