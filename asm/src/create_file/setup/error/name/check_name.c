/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_name
*/

#include "asm.h"

int error_name(char **file_array)
{
    int name_presence = check_name_presence(file_array);
    int check_syntax = check_syntax_name(file_array, name_presence);

    if (check_syntax < 0)
        return (check_error_code_name(check_syntax));
    return (name_presence);
}