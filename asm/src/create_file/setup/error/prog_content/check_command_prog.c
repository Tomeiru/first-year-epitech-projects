/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_command_prog
*/

#include "asm.h"

int check_error_code_command(int status, int line_error)
{
    write(2, "Line ", 5);
    my_put_nbr(line_error);
    if (status == -1)
        write(2, ": error: Name can only be defined once\n", 39);
    if (status == -2)
        write(2, ": error: Comment can only be defined once\n", 42);
    if (status == -3)
        write(2, ": error: Unknown command\n", 25);
    return (84);
}

int check_command_prog(char **file_array, int after_comment_line)
{
    int command = 0;
    int ret = 0;
    int i = after_comment_line;

    for ( ; file_array[i]; i++) {
        command = get_command_value(file_array[i]);
        if (command == 100) {
            ret = -1;
            break;
        }if (command == 200) {
            ret = -2;
            break;
        }if (command == -1) {
            ret = -3;
            break;
        }
    }if (ret == 0)
        return (0);
    return (check_error_code_command(ret, i + 1));
}