/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** NPC
*/

#include <math.h>
#include "my_rpg.h"
#include "elements/entities/npc.h"

npc_t *npc_create(sfVector2f pos, sfTexture *texture)
{
    npc_t *npc = (npc_t*) interactable_create(sizeof(npc_t), pos, texture);

    if (!npc)
        return (NULL);
    my_strcpy(npc->action_name, "Parler\0");
    npc->update = &npc_update;
    npc->speed = 1;
    npc->mov_target = (sfVector2f) {-1, -1};
    return (npc);
}

void npc_update(entity_t *entity, infos_t *infos, float elapsed)
{
    npc_t *npc = (npc_t*) entity;
    sfVector2f diff;
    sfVector2f move;
    sfVector2f new_pos;

    if (npc->mov_target.x == -1 && npc->mov_target.y == -1)
        interactable_update(entity, infos, elapsed);
    else {
        diff = (sfVector2f) {npc->mov_target.x - npc->pos.x,
        npc->mov_target.y - npc->pos.y};
        move = vector_normalize(diff);
        move.x *= npc->speed * elapsed;
        move.y *= npc->speed * elapsed;
        if (fabs(diff.x) <= fabs(move.x) && fabs(diff.y) <= fabs(move.y)) {
            new_pos = npc->mov_target;
            npc->mov_target = (sfVector2f) {-1, -1};
        } else
            new_pos = (sfVector2f) {npc->pos.x + move.x, npc->pos.y + move.y};
        npc->move((element_t*) npc, new_pos);
    }
}