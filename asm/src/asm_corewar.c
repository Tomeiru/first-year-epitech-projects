/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** asm_corewar
*/

#include "asm.h"

int asm_corewar(int ac, char **av)
{
    write(1, av[0], sizeof(av[0]));
    return (ac);
}