/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_aff
*/

#include "asm.h"

void write_aff(char *line, int cor_file)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned char coding_byte = get_coding_byte(args);
    unsigned char aff_buffer[3];

    aff_buffer[0] = 0x10;
    aff_buffer[1] = coding_byte;
    aff_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    write(cor_file, aff_buffer, 3);
}
