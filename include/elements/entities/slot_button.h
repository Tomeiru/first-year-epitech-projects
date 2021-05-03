/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** slot button
*/

#ifndef SLOT_BUTTON_H_
#define SLOT_BUTTON_H_

#include "elements/entities/button.h"

typedef struct slot_button_s {
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
    int width;
    int height;
    char is_hover;
    float press_time;
    int texture_height_offset;
    sfSprite *icon;
    unsigned char item;
} slot_button_t;

slot_button_t *slot_button_create(infos_t *infos, sfVector2f pos);
int slot_button_setup_icon(slot_button_t *button,
infos_t *infos, sfVector2f pos);
void slot_button_set_item(slot_button_t *button, unsigned char item);

void slot_button_move(element_t *element, sfVector2f pos);
void slot_button_draw(element_t *element, sfRenderWindow *window);
void slot_button_destroy(element_t *element);

#endif /* !SLOT_BUTTON_H_ */
