/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** size_ld
*/

#include "asm.h"

unsigned int size_ld_lld(char *line)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned char coding_byte = get_coding_byte(args);

    if (coding_byte == 0xD0)
        return (5);
    return (7);
}