/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** builtin
*/

#include "mysh.h"

int builtin(char **command, char **env)
{
    if (my_strcmp("/bin/exit", command[0]) == 0)
        return (builtin_exit(command, env));
    if (my_strcmp("/bin/env", command[0]) == 0)
        return (builtin_env(env));
    if (my_strcmp("/bin/setenv", command[0]) == 0)
        return (builtin_setenv(command, env));
    if (my_strcmp("/bin/unsetenv", command[0]) == 0)
        return (builtin_unsetenv(command, env));
    if (my_strcmp("/bin/cd", command[0]) == 0)
        return (builtin_cd(command, env));
}

int is_it_builtin(char *command)
{
    if (my_strcmp("/bin/exit", command) == 0 ||
    my_strcmp("/bin/env", command) == 0 ||
    my_strcmp("/bin/setenv", command) == 0 ||
    my_strcmp("/bin/unsetenv", command) == 0 ||
    my_strcmp("/bin/cd", command) == 0)
        return (1);
    return (0);
}