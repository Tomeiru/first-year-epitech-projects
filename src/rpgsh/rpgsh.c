/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH
*/

#include <stdlib.h>
#include "my.h"
#include "my_rpg.h"
#include "scene/world_scene.h"
#include "rpgsh/rpgsh.h"
#include "rpgsh/commands.h"
#include "rpgsh/conditions.h"

void execute_rpgsh(char **script, infos_t *infos)
{
    char **args = NULL;

    for (char **line = script; *line; line++) {
        args = split_into_args(*line);
        if (!args)
            continue;
        execute_instruction(&line, args, infos);
        free_args(args);
    }
}

void execute_instruction(char ***line, char **args, infos_t *infos)
{
    char *cmd = *args;
    int len = my_strlen(cmd);

    if (len == 2 && !my_strcmp(cmd, "IF")) {
        execute_condition(line, args, infos);
    } else
        execute_command(args, cmd, len, infos);
}

void execute_condition(char ***line, char **args, infos_t *infos)
{
    char *cond = args[1];
    int len = my_strlen(cond);

    for (int i = 0; i < NB_CONDITIONS; i++) {
        if (CONDITION_LENGTH[i] == len && !my_strcmp(CONDITION_STR[i], cond)) {
            if (!CONDITION_FCT[i](args, infos))
                skip_condition(line);
        }
    }
}

void execute_command(char **args, char *cmd, int len, infos_t *infos)
{
    for (int i = 0; i < NB_COMMANDS; i++) {
        if (COMMAND_LENGTH[i] == len && !my_strcmp(COMMAND_STR[i], cmd)) {
            COMMAND_FCT[i](args, infos, NULL);
            break;
        }
    }
}

void skip_condition(char ***line)
{
    int if_nb = 1;

    for (; **line; *line += 1) {
        if (!my_strcmp(**line, "IF"))
            if_nb++;
        else if (!my_strcmp(**line, "FI"))
            if_nb--;
        if ((!my_strcmp(**line, "ELSE") && if_nb == 1) ||
        if_nb == 0)
            break;
    }
}