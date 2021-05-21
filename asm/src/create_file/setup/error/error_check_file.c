/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** error_check_file
*/

#include "asm.h"

int error_check_file(char **file_array)
{
    int check_name = error_name(file_array);
    exit (check_name);
}