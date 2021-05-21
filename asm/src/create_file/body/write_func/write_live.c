/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_live
*/

#include "asm.h"

void write_live(char *line, int cor_file)
{
    unsigned char live_buffer[5] = "00000";
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned int live_value = get_direct_value(args[0]);

    live_buffer[0] = 0x01;
    for (int i = 4; i != 0; i--) {
        if (live_value == 0) {
            live_buffer[i] = 0;
            continue;
        }
        live_buffer[i] = live_value % 0x100;
        live_value /= 0x100;
    }write(cor_file, live_buffer, 5);
}