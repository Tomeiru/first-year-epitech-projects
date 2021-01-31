/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** builtin_cd
*/

#include "mysh.h"

void cd_home(char **env)
{
    char *path = malloc(sizeof(char) * (2 + (my_strlen(env[39]))));
    int i = 0;

    path[i++] = '/';
    path[i++] = 'h';
    path[i++] = 'o';
    path[i++] = 'm';
    path[i++] = 'e';
    path[i++] = '/';
    for (int j = 5; env[39][j]; j++)
        path[i++] = env[39][j];
    path[i] = '\0';
    chdir(path);
}

int cd_path(char **command, char **env)
{
    int return_val = 0;
    int status;

    if (fork() == 0)
        exit(execve(command[0], command, env));
    waitpid(0, &status, 0);
    return_val = WEXITSTATUS(status);
    if (return_val == 0)
        chdir(command[1]);
    return (return_val);
}

int builtin_cd(char **command, char **env)
{
    int i = 0;
    int return_value = 0;

    for ( ; command[i]; i++);
    if (i > 2 && isatty(0) == 1) {
        return (mysh(env, -1));
    if (i > 2)
        exit(-1);
    }if (i == 1 && isatty(0) == 1) {
        cd_home(env);
        return (mysh(env, 0));
    }if (i == 1) {
        cd_home(env);
        exit(0);
    }return_value = cd_path(command, env);
    if (isatty(0) == 1)
        return (mysh(env, return_value));
    else
        exit(return_value);
}