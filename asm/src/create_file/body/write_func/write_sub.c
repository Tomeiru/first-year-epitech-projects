/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_add
*/

#include "asm.h"

void write_sub(char *line, int cor_file)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned char coding_byte = get_coding_byte(args);
    unsigned char sub_buffer[5];

    sub_buffer[0] = 5;
    sub_buffer[1] = coding_byte;
    sub_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    sub_buffer[3] = (unsigned char)my_getnbr(++args[1]);
    sub_buffer[4] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, sub_buffer, 5);
}
