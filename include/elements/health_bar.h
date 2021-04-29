/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** health bar
*/

#ifndef HEALTH_BAR_H_
#define HEALTH_BAR_H_

#include "elements/element.h"

#define HEART_SIZE 64
#define MAX_HEARTS 10

typedef struct health_bar_s {
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
    sfRenderTexture *render_text;
    sfSprite *heart_sprite;
    int max_value;
} health_bar_t;

health_bar_t *health_bar_create(infos_t *infos, sfVector2f pos,
float value, int max_value);
void health_bar_set_value(health_bar_t *health_bar, float value);
void health_bar_draw_hearts(health_bar_t *health_bar, int nb, int type);
void health_bar_destroy(element_t *element);

#endif /* !HEALTH_BAR_H_ */
