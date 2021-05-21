/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** size_st
*/

#include "asm.h"

unsigned int size_st(char *line)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned char coding_byte = get_coding_byte(args);

    if (coding_byte == 0x70)
        return (5);
    return (4);
}