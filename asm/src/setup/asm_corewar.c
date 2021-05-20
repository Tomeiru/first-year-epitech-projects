/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** asm_corewar
*/

#include "asm.h"

static int help(void)
{
    write(1, "USAGE\n./asm file_name[.s]\nDESCRIPTION\nfile_name file in assem\
bly language to be converted into file_name.cor, an executable in the Virt\
ual Machine.\n", 148);
    return (84);
}

int asm_corewar(int ac, char **av)
{
    info_t *info;

    if (ac == 1 || (ac == 2 && my_strcmp("-h", av[1]) == 0))
        return (help());
    info = fill_info_struct(ac, av);
    for (int i = 0; i < ac - 1; i++) {
        if (my_strcmp(info->files[i][0], "!") == 0)
            info->return_value = 84;
        else
            asm_file(info, i);
    }
    return (info->return_value);
}