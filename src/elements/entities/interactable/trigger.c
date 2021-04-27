/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** trigger
*/

#include <math.h>
#include "my_rpg.h"
#include "elements/entities/npc.h"

npc_t *trigger_create(sfVector2f pos, char *action)
{
    npc_t *npc = (npc_t*) interactable_create(sizeof(npc_t), pos, NULL);

    if (!npc)
        return (NULL);
    my_strcpy(npc->action_name, action);
    npc->move = &trigger_move;
    npc->draw = &trigger_draw;
    npc->update = &npc_update;
    npc->speed = 1;
    npc->mov_target = (sfVector2f) {-1, -1};
    return (npc);
}

void trigger_move(element_t *element, sfVector2f pos)
{
    element->pos = pos;
    element->hitbox.left = pos.x;
    element->hitbox.top = pos.y;
}

void trigger_draw(element_t *element, sfRenderWindow *window)
{
    UNUSED(element);
    UNUSED(window);
}