/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instru_one
*/

#include "corewar.h"

void live(info_t *info,  champion_t *champion)
{
    unsigned int id = 0;
    champion_t *champ = NULL;

    if (champion->op_cycle == 10) {
        id = get_id(info->arena, champion->PC);
        champ = find_champ(info->champions, id);
        champion->PC += 5;
        if (champ == NULL)
            return;
        write(1, "The player ", 12);
        my_putnbr(champ->id);
        write(1, "(", 1);
        my_putstr(champ->name);
        write(1, ") is alive.\n", 12);
        champion->op_cycle = 1;
        champion->last_live = info->cycle;
        info->nbr_live += 1;
    } else
        champion->op_cycle += 1;
}