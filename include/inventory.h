/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** inventory
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "graphics/subwindow.h"

#define INVENTORY_SPEED 50

typedef struct inventory_s {
    sfSprite *background;
    sfVector2f pos;
    list_t *elements;
    list_t *entities;
    subwindow_move_fct_t move;
    subwindow_update_fct_t update;
    subwindow_draw_fct_t draw;
    subwindow_destroy_fct_t destroy;
    char show;
    char anim;
    char items[16];
} inventory_t;

inventory_t *inventory_create(infos_t *infos);
void inventory_update(subwindow_t *subwindow, infos_t *infos, float elapsed);
void inventory_anim_move(inventory_t *inventory,
sfView *view, int target, float elapsed);
void inventory_show(inventory_t *inventory);

#endif /* !INVENTORY_H_ */
