/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_prog_size
*/

#include "asm.h"

static unsigned int command_size(char *line, int command)
{
    unsigned int (* size_func[16])(char *) = {
        size_five, size_ld_lld, size_st, size_five, size_five,
        size_and_or_xor, size_and_or_xor, size_and_or_xor,
        size_three, size_ldi_lldi, size_sti, size_three, size_ld_lld,
        size_ldi_lldi, size_three, size_three,
    };

    return (size_func[command](line));
}

unsigned long long get_prog_size(char **file_array, int body_line)
{
    int command = 0;
    unsigned long long prog_size = 0;

    for (int i = body_line; file_array[i]; i++) {
        command = get_command_value(file_array[i]);
        if (command >= 0) 
            prog_size += command_size(file_array[i], command);
    }return (prog_size);
}