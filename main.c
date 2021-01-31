/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-minishell1-mathieu.brujan
** File description:
** main
*/

#include "mysh.h"


int is_alphanum(char *str)
{
    for (int i = 0; str[i]; i++)
        if (!((str[i] >= '0' && str[i] <= '9') ||
        (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
            return (0);
    return (1);
}

int main(int ac, char **av, char **env)
{
    error(ac, av);
    return (mysh(env, 0));
}