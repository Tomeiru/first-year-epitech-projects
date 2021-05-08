/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH execute
*/

#include <stdlib.h>
#include "my.h"
#include "my_rpg.h"
#include "rpgsh/rpgsh.h"
#include "rpgsh/commands.h"
#include "rpgsh/conditions.h"

void execute_instruction(char ***line, char **args,
infos_t *infos, element_t *element)
{
    if (!my_strcmp(args[0], "IF")) {
        execute_condition(line, args, infos, element);
    } else {
        if (!my_strcmp(args[0], "ELSE"))
            skip_else(line);
        execute_command(line, args, infos, element);
    }
}

void execute_condition(char ***line, char **args,
infos_t *infos, element_t *element)
{
    char *cond = args[1];
    int len = my_strlen(cond);

    for (int i = 0; i < NB_CONDITIONS; i++) {
        if (CONDITION_LENGTH[i] == len && !my_strcmp(CONDITION_STR[i], cond)) {
            if (!CONDITION_FCT[i](line, args + 1, infos, element))
                skip_condition(line);
        }
    }
}

void execute_command(char ***line, char **args,
infos_t *infos, element_t *element)
{
    char *cmd = args[0];
    int len = my_strlen(cmd);

    for (int i = 0; i < NB_COMMANDS; i++) {
        if (COMMAND_LENGTH[i] == len && !my_strcmp(COMMAND_STR[i], cmd)) {
            COMMAND_FCT[i](line, args, infos, element);
            break;
        }
    }
}

void skip_condition(char ***line)
{
    int if_nb = 0;
    char **args;

    for (; **line; *line += 1) {
        args = split_into_args(**line);
        if (!my_strcmp(args[0], "IF"))
            if_nb++;
        else if (!my_strcmp(args[0], "FI"))
            if_nb--;
        if ((!my_strcmp(args[0], "ELSE") && if_nb == 1) ||
        if_nb == 0) {
            free_args(args);
            break;
        }
        free_args(args);
    }
}

void skip_else(char ***line)
{
    int if_nb = 1;
    char **args;

    for (; **line; *line += 1) {
        args = split_into_args(**line);
        if (!my_strcmp(args[0], "IF"))
            if_nb++;
        else if (!my_strcmp(args[0], "FI"))
            if_nb--;
        if (if_nb == 0) {
            free_args(args);
            break;
        }
        free_args(args);
    }
}