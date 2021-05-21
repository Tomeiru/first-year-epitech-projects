/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** size_and_or_for
*/

#include "asm.h"

unsigned int size_and_or_xor(char *line)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned char coding_byte = get_coding_byte(args);

    if (coding_byte == 0x54)
        return (5);
    if (coding_byte == 0xD4 || coding_byte == 0x74)
        return (6);
    if (coding_byte == 0xF4)
        return (7);
    if (coding_byte == 0x94 || coding_byte == 0x64)
        return (8);
    if (coding_byte == 0xB4 || coding_byte == 0xE4)
        return (9);
    return (11);
}