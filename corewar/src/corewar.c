/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** corewar
*/

#include "corewar.h"

int update(info_t *info, champion_t *champion)
{
    //read mem, update vars
    champion->current_op.exec(info, champion);
    return (0);
}

int loop(info_t *info)
{
    for (champion_t *temp = info->champions; temp != NULL; temp = temp->next)
        update(info, temp);
    info->cycle++;
}

int corewar(int ac, char **av)
{
    info_t *info = init_all(ac, av);

    while (info->nbr_alive > 1) {
        while (info->nbr_live < NBR_LIVE)
            loop(info);
        info->cycle_to_die -= CYCLE_DELTA;
    }
    return (0);
}