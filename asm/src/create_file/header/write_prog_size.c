/*
** EPITECH PROJECT, 2021
** Corewar_First
** File description:
** write_prog_size
*/

#include "asm.h"

static int get_comment_line(char **file_array, int name_line)
{
    int i = name_line + 1;
    int j = 0;

    for ( ; file_array[i]; i++) {
        for ( ; file_array[i][j] == ' ' || file_array[i][j] == 9; j++);
        if (file_array[i][j] == COMMENT_CHAR)
            continue;
        if (file_array[i][j] == '.')
            return (i);
        else if (file_array[i][j] != '.')
            return (-1);
    }return (-1);
}

static unsigned long long get_prog_size(void)
{
    return (0x0000000ffffffabc);
}

int write_prog_size(char **file_array, int cor_file, int name_line)
{
    int comment_line = get_comment_line(file_array, name_line);
    unsigned long long prog_size = get_prog_size();
    unsigned char prog_size_char[8];

    for (int i = 7; i != -1; i--) {
        if (prog_size == 0) {
            prog_size_char[i] = 0;
            continue;
        }
        prog_size_char[i] = prog_size % 0x100;
        prog_size /= 0x100;
    }
    write(cor_file, prog_size_char, 8);
    return (comment_line);
}