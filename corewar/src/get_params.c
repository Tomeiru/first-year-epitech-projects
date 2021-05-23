/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** get_params.c
*/

#include "corewar.h"

champion_t *find_champ(champion_t *champ_list, int id)
{
    for (champion_t *temp = champ_list; temp != NULL; temp = temp->next)
        if (temp->id == id) {
            return (temp);
        }
    return (NULL);
}

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