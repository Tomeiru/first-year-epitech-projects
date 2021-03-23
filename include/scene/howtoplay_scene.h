/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** howtoplay scene
*/

#ifndef HOWTOPLAY_SCENE_H_
#define HOWTOPLAY_SCENE_H_

#include "scene.h"

typedef struct howtoplay_scene_s {
    sfSprite *background;
    list_t *elements;
    list_t *entities;
    list_t *subwindows;
    update_scene_fct_t update;
    draw_scene_fct_t draw;
    event_scene_fct_t event;
    destroy_scene_fct_t destroy;
} howtoplay_scene_t;

scene_t *howtoplay_scene_create(infos_t *infos);
void howtoplay_scene_destroy(scene_t *scene);
int howtoplay_scene_update(scene_t *scene, infos_t *infos, float elapsed);

#endif /* !HOWTOPLAY_SCENE_H_ */
