/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** fill_info_struct
*/

#include "asm.h"

void create_cor_file(char **file_array, char *filename)
{
    char *filename_cor = filename_to_filename_cor(filename);
    int cor_file = open(filename_cor, O_WRONLY | O_CREAT, 0644);
    int comment_line = write_header(file_array, cor_file);

    //write_body(file_array, cor_file, comment_line + 1);
}