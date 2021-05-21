/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_command
*/

#include "asm.h"

void write_command(char *line, int cor_file, int command)
{
    void (* write_func[16])(char *, int) = {
        write_live, write_ld, write_st, write_add, write_sub,
        write_and, write_or, write_xor, write_zjmp, write_ldi,
        write_sti, write_fork, write_lld, write_lldi, write_lfork,
        write_aff,
    };

    write_func[command](line, cor_file);
}