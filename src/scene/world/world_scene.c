/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** world scene
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "scene/world_scene.h"

int world_scene_init(world_scene_t *world_scene, infos_t *infos)
{
    player_t *player = player_create(infos);
    pause_t *pause = pause_create(infos);
    inventory_t *inventory = inventory_create(infos);

    if (!pause || !player || !inventory)
        return (1);
    world_scene->player = player;
    world_scene->pause = pause;
    world_scene->inventory = inventory;
    scene_add_element((scene_t*) world_scene, (element_t*) player, 1);
    create_list(&(world_scene->subwindows), pause);
    create_list(&(world_scene->subwindows), inventory);
    return (0);
}

scene_t *world_scene_create(infos_t *infos)
{
    scene_t *scene = scene_create_default(sizeof(world_scene_t),
    &world_scene_update, &world_scene_destroy);
    sfSprite *background = sfSprite_create();
    world_scene_t *world_scene = (world_scene_t*) scene;

    if (!scene || !background || world_scene_init(world_scene, infos))
        return (NULL);
    world_scene->background = background;
    world_scene->event = &world_scene_event;
    world_scene->map = NULL;
    if (world_load(world_scene, "assets/maps/default/"))
        return (NULL);
    return (scene);
}

int world_scene_update(scene_t *scene, infos_t *infos, float elapsed)
{
    world_scene_t *world_scene = (world_scene_t*) scene;

    update_hover(infos);
    if (world_scene->pause->pause) {
        world_scene->pause->update((subwindow_t*)
        world_scene->pause, infos, elapsed);
        return (0);
    }
    camera_move(world_scene, infos, elapsed);
    scene_update_elements(scene, infos, elapsed);
    return (0);
}

int world_scene_event(scene_t *scene, infos_t *infos, sfEvent *event)
{
    world_scene_t *world_scene = (world_scene_t*) scene;
    sfKeyEvent keyEv = event->key;

    if (event->type == sfEvtKeyPressed) {
        if (keyEv.code == sfKeyTab) {
            world_scene->player->can_move = 0;
            inventory_show(world_scene->inventory);
        } else if (keyEv.code == sfKeyEscape)
            pause_set_pause(world_scene->pause, infos);
    }
    return (0);
}

void world_scene_destroy(scene_t *scene)
{
    world_scene_t *world_scene = (world_scene_t*) scene;
    list_t *next;

    map_destroy(world_scene->map);
    for (list_t *list = scene->subwindows; list; list = next) {
        next = list->next;
        ((subwindow_t*) list->data)->destroy((subwindow_t*) list->data);
        free(list);
    }
    scene_destroy_all_elements(scene);
    free(world_scene);
}
