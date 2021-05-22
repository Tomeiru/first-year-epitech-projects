/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_error_code
*/

#include "asm.h"

int check_error_code_comment(int error_code)
{
    if (error_code == -2)
        write(2, ".comment error: The comment of your program must \
be right after the name\n", 73);
    if (error_code == -3)
        write(2, ".comment error: Please verify your comment syntax\n", 50);
    if (error_code == -4)
        write(2, ".comment error: The comment specified is too long (2048 \
characters is the maximum)\n", 83);
    return (-84);
}