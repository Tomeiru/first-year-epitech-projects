/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_comment
*/

#include "asm.h"

int error_comment(char **file_array, int line_name)
{
    int comment_presence = 0;
    int check_syntax = 0;

    if (line_name == 84)
        return (line_name);
    comment_presence = check_comment_presence(file_array, line_name + 1);
    check_syntax = check_syntax_comment(file_array, comment_presence);
    if (check_syntax < -1)
        return (check_error_code_comment(check_syntax));
    if (check_syntax == -1) {
        write(2, ".comment warning: No comment specified.\n", 40);
        return (line_name);
    }
    return (comment_presence);
}