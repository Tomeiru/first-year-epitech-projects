/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH
*/

#include <stdlib.h>
#include "my.h"
#include "my_rpg.h"
#include "rpgsh/rpgsh.h"

void execute_rpgsh(char **script, infos_t *infos, element_t *element)
{
    char **args = NULL;

    for (char **line = script; *line; line++) {
        args = split_into_args(*line);
        if (!args)
            continue;
        execute_instruction(&line, args, infos, element);
        free_args(args);
        if (!*line)
            break;
    }
}

void execute_rpgsh_single_instruction(char **script,
int *instruction, infos_t *infos, element_t *element)
{
    char **line = script + *instruction;
    char **cpy = line;
    char **args = NULL;

    if (!*line)
        return;
    args = split_into_args(*line);
    execute_instruction(&line, args, infos, element);
    *instruction = (int) (line - cpy);
}