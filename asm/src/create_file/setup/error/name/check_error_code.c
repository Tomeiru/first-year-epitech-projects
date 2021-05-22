/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_error_code
*/

#include "asm.h"

int check_error_code_name(int error_code)
{
    if (error_code == -1)
        write(2, ".name error: Your program must have a name\n", 43);
    if (error_code == -2)
        write(2, ".name error: The name of your program must \
be the first command\n", 64);
    if (error_code == -3)
        write(2, ".name error: Please verify your name syntax\n", 44);
    if (error_code == -4)
        write(2, ".name error: The name specified is too long (128 \
characters is the maximum)\n", 76);
    return (-84);
}