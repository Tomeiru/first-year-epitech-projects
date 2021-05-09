/*
** EPITECH PROJECT, 2021
** myDefender
** File description:
** subwindow
*/

#ifndef SUBWINDOW_H_
#define SUBWINDOW_H_

#include <SFML/Graphics.h>
#include "my_list.h"
#include "elements/element.h"
#include "texture.h"

typedef struct infos_s infos_t;

typedef struct subwindow_s {
    sfSprite *background;
    sfVector2f pos;
    list_t *elements;
    list_t *entities;
    void (*move)(struct subwindow_s *subwindow, sfVector2f new_pos);
    void (*update)(struct subwindow_s *subwindow,
    infos_t *infos, float elapsed);
    void (*draw)(struct subwindow_s *subwindow, sfRenderWindow *window);
    void (*destroy)(struct subwindow_s *subwindow);
} subwindow_t;

typedef void (*subwindow_move_fct_t)(subwindow_t *subwindow,
sfVector2f new_pos);
typedef void (*subwindow_update_fct_t)(subwindow_t *subwindow,
infos_t *infos, float elapsed);
typedef void (*subwindow_draw_fct_t)(subwindow_t *subwindow,
sfRenderWindow *window);
typedef void (*subwindow_destroy_fct_t)(subwindow_t *subwindow);

subwindow_t *subwindow_create(size_t size, infos_t *infos,
sfVector2f pos, texture_t texture);
void subwindow_add_element(subwindow_t *subwindow,
element_t *element, char entity);

void subwindow_default_move(subwindow_t *subwindow, sfVector2f new_pos);
void subwindow_default_update(subwindow_t *subwindow,
infos_t *infos, float elapsed);
void subwindow_default_draw(subwindow_t *subwindow, sfRenderWindow *window);
void subwindow_default_destroy(subwindow_t *subwindow);

subwindow_t *sound_subwindow_create(infos_t *infos);
subwindow_t *fps_subwindow_create(infos_t *infos);
subwindow_t *res_subwindow_create(infos_t *infos);

#endif /* !SUBWINDOW_H_ */
