/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** npc
*/

#ifndef NPC_H_
#define NPC_H_

#include "elements/entities/interactable.h"

typedef struct npc_s {
    element_type_t type;
    sfVector2f pos;
    float rot;
    sfIntRect hitbox;
    sfSprite *sprite;
    move_element_fct_t move;
    rotate_element_fct_t rotate;
    draw_element_fct_t draw;
    on_click_fct_t on_click;
    get_infos_element_fct_t get_infos;
    destroy_element_fct_t destroy;
    update_entity_fct_t update;
    interactable_action_fct_t action;
    char action_name[16];
    char **action_script;
    int action_instruction;
    char **update_script;
    int update_instruction;
    float speed;
    sfVector2f mov_target;
} npc_t;

npc_t *npc_create(sfVector2f pos, sfTexture *texture);
void npc_update(entity_t *entity, infos_t *infos, float elapsed);

#endif /* !NPC_H_ */
