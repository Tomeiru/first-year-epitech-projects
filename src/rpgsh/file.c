/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH file
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "rpgsh/rpgsh.h"

char **open_rpgsh_file(char *filename)
{
    char **lines = NULL;
    int size = 0;
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t n = 0;
    ssize_t len = 0;

    if (!file)
        return (NULL);
    while ((len = getline(&line, &n, file)) > -1) {
        if (line[len - 1] == '\n')
            line[len - 1] = 0;
        add_line(&lines, line, size);
        size++;
        line = NULL;
        n = 0;
    }
    return (lines);
}

void add_line(char ***lines, char *line, int size)
{
    char **newlines = malloc(sizeof(char*) * (size + 2));

    if (!newlines)
        return;
    for (int i = 0; i < size; i++)
        newlines[i] = (*lines)[i];
    newlines[size] = line;
    newlines[size + 1] = NULL;
    if (*lines)
        free(*lines);
    *lines = newlines;
}