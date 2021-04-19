/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH conditions
*/

#ifndef CONDITIONS_H_
#define CONDITIONS_H_

typedef struct infos_s infos_t;
typedef int (*rpgsh_condition_fct_t)(char **args,
infos_t *infos, element_t *element);

#define NB_CONDITIONS 1

int item_rpgsh_condition(char **args, infos_t *infos, element_t *element);

const char *CONDITION_STR[] = {
    "HAS_ITEM",
};

const int CONDITION_LENGTH[] = {
    8,
};

const rpgsh_condition_fct_t CONDITION_FCT[] = {
    &item_rpgsh_condition,
};

#endif /* !CONDITIONS_H_ */
