/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** world scene
*/

#ifndef WORLD_SCENE_H_
#define WORLD_SCENE_H_

#include <SFML/Window/Event.h>
#include "scene/scene.h"
#include "inventory.h"
#include "graphics/pause.h"
#include "elements/entities/player.h"

typedef struct world_scene_s {
    sfSprite *background;
    list_t *elements;
    list_t *entities;
    list_t *subwindows;
    update_scene_fct_t update;
    draw_scene_fct_t draw;
    event_scene_fct_t event;
    destroy_scene_fct_t destroy;
    pause_t *pause;
    inventory_t *inventory;
    player_t *player;
} world_scene_t;

scene_t *world_scene_create(infos_t *infos);
int world_scene_update(scene_t *scene, infos_t *infos, float elapsed);
int world_scene_event(scene_t *scene, infos_t *infos, sfEvent *event);
void world_scene_destroy(scene_t *scene);

void world_load(world_scene_t *world_scene, infos_t *infos);
void world_move(world_scene_t *world_scene, infos_t *infos, float elapsed);

#endif /* !WORLD_SCENE_H_ */
