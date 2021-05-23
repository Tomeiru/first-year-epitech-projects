/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** size_sti
*/

#include "asm.h"

unsigned int size_sti(char *line)
{
    char **args = get_args_arr(line, get_info_label(line));
    int coding_byte = get_coding_byte(args);

    if (coding_byte == 0x68 || coding_byte == 0x78)
        return (7);
    if (coding_byte == 0x58 || coding_byte == 0x64 || coding_byte == 0x74)
        return (6);
    return (5);
}