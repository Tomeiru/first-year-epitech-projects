/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** NPC
*/

#include <math.h>
#include "my_rpg.h"
#include "elements/entities/npc.h"

npc_t *npc_create(sfVector2f pos,
sfTexture *texture, char *action, direction_t dir)
{
    npc_t *npc = (npc_t*) interactable_create(sizeof(npc_t), pos, texture);

    if (!npc)
        return (NULL);
    my_strcpy(npc->action_name, action);
    npc->update = &npc_update;
    npc->speed = 2;
    npc->mov_target = (sfVector2f) {-1, -1};
    npc->anim = 0;
    npc->dir = dir;
    living_walk_sprite_anim(npc->sprite, dir, 0);
    return (npc);
}

void npc_update(entity_t *entity, infos_t *infos, float elapsed)
{
    npc_t *npc = (npc_t*) entity;

    if (npc->mov_target.x == -1 && npc->mov_target.y == -1)
        interactable_update(entity, infos, elapsed);
    else {
        npc_movement(npc, infos, elapsed);
        if (npc->sprite)
            living_walk_sprite_anim(npc->sprite, npc->dir, npc->anim);
    }
}

void npc_movement(npc_t *npc, infos_t *infos, float elapsed)
{
    sfVector2f diff = (sfVector2f) {npc->mov_target.x - npc->pos.x,
    npc->mov_target.y - npc->pos.y};
    sfVector2f move = vector_normalize(diff);
    sfVector2f new_pos;
    float speed = npc->speed * elapsed;

    move.x *= speed;
    move.y *= speed;
    walk_animation_set_anim_and_dir(&(npc->anim), &(npc->dir), move, speed);
    prior_element_collision((element_t*) npc, &move, npc->hitbox, infos);
    if (fabs(diff.x) <= fabs(move.x) && fabs(diff.y) <= fabs(move.y)) {
        new_pos = npc->mov_target;
        npc->mov_target = (sfVector2f) {-1, -1};
    } else
        new_pos = (sfVector2f) {npc->pos.x + move.x, npc->pos.y + move.y};
    npc->move((element_t*) npc, new_pos);
}