/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** meteo
*/

#include "my_rpg.h"
#include "elements/entities/particles/meteo.h"
#include "scene/world_scene.h"

buffer_t *meteo_create(void)
{
    buffer_t *buffer = buffer_create(sizeof(buffer_t),
    (sfVector2f) {0, 0}, (sfVector2u) {WINDOW_WIDTH, WINDOW_HEIGHT});

    if (!buffer)
        return (NULL);
    buffer->update = &meteo_update;
    return (buffer);
}

void meteo_update(entity_t *entity, infos_t *infos, float elapsed)
{
    buffer_t *buffer = (buffer_t*) entity;
    world_scene_t *world_scene = (world_scene_t*) infos->scene;

    UNUSED(elapsed);
    buffer_clear(buffer);
    night_effect(buffer, infos);
    rain_effect(buffer, world_scene->time);
}