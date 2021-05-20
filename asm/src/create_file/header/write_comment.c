/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_comment
*/

#include "asm.h"

void write_comment(char **file_array, int cor_file, int comment_line)
{
    unsigned char comment[2052];
    int i = 0;
    int j = 0;

    if (comment_line != -1) {
        for ( ; file_array[comment_line][i] != '"'; i++);
        i++;
        for ( ; file_array[comment_line][i] != '"'; i++)
            comment[j++] = file_array[comment_line][i];
    }
    for ( ; j < 2052; j++)
        comment[j] = 0;
    write(cor_file, comment, 2052);
}