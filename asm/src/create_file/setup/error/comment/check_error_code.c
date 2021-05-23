/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_error_code
*/

#include "asm.h"

int check_error_code_comment(int error_code)
{
    if (error_code == -2) {
        write(2, ".comment error: The comment of your program must ", 49);
        write(2, "be right after the name\n", 24);
    }
    if (error_code == -3)
        write(2, ".comment error: Please verify your comment syntax\n", 50);
    if (error_code == -4) {
        write(2, ".comment error: The comment specified is too long (2048", 55);
        write(2, " characters is the maximum)\n", 28);
    }
    return (-84);
}