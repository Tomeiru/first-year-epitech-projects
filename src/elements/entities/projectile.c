/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** projectile
*/

#include <math.h>
#include "my_rpg.h"
#include "map.h"
#include "scene/world_scene.h"
#include "elements/entities/projectile.h"

#include <stdio.h>

projectile_t *projectile_create(sfVector2f pos,
float rot, float speed, sfTexture *texture)
{
    projectile_t *projectile = (projectile_t*)
    element_create_default(sizeof(projectile_t), PROJECTILE, pos);
    sfSprite *sprite = sfSprite_create();

    if (!projectile || !sprite)
        return (NULL);
    sfSprite_setTexture(sprite, texture, 0);
    sprite_set_origin_center(sprite);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setRotation(sprite, rot + 45);
    projectile->sprite = sprite;
    projectile->rot = rot;
    projectile->update = &projectile_update;
    projectile->speed = speed;
    return (projectile);
}

void projectile_update(entity_t *entity, infos_t *infos, float elapsed)
{
    projectile_t *projectile = (projectile_t*) entity;
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    map_t *map = ((world_scene_t*) infos->scene)->map;
    float rad = projectile->rot * 3.14 / 180;
    float speed = projectile->speed * elapsed;
    sfVector2f new_pos = projectile->pos;
    element_t *collision = element_collision((element_t*)projectile, projectile->hitbox,
        world_scene->entities);

    new_pos.x += cos(rad) * speed;
    new_pos.y += sin(rad) * speed;
    if (collision != NULL && collision->type == PLAYER) {
        player_damage(world_scene->player, 1, infos);
        scene_remove_element((scene_t*)world_scene, (element_t*)projectile, 1);
        return;
    }
    projectile->move((element_t*) projectile, new_pos);
    if (projectile->pos.x < 0 || projectile->pos.x > map->map_size.x
    || projectile->pos.y < 0 || projectile->pos.y > map->map_size.y)
        scene_remove_element(infos->scene, (element_t*) projectile, 1);
}