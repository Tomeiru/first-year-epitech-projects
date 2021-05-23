/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** corewar
*/

#include "corewar.h"

int init_all(info_t *info, char **av)
{
    init_info(info);
    init_arena(info);
    get_params(av, info);
    return (0);
}

int update(info_t *info, champion_t *champion)
{
    unsigned char op;

    if (champion->current_op == NULL) {
        op = info->arena->memory[champion->PC];
        for (int i = 0; info->instru_tab[i] != NULL; i++) {
            if (info->instru_tab[i]->op.code == op)
                champion->current_op = info->instru_tab[i];
        }
    }
    champion->current_op->exec(info, champion);
    return (0);
}

void loop(info_t *info)
{
    for (champion_t *temp = info->champions; temp != NULL; temp = temp->next)
        update(info, temp);
    info->cycle++;
}

int corewar(char **av, int champ_number)
{
    info_t *info = malloc(sizeof(info_t));

    info->nbr_champions = champ_number;
    init_all(info, av);
    while (info->nbr_alive > 1) {
        while (info->nbr_live < NBR_LIVE)
            loop(info);
        info->cycle_to_die -= CYCLE_DELTA;
    }
    return (0);
}