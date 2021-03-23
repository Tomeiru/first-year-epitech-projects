/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** menu scene
*/

#ifndef MENU_SCENE_H_
#define MENU_SCENE_H_

#include "scene.h"

typedef struct menu_scene_s {
    sfSprite *background;
    list_t *elements;
    list_t *entities;
    list_t *subwindows;
    update_scene_fct_t update;
    draw_scene_fct_t draw;
    event_scene_fct_t event;
    destroy_scene_fct_t destroy;
} menu_scene_t;

scene_t *menu_scene_create(infos_t *infos);
void menu_scene_destroy(scene_t *scene);
int menu_scene_update(scene_t *scene, infos_t *infos, float elapsed);

#endif /* !MENU_SCENE_H_ */
