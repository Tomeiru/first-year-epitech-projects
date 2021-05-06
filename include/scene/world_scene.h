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
#include "map.h"
#include "inventory.h"
#include "hud.h"
#include "graphics/pause.h"
#include "elements/entities/player.h"

typedef enum world_type_e {
    VILLAGE,
    FOREST,
    RIVER,
} world_type_t;

typedef struct world_scene_s {
    sfSprite *background;
    list_t *elements;
    list_t *entities;
    list_t *subwindows;
    post_init_fct_t post_init;
    update_scene_fct_t update;
    draw_scene_fct_t draw;
    event_scene_fct_t event;
    destroy_scene_fct_t destroy;
    world_type_t world_type;
    char world_pause;
    map_t *map;
    pause_t *pause;
    inventory_t *inventory;
    hud_t *hud;
    player_t *player;
    element_t *cam_target;
    float time;
} world_scene_t;

scene_t *world_scene_create_new(infos_t *infos);
scene_t *world_scene_create_save(infos_t *infos);
int world_scene_update(scene_t *scene, infos_t *infos, float elapsed);
void world_scene_destroy(scene_t *scene);

int world_scene_post_init_common(world_scene_t *world_scene, infos_t *infos);
int world_scene_post_init_new(scene_t *scene, infos_t *infos);
int world_scene_post_init_save(scene_t *scene, infos_t *infos);
int world_scene_event(scene_t *scene, infos_t *infos, sfEvent *event);
void world_scene_keyboard_event(world_scene_t *world_scene,
sfKeyCode code, infos_t *infos);

int world_load(world_scene_t *world_scene,
int map_id, int spawn_id, infos_t *infos);
int check_world_load(world_scene_t *world_scene, infos_t *infos);
int world_load_save(world_scene_t *world_scene, infos_t *infos);

void camera_move(world_scene_t *world_scene, infos_t *infos, float elapsed);
void camera_move_limits(sfVector2f *move, const sfView *view,
world_scene_t *world_scene);
void camera_move_view(sfView *view, sfVector2f move,
world_scene_t *world_scene, infos_t *infos);

int does_savefile_exists(void);
void save_game(world_scene_t *world_scene);
int load_save(world_scene_t *world_scene, infos_t *infos);
int read_int(int fd);
float read_float(int fd);

#endif /* !WORLD_SCENE_H_ */
