/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** dialogue.h
*/

#ifndef DIALOGUE_H_
#define DIALOGUE_H_

#include "elements/entities/text.h"

typedef struct dialogue_s {
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
    sfText *text;
    float time;
    int pos;
    char *str;
    int len;
} dialogue_t;

dialogue_t *dialogue_create(char *text_str, sfFont *font, sfVector2f pos,
int size);
sfSprite *dialogue_set_sprite(char *path, sfVector2f pos);
void dialogue_set_fcts(dialogue_t *dialogue);
void dialogue_set_str(dialogue_t *dialogue, char *new_str);
void dialogue_update(entity_t *entity, infos_t *infos, float elapsed);

#endif /* !DIALOGUE_H_ */