/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** builtin_env
*/

#include "mysh.h"

int builtin_exit(char **command, char **env)
{
    int i = 0;

    for ( ; command[i]; i++);
    if ((i > 2) || (i == 2 && is_number(command[1]) == 0)) {
        write(1, "exit: Expression Syntax.\n", 25);
        return (mysh(env, 1));
    }write(1, "exit\n", 5);
    if (i == 1)
        exit(0);
    else
        exit(my_getnbr(command[1]));
}

int builtin_env(char **env)
{
    for (int i = 0; env[i]; i++) {
        write(1, env[i], my_strlen(env[i]));
        write(1, "\n", 1);
    }return (mysh(env, 0));
}