/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** world scene
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "actions.h"
#include "audio/music.h"
#include "rpgsh/rpgsh.h"
#include "elements/entities/interactable.h"
#include "scene/world_scene.h"
#include "elements/entities/enemy.h"

scene_t *world_scene_create_new(infos_t *infos)
{
    scene_t *scene = scene_create_default(sizeof(world_scene_t),
    &world_scene_update, &world_scene_destroy);
    sfSprite *background = sfSprite_create();
    world_scene_t *world_scene = (world_scene_t*) scene;

    UNUSED(infos);
    if (!scene || !background)
        return (NULL);
    world_scene->background = background;
    world_scene->post_init = &world_scene_post_init_new;
    world_scene->event = &world_scene_event;
    world_scene->world_type = VILLAGE;
    world_scene->map = NULL;
    world_scene->time = 0;
    world_scene->victory = 0;
    return (scene);
}

scene_t *world_scene_create_save(infos_t *infos)
{
    scene_t *scene = scene_create_default(sizeof(world_scene_t),
    &world_scene_update, &world_scene_destroy);
    sfSprite *background = sfSprite_create();
    world_scene_t *world_scene = (world_scene_t*) scene;

    UNUSED(infos);
    if (!scene || !background)
        return (NULL);
    world_scene->background = background;
    world_scene->post_init = &world_scene_post_init_save;
    world_scene->event = &world_scene_event;
    world_scene->world_type = VILLAGE;
    world_scene->map = NULL;
    world_scene->time = 0;
    world_scene->victory = 0;
    return (scene);
}

int world_scene_update(scene_t *scene, infos_t *infos, float elapsed)
{
    world_scene_t *world_scene = (world_scene_t*) scene;

    if (world_scene->victory)
        return (LOAD_VICTORY_SCENE_ACTION);
    update_hover(infos);
    if (check_world_load(world_scene, infos))
        return (QUIT_GAME_ACTION);
    world_scene->time += elapsed;
    if (!world_scene->world_pause && !world_scene->pause->pause)
        scene_update_elements(scene, infos, elapsed);
    camera_move(world_scene, infos, elapsed);
    scene_update_subwindows(scene, infos, elapsed);
    interactable_show_closest(infos, world_scene->hud, world_scene->player);
    if (world_scene->player->health <= 0)
        return (LOAD_GAMEOVER_SCENE_ACTION);
    return (0);
}

void world_scene_destroy(scene_t *scene)
{
    world_scene_t *world_scene = (world_scene_t*) scene;
    list_t *next;

    map_destroy(world_scene->map, world_scene);
    for (list_t *list = scene->subwindows; list; list = next) {
        next = list->next;
        ((subwindow_t*) list->data)->destroy((subwindow_t*) list->data);
        free(list);
    }
    scene_destroy_all_elements(scene);
    free(world_scene);
}
