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
    inventory_t *inventory = inventory_create(infos);

    if (!inventory)
        return (1);
    world_scene->inventory = inventory;
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
    world_scene->can_move = 1;
    world_load(world_scene, infos);
    return (scene);
}

int world_scene_update(scene_t *scene, infos_t *infos, float elapsed)
{
    entity_t *entity;
    subwindow_t *subwindow;

    world_move((world_scene_t*) scene, infos, elapsed);
    for (list_t *list = scene->entities; list; list = list->next) {
        entity = (entity_t*) list->data;
        entity->update(entity, infos, elapsed);
    }
    for (list_t *list = scene->subwindows; list; list = list->next) {
        subwindow = (subwindow_t*) list->data;
        subwindow->update(subwindow, infos, elapsed);
    }
    return (0);
}

int world_scene_event(scene_t *scene, infos_t *infos, sfEvent *event)
{
    world_scene_t *world_scene = (world_scene_t*) scene;
    sfKeyEvent keyEv = event->key;

    if (event->type == sfEvtKeyPressed) {
        if (keyEv.code == sfKeyTab) {
            world_scene->can_move = 0;
            inventory_show(world_scene->inventory);
        }
    }
    return (0);
}

void world_scene_destroy(scene_t *scene)
{
    world_scene_t *world_scene = (world_scene_t*) scene;
    list_t *next;

    for (list_t *list = scene->subwindows; list; list = next) {
        next = list->next;
        ((subwindow_t*) list->data)->destroy((subwindow_t*) list->data);
        free(list);
    }
    scene_destroy_all_elements(scene);
    free(world_scene);
}
