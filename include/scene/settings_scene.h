/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** settings scene
*/

#ifndef SETTINGS_SCENE_H_
#define SETTINGS_SCENE_H_

#include "scene/scene.h"

typedef struct settings_scene_s {
    sfSprite *background;
    list_t *elements;
    list_t *entities;
    list_t *subwindows;
    post_init_fct_t post_init;
    update_scene_fct_t update;
    draw_scene_fct_t draw;
    event_scene_fct_t event;
    destroy_scene_fct_t destroy;
} settings_scene_t;

scene_t *settings_scene_create(infos_t *infos);
int settings_scene_init(scene_t *scene, infos_t *infos);
int settings_scene_update(scene_t *scene, infos_t *infos, float elapsed);
void settings_scene_destroy(scene_t *scene);

#endif /* !SETTINGS_SCENE_H_ */
