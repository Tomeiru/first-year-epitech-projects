/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** meteo
*/

#include <stdio.h>

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
    sfSprite_setScale(buffer->sprite,
    (sfVector2f) {BUFFER_SCALE, BUFFER_SCALE});
    buffer->update = &meteo_update;
    return (buffer);
}

/*
**  Day: 10m (600s), 60fps -> 36000 updates
**  36000 / 3.14 / 2 ~= 5732.5
*/
void meteo_update(entity_t *entity, infos_t *infos, float elapsed)
{
    buffer_t *buffer = (buffer_t*) entity;
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    int time_int = (int) world_scene->time;
    float darkness = 0.5 - 0.5 * cos(time_int % 3600 / 572.35);

    UNUSED(elapsed);
    buffer_clear(buffer);
    night_effect(buffer, infos, darkness);
    rain_effect(buffer, world_scene->time);
}