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
    if (champion->current_op != NULL)
        live(info, champion);
    if (info->cycle - champion->last_live > info->cycle_to_die) {
        info->nbr_alive -= 1;
        for (champion_t *backup = info->champions; 
        backup->next->id != champion->id; backup = backup->next)
            backup->next = champion->next;
        free(champion);
    }
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
        while (info->nbr_live < NBR_LIVE) {
            loop(info);
        }info->cycle_to_die -= CYCLE_DELTA;
    }
    return (0);
}