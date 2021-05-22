/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_args_line
*/

#include "asm.h"

int check_args_line(char *line, int command)
{
    int (* check_args_func[16])(char *) = {
        check_args_live_zjmp_fork_lfork, check_args_ld_lld, check_args_st,
        check_args_add_sub, check_args_add_sub, check_args_and_or_xor,
        check_args_and_or_xor, check_args_and_or_xor,
        check_args_live_zjmp_fork_lfork, check_args_ldi_lldi, check_args_sti,
        check_args_live_zjmp_fork_lfork, check_args_ld_lld,
        check_args_ldi_lldi, check_args_live_zjmp_fork_lfork,
        check_args_aff,
    };

    return (check_args_func[command](line));
}