/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** buffer
*/

#ifndef BUFFER_H_
#define BUFFER_H_

#include "elements/entities/entity.h"

typedef struct buffer_s {
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
    sfVector2u size;
    sfUint8 *pixels;
    sfTexture *texture;
    char edited;
} buffer_t;

buffer_t *buffer_create(size_t memsize, sfVector2f pos, sfVector2u size);
void buffer_put_pixel(buffer_t *buffer, sfColor color, sfVector2u pos);
void buffer_clear(buffer_t *buffer);
void buffer_draw(element_t *element, sfRenderWindow *window);
void buffer_destroy(element_t *element);

#endif /* !BUFFER_H_ */
