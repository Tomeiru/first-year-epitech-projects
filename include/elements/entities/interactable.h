/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** npc.h
*/

#ifndef NPC_H_
#define NPC_H_

#include "graphics/texture.h"
#include "elements/element.h"

typedef struct interactable_s {
    element_type_t type;
    sfVector2f pos;
    float rot;
    sfIntRect hitbox;
    sfSprite *sprite;
    move_element_fct_t move;
    rotate_element_fct_t rotate;
    draw_element_fct_t draw;
    on_click_fct_t on_click;
    set_infos_element_fct_t set_infos;
    destroy_element_fct_t destroy;
    update_entity_fct_t update;
    char action[15];
} interactable_t;

interactable_t *interactable_create(sfVector2f pos,
sfTexture *texture, char *action, element_type_t type);
void interactable_update(element_t *element, infos_t *infos, float elapsed);

#endif /* !NPC_H_ */
