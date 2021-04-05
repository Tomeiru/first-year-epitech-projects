/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** world scene
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "scene/world_scene.h"

scene_t *world_scene_create(infos_t *infos)
{
    scene_t *scene = scene_create_default(sizeof(world_scene_t),
    &world_scene_update, &world_scene_destroy);
    sfSprite *background = sfSprite_create();
    world_scene_t *world_scene = (world_scene_t*) scene;

    if (!scene || !background)
        return (NULL);
    world_scene->background = background;
    world_scene->event = &world_scene_event;
    world_load(world_scene, infos);
    return (scene);
}

int world_scene_update(scene_t *scene, infos_t *infos, float elapsed)
{
    entity_t *entity;

    world_move((world_scene_t*) scene, infos, elapsed);
    for (list_t *list = scene->entities; list; list = list->next) {
        entity = (entity_t*) list->data;
        entity->update(entity, infos, elapsed);
    }
    return (0);
}

int world_scene_event(scene_t *scene, infos_t *infos, sfEvent *event)
{
    return (0);
}

void world_scene_destroy(scene_t *scene)
{
    world_scene_t *world_scene = (world_scene_t*) scene;

    scene_destroy_all_elements(scene);
    free(world_scene);
}
