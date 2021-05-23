/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instru_one
*/

#include "corewar.h"

unsigned int get_id(arena_t *arena, int PC)
{
    unsigned int result = 0;
    unsigned char first = arena->memory[PC + 1];
    unsigned char second = arena->memory[PC + 2];
    unsigned char third = arena->memory[PC + 3];
    unsigned char fourth = arena->memory[PC + 4];

    result += first * 0x1000000;
    result += second * 0x10000;
    result += third * 0x100;
    result += fourth * 0x1;
    return (result);
}

void live(info_t *info,  champion_t *champion)
{
    unsigned int id = 0;
    champion_t *champ = NULL;

    if (champion->op_cycle == 10) {
        id = get_id(info->arena, champion->PC);
        champ = find_champ(info->champions, id);
        if (champ == NULL)
            return;
        write(1, "The player ", 12);
        my_putnbr(champ->id);
        write(1, "(", 1);
        my_putstr(champ->name);
        write(1, ") is alive.", 12);
        champion->op_cycle = 1;
        champion->last_live = info->cycle;
        info->nbr_alive += 1;
    } else
        champion->op_cycle += 1;
} // execute live + update last_live & nbr_live

void load(info_t *info,  champion_t *champion)
{
    return;
} // execute ld

void store(info_t *info,  champion_t *champion)
{
    return;
} // execute st

void addition(info_t *info,  champion_t *champion)
{
    return;
} // execute add