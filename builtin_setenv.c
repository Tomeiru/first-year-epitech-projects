/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** builtin_setenv
*/

#include "mysh.h"

int setenv_error(char **command, int i)
{
    if (i > 3) {
        write(1, "setenv: Too many arguments.\n", 28);
        return (84);
    }if (!((command[1][0] >= 'a' && command[1][0] <= 'z') ||
    (command[1][0] >= 'A' && command[1][0] <= 'Z'))) {
        write(1, "setenv: Variable name must begin with a letter.\n", 48);
        return (84);
    }if (is_alphanum(command[1]) == 0) {
        write(1,
        "setenv: Variable name must contain alphanumeric characters.\n", 60);
        return (84);
    }
    return (0);
}

char *get_newenv_str(char **command)
{
    char *str;
    int f = 0;

    if (command[2] != NULL) {
        str = malloc(sizeof(char) * (my_strlen(command[1]) +
        my_strlen(command[2]) + 2));
        for ( ; command[1][f]; f++)
            str[f] = command[1][f];
        str[f++] = '=';
        for (int h = 0; command[2][h]; h++)
            str[f++] = command[2][h];
    }else {
        str = malloc(sizeof(char) * (my_strlen(command[1]) + 2));
        for ( ; command[1][f]; f++)
            str[f] = command[1][f];
        str[f++] = '=';
    }str[f] = '\0';
    return (str);
}

char **get_newenv(int i, char **env, char **command)
{
    int nb_env = 0;
    char **new_env;

    for ( ; env[nb_env]; nb_env++);
    new_env = malloc(sizeof(char *) * (nb_env + 1));
    for (i = 0; env[i]; i++)
        new_env[i] = my_strdup(env[i]);
    new_env[i] = get_newenv_str(command);
    new_env[++i] = NULL;
    return (new_env);
}

int builtin_setenv(char **command, char **env)
{
    int i = 0;
    char **new_env;

    for ( ; command[i]; i++);
    if (setenv_error(command, i) == 84 && isatty(0) == 1)
        exit(-1);
    if (setenv_error(command, i) == 84)
        return (mysh(env, -1));
    if (i == 1)
        exit(builtin_env(env));
    new_env = get_newenv(i, env, command);
    if (isatty(0) == 1)
        return (mysh(new_env, 0));
    else
        exit(0);
}