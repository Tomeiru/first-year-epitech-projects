/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

typedef struct infos_s infos_t;
typedef struct element_s element_t;
typedef void (*rpgsh_command_fct_t)(char **args,
infos_t *infos, element_t *element);

#define NB_COMMANDS 1

void add_rpgsh_command(char **args, infos_t *infos, element_t *element);

const char *COMMAND_STR[] = {
    "ADD",
};

const int COMMAND_LENGTH[] = {
    3,
};

const rpgsh_command_fct_t COMMAND_FCT[] = {
    &add_rpgsh_command,
};

#endif /* !COMMANDS_H_ */
