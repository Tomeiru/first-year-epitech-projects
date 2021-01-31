/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** builtin_unsetenv
*/

#include "mysh.h"

char **get_beforeequal(char **env, int nb_env)
{
    char **new_env = malloc(sizeof(char *) * (nb_env + 1));
    int f = 0;
    int a = 0;
    int count = 0;

    for (a = 0; env[a]; a++) {
        for (f = 0; env[a][f] != '='; f++)
            count++;
        new_env[a] = malloc(sizeof(char) * (count + 1));
    }for (a = 0; env[a]; a++) {
        for (f = 0; env[a][f] != '='; f++)
            new_env[a][f] = env[a][f];
        new_env[a][f] = '\0';
    }new_env[a] = NULL;
    return (new_env);
}

char **get_unsetenv(int nb_env, char **command, char **env, char **before_equal)
{
    char **new_env = malloc(sizeof(char *) * (nb_env + 1));
    int j = 0;
    int count = 0;
    int k = 0;

    for (count = 0; command[count]; count++);
    for (int i = 0; before_equal[i]; i++) {
        for (j = 0; command[j] != NULL && 
        my_strcmp(before_equal[i], command[j]) != 0; j++);
        if (j == count)
            new_env[k++] = my_strdup(env[i]);
    }
    new_env[k] = NULL;
    return (new_env);
}

void norm(char *be, char *com, int *nb_env)
{
    if (my_strcmp(be, com) == 0)
        *nb_env--;
}

int builtin_unsetenv(char **command, char **env)
{
    int nb_env = 0;
    int i = 0;
    char **before_equal;
    char **new_env;

    for ( ; command[i]; i++);
    if (i == 1 && isatty(0) == 1)
        return (mysh(env, -1));
    if (i == 1)
        exit (-1);
    for ( ; env[nb_env]; nb_env++);
    before_equal = get_beforeequal(env, nb_env);
    for (i = 1; command[i]; i++)
        for (int j = 0; before_equal[j]; j++)
            norm(before_equal[j], command[i], &nb_env);
    new_env = get_unsetenv(nb_env, command, env, before_equal);
    if (isatty(0) == 1)
        return (mysh(new_env, 0));
    else
        exit(0);
}