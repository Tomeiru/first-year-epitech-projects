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
    char *cmd = *args;

    if (!my_strcmp(cmd, "IF")) {
        execute_condition(line, args, infos, element);
    } else
        execute_command(line, args, infos, element);
}

void execute_condition(char ***line, char **args,
infos_t *infos, element_t *element)
{
    char *cond = args[1];
    int len = my_strlen(cond);

    for (int i = 0; i < NB_CONDITIONS; i++) {
        if (CONDITION_LENGTH[i] == len && !my_strcmp(CONDITION_STR[i], cond)) {
            if (!CONDITION_FCT[i](line, args, infos, element))
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