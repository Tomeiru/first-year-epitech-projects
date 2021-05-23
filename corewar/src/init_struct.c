/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** init_struct
*/

#include "corewar.h"

instruction_t *init_instruction_struct(void)
{
    instruction_t *instruction = malloc(sizeof(instruction_t));

    return (instruction);
}

champion_t *init_champions_linkedlist(void)
{
    champion_t *champion = malloc(sizeof(champion_t));

    champion->PC = 0;
    champion->name = NULL;
    champion->last_live = 0;
    champion->id = 0;
    champion->params = NULL;
    champion->current_op = init_instruction_struct();
    champion->carry = 0;
    champion->next = NULL;
    return (champion);
}

arena_t *init_arena_struct(void)
{
    arena_t *arena = malloc(sizeof(arena_t));

    arena->memory = malloc(sizeof(unsigned char) * (6144));
    return (arena);
}

info_t *init_all(void)
{
    info_t *info = malloc(sizeof(info_t));

    info->cycle = 0;
    info->cycle_to_die = CYCLE_TO_DIE;
    info->nbr_alive = 0;
    info->nbr_live = 0;
    info->arena = init_arena_struct();
    info->champions = init_champions_linkedlist();
    //init all structs and load instructions in memory
    return (info);
}