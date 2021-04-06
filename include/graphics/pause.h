/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** pause
*/

#ifndef PAUSE_H_
#define PAUSE_H_

#include "my_list.h"
#include "graphics/subwindow.h"

#define PAUSE_SPEED 75

typedef struct infos_s infos_t;

typedef struct pause_s {
    sfSprite *background;
    sfVector2f pos;
    list_t *elements;
    list_t *entities;
    subwindow_move_fct_t move;
    subwindow_update_fct_t update;
    subwindow_draw_fct_t draw;
    subwindow_destroy_fct_t destroy;
    char pause;
    char anim;
} pause_t;

pause_t *pause_create(infos_t *infos);
void pause_update(subwindow_t *subwindow, infos_t *infos, float elapsed);
void pause_draw(subwindow_t *subwindow, sfRenderWindow *window);

int button_pause_resume(element_t *element,
infos_t *infos, sfMouseButton button_type);
void pause_anim_move(pause_t *pause,
const sfView *view, int target, float elapsed);
void pause_set_pause(pause_t *pause, infos_t *infos);

#endif /* !PAUSE_H_ */
