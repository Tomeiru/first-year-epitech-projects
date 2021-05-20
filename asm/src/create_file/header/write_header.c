/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_header
*/

#include "asm.h"

int write_header(char **file_array, int cor_file)
{
    int name_line = 0;
    int comment_line = 0;

    write_magic_number(cor_file);
    name_line = write_name(file_array, cor_file);
    comment_line = write_prog_size(file_array, cor_file, name_line);
    write_comment(file_array, cor_file, comment_line);
    return (comment_line);
}