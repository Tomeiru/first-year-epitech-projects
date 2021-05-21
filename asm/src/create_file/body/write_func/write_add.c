/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_sub
*/

#include "asm.h"

void write_add(char *line, int cor_file)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned char coding_byte = get_coding_byte(args);
    unsigned char add_buffer[5];

    add_buffer[0] = 4;
    add_buffer[1] = coding_byte;
    add_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    add_buffer[3] = (unsigned char)my_getnbr(++args[1]);
    add_buffer[4] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, add_buffer, 5);
}