/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** meteo
*/

#include <math.h>
#include "my_rpg.h"
#include "elements/entities/particles/meteo.h"
#include "scene/world_scene.h"

buffer_t *meteo_create(void)
{
    buffer_t *buffer = buffer_create(sizeof(buffer_t),
    (sfVector2f) {0, 0}, (sfVector2u)
    {WINDOW_WIDTH / BUFFER_SCALE, WINDOW_HEIGHT / BUFFER_SCALE});

    if (!buffer)
        return (NULL);
    buffer->type = BACKGROUND;
    sfSprite_setScale(buffer->sprite,
    (sfVector2f) {BUFFER_SCALE, BUFFER_SCALE});
    buffer->update = &meteo_update;
    return (buffer);
}

void meteo_update(entity_t *entity, infos_t *infos, float elapsed)
{
    buffer_t *buffer = (buffer_t*) entity;
    world_scene_t *world_scene = (world_scene_t*) infos->scene;

    UNUSED(elapsed);
    buffer_clear(buffer);
    if (world_scene->world_type == FOREST)
        night_effect(buffer, infos, 1);
    else if (world_scene->world_type == RIVER)
        rain_effect(buffer, world_scene->time);
}