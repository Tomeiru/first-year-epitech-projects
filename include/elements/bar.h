/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** bar
*/

#ifndef BAR_H_
#define BAR_H_

#include "elements/element.h"

#define RED_BAR 0
#define GREEN_BAR 1

typedef struct bar_s {
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
    sfRectangleShape *bkgd;
    sfRectangleShape *bar;
    sfVector2f size;
    float value;
    float max;
    int color_id;
} bar_t;

bar_t *bar_create(infos_t *infos, sfIntRect rect, float max_value);
void bar_set_value(bar_t *bar, float value);
void bar_set_color(bar_t *bar, unsigned int color_id);

void bar_move(element_t *element, sfVector2f pos);
void bar_draw(element_t *element, sfRenderWindow *window);
void bar_destroy(element_t *element);

#endif /* !BAR_H_ */
