/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH conditions
*/

#ifndef CONDITIONS_H_
#define CONDITIONS_H_

typedef struct infos_s infos_t;
typedef int (*rpgsh_condition_fct_t)(char ***line,
char **args, infos_t *infos, element_t *element);

#define NB_CONDITIONS 2

int item_rpgsh_condition(char ***line,
char **args, infos_t *infos, element_t *element);
int player_in_range_condition(char ***line,
char **args, infos_t *infos, element_t *element);

const char *CONDITION_STR[] = {
    "HAS_ITEM",
    "PLAYER_IN_RANGE"
};

const int CONDITION_LENGTH[] = {
    8,
    15
};

const rpgsh_condition_fct_t CONDITION_FCT[] = {
    &item_rpgsh_condition,
    &player_in_range_condition
};

#endif /* !CONDITIONS_H_ */
