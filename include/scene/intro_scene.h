/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** intro scene
*/

#ifndef INTRO_SCENE_H_
#define INTRO_SCENE_H_

#include "scene/scene.h"

typedef struct intro_scene_s {
    sfSprite *background;
    list_t *elements;
    list_t *entities;
    list_t *subwindows;
    post_init_fct_t post_init;
    update_scene_fct_t update;
    draw_scene_fct_t draw;
    event_scene_fct_t event;
    destroy_scene_fct_t destroy;
    float x_offest;
} intro_scene_t;

scene_t *intro_scene_create(infos_t *infos);
int intro_scene_update(scene_t *scene, infos_t *infos, float elapsed);
int intro_scene_event(scene_t *scene, infos_t *infos, sfEvent *event);
void intro_scene_destroy(scene_t *scene);

#endif /* !INTRO_SCENE_H_ */
