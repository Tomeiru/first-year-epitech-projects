/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** text
*/

#ifndef TEXT_H_
#define TEXT_H_

#include "elements/entities/entity.h"

typedef struct text_s {
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
    sfText *text;
    float time;
} text_t;

text_t *text_create(char *text_str, sfFont *font, sfVector2f pos, int size);
void text_move(element_t *element, sfVector2f pos);
void text_rotate(element_t *element, float rot);
void text_draw(element_t *element, sfRenderWindow *window);
void text_destroy(element_t *element);

void text_money_update(entity_t *entity, infos_t *infos, float elapsed);
void text_health_update(entity_t *entity, infos_t *infos, float elapsed);

void text_gameover_name_update(entity_t *entity, infos_t *infos, float elapsed);
void text_notif_update(entity_t *entity, infos_t *infos, float elapsed);
void text_fps_update(entity_t *entity, infos_t *infos, float elapsed);
void text_sound_update(entity_t *entity, infos_t *infos, float elapsed);

#endif /* !TEXT_H_ */
