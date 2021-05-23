/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** setup
*/

#include "../include/corewar.h"

int init_arena(info_t *info)
{
    arena_t *arena = malloc(sizeof(arena_t));

    for (int i = 0; i < MEM_SIZE; i++)
        arena->memory[i] = 0x0;
    info->arena = arena;
    return (0);
}

void init_info(info_t *info)
{
    info->cycle = 0;
    info->cycle_to_die = CYCLE_TO_DIE;
    info->nbr_alive = 0;
    info->nbr_live = 0;
    info->instru_tab = malloc(sizeof(instruction_t *) * 2);
}