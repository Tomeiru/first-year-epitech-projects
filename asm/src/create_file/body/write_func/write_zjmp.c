/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_zjmp
*/

#include "asm.h"

void write_zjmp(char *line, int cor_file)
{
    unsigned char zjmp_buffer[3] = "000";
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned short zjmp_value = get_index_value(args[0]);

    zjmp_buffer[0] = 0x09;
    for (int i = 2; i != 0; i--) {
        if (zjmp_value == 0) {
            zjmp_buffer[i] = 0;
            continue;
        }
        zjmp_buffer[i] = zjmp_value % 0x100;
        zjmp_value /= 0x100;
    }write(cor_file, zjmp_buffer, 3);
}