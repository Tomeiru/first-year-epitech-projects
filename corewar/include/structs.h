/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** structs
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

#include "op.h"

typedef struct arena_s
{
    int memory[MEM_SIZE + 1];
} arena_t;

typedef struct instruction_s
{
    op_t op;
    void (*exec)(info_t *info, champion_t *champion);
} instruction_t;

typedef struct champion_s
{
    int carry;
    int PC;
    int last_live;
    int id;
    void *params;
    char *name;
    instruction_t current_op;
    struct champion_s *next;
} champion_t;

typedef struct info_s
{
    int dump;
    int cycle;
    int cycle_to_die;
    int nbr_alive;
    int nbr_live;
    arena_t *arena;
    champion_t *champions;
    instruction_t *instru_tab; //struct tab with all possible instructions
} info_t;



#endif /* !STRUCTS_H_ */
