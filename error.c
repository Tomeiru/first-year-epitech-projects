/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-minishell1-mathieu.brujan
** File description:
** error
*/

#include "mysh.h"

void error(int ac, char **av)
{
    if (ac > 1) {
        write(1, av[0], 6);
        write(1, " doesn't need any argument\n", 27);
        exit(84);
    }
}