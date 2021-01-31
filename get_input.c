/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** get_input
*/

#include "mysh.h"

char *get_input(int *input_len, int return_val)
{
    char *line = NULL;
    unsigned long size = 0;

    write(1, "$> ", 3);
    if (getline(&line, &size, stdin) == -1)
        exit(return_val);
    size = my_strlen(line) - 1;
    line[size] = '\0';
    *input_len = size;
    return (line);
}

int get_input_len(char *input)
{
    int len = 0;

    for (int i = 0; input[i]; i++)
        if (input[i] != ' ')
            len++;
    return (len);
}