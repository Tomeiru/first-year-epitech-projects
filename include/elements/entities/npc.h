/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** npc
*/

#ifndef NPC_H_
#define NPC_H_

#include "my_rpg.h"
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
    direction_t dir;
    float anim;
} npc_t;

npc_t *npc_create(sfVector2f pos,
sfTexture *texture, char *action, direction_t dir);
void npc_update(entity_t *entity, infos_t *infos, float elapsed);
void npc_movement(npc_t *npc, infos_t *infos, float elapsed);

npc_t *trigger_create(sfVector2f pos, char *action);
void trigger_move(element_t *element, sfVector2f pos);
void trigger_draw(element_t *element, sfRenderWindow *window);
void trigger_destroy(element_t *element);

#endif /* !NPC_H_ */
