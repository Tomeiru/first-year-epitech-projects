/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_fork
*/

#include "asm.h"

void write_lfork(char *line, int cor_file)
{
    unsigned char lfork_buffer[3] = "000";
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned short lfork_value = get_index_value(args[0]);

    lfork_buffer[0] = 0x0f;
    for (int i = 2; i != 0; i--) {
        if (lfork_value == 0) {
            lfork_buffer[i] = 0;
            continue;
        }
        lfork_buffer[i] = lfork_value % 0x100;
        lfork_value /= 0x100;
    }write(cor_file, lfork_buffer, 3);
}