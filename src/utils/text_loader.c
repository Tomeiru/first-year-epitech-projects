/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** text loader
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

void add_line_to_array(char ***array, char **line, int *size)
{
    char **new = malloc(sizeof(char*) * (*size + 2));

    if (!new)
        return;
    for (int i = 0; i < *size; i++)
        new[i] = *array[i];
    new[*size] = *line;
    new[*size + 1] = NULL;
    if (*array)
        free(*array);
    *array = new;
    *size += 1;
    *line = NULL;
}

void add_buf_to_line(char **line, char *buf)
{
    char *new = NULL;

    if (!*line)
        *line = my_strdup(buf + 1);
    else {
        new = my_strmerge(*line, buf);
        free(*line);
        *line = new;
    }
}

char **load_text(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char **array = NULL;
    char *line = NULL;
    char *buf = NULL;
    size_t n = 0;
    int size = 0;

    if (!file)
        return (NULL);
    while (getline(&buf, &n, file) > 0) {
        if (buf[0] == '*' && line != NULL)
            add_line_to_array(&array, &line, &size);
        add_buf_to_line(&line, buf);
        free(buf);
        buf = NULL;
    }
    add_line_to_array(&array, &line, &size);
    fclose(file);
    return (array);
}