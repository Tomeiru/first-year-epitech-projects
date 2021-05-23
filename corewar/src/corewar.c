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
    get_params(info, av);
    return (0);
}

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
    info_t *info = malloc(sizeof(info_t));

    init_all(info, av);
    while (info->nbr_alive > 1) {
        while (info->nbr_live < NBR_LIVE)
            loop(info);
        info->cycle_to_die -= CYCLE_DELTA;
    }
    return (0);
}