/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** gameover scene
*/

#ifndef GAMEOVER_SCENE_H_
#define GAMEOVER_SCENE_H_

#include "scene.h"

typedef struct gameover_scene_s {
    sfSprite *background;
    list_t *elements;
    list_t *entities;
    list_t *subwindows;
    post_init_fct_t post_init;
    update_scene_fct_t update;
    draw_scene_fct_t draw;
    event_scene_fct_t event;
    destroy_scene_fct_t destroy;
} gameover_scene_t;

scene_t *gameover_scene_create(infos_t *infos);
int gameover_scene_update(scene_t *scene, infos_t *infos, float elapsed);
void gameover_scene_destroy(scene_t *scene);

#endif /* !GAMEOVER_SCENE_H_ */
