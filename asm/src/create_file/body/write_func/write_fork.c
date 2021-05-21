/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_fork
*/

#include "asm.h"

void write_fork(char *line, int cor_file)
{
    unsigned char fork_buffer[3] = "000";
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned short fork_value = get_index_value(args[0]);

    fork_buffer[0] = 0x0c;
    for (int i = 2; i != 0; i--) {
        if (fork_value == 0) {
            fork_buffer[i] = 0;
            continue;
        }
        fork_buffer[i] = fork_value % 0x100;
        fork_value /= 0x100;
    }write(cor_file, fork_buffer, 3);
}