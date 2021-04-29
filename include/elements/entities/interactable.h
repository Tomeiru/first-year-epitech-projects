/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** interactable
*/

#ifndef INTERACTABLE_H_
#define INTERACTABLE_H_

#include "graphics/texture.h"
#include "elements/entities/entity.h"

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
    get_infos_element_fct_t get_infos;
    destroy_element_fct_t destroy;
    update_entity_fct_t update;
    void (*action)(struct interactable_s *interactable, infos_t *infos);
    char action_name[16];
    char **action_script;
    int action_instruction;
    char **update_script;
    int update_instruction;
} interactable_t;

typedef void (*interactable_action_fct_t)(interactable_t
*interactable, infos_t *infos);

interactable_t *interactable_create(size_t size,
sfVector2f pos, sfTexture *texture);
void interactable_create_sprite(interactable_t *interactable,
sfSprite *sprite, sfTexture *texture, sfVector2f pos);
void interactable_update(entity_t *entity, infos_t *infos, float elapsed);
void interactable_default_action(interactable_t *interactable, infos_t *infos);
void interactable_get_infos(element_t *element, char *str, int size);

#endif /* !INTERACTABLE_H_ */
