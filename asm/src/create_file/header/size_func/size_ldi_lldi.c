/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** size_ldi_lldi
*/

#include "asm.h"

unsigned int size_ldi_lldi(char *line)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned char coding_byte = get_coding_byte(args);

    if (coding_byte == 0xa4 || coding_byte == 0xe4)
        return (7);
    if (coding_byte == 0x54)
        return (5);
    return (6);
}