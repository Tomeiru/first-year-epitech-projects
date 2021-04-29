/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH args
*/

#include <stdlib.h>
#include "my.h"
#include "rpgsh/rpgsh.h"

char **split_into_args(char *line)
{
    char **args = NULL;
    int size = 0;
    char *start = line;
    int len = 0;

    for (char *c = line; *c; c++) {
        if (*c == ' ' || *c == '\t') {
            if (len > 0) {
                add_arg(&args, size, start, len);
                size++;
            }
            start = c + 1;
            len = 0;
        } else
            len++;
    }
    if (len > 0)
        add_arg(&args, size, start, len);
    return (args);
}

void add_arg(char ***args, int size, char *start, int len)
{
    char **newargs = malloc(sizeof(char*) * (size + 2));
    char *arg = malloc(sizeof(char) * (len + 1));

    if (!newargs || !arg)
        return;
    my_strncpy(arg, start, len);
    for (int i = 0; i < size; i++)
        newargs[i] = (*args)[i];
    newargs[size] = arg;
    newargs[size + 1] = NULL;
    if (*args)
        free(*args);
    *args = newargs;
}

void free_args(char **args)
{
    for (; *args; args++)
        free(*args);
}