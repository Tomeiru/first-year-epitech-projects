/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** particle
*/

#include "my_rpg.h"
#include "graphics/texture.h"
#include "elements/entities/particle.h"

particle_t *particle_create(sfVector2f pos, float rot,
sfTexture *texture, float life_time)
{
    particle_t *particle = (particle_t*)
    element_create_default(sizeof(particle_t), PARTICLE, pos);
    sfSprite *sprite = sfSprite_create();

    if (!particle || !sprite)
        return (NULL);
    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 64, 64});
    sfSprite_setPosition(sprite, pos);
    sfSprite_setRotation(sprite, rot * 180 / 3.14);
    particle->sprite = sprite;
    particle->rot = rot;
    particle->update = &particle_default_update;
    particle->time = 0;
    particle->life_time = life_time;
    particle->sprite_speed = 0;
    sprite_set_origin_center(sprite);
    element_set_hitbox((element_t*) particle,
    sfSprite_getGlobalBounds(sprite));
    return (particle);
}

void particle_default_update(entity_t *entity, infos_t *infos, float elapsed)
{
    particle_t *particle = (particle_t*) entity;

    particle->time += elapsed;
    if (particle->sprite_speed > 0)
        sfSprite_setTextureRect(entity->sprite, (sfIntRect)
        {((int) particle->time) / particle->sprite_speed * 64, 0, 64, 64});
    if (particle->time >= particle->life_time)
        scene_remove_element((scene_t*) infos->scene, (element_t*) entity, 1);
}