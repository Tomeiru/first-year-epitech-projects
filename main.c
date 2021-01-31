/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-minishell1-mathieu.brujan
** File description:
** main
*/

#include "mysh.h"

int main(int ac, char **av, char **env)
{
    error(ac, av);
    return (mysh(env, 0));
}