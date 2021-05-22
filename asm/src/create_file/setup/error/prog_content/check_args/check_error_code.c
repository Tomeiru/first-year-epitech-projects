/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_error_status
*/

#include "asm.h"

int check_error_code_args(int status)
{
    if (status == -1)
        write(2, ": error: Wrong number of argument\n", 34);
    if (status == -2)
        write(2, ": error: Wrong argument syntax\n", 32);
    if (status == -3)
        write(2, ": error: Wrong label syntax\n", 32);
    return (84);
}