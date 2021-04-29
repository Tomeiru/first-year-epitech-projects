/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** enemy
*/

#include "my_rpg.h"
#include "elements/entities/enemy.h"
#include "graphics/texture.h"
#include "scene/world_scene.h"

void enemy_take_damage(enemy_t *enemy, int damage)
{
    enemy->health -= damage;
    if (enemy->health <= 0)
        enemy->destroy((element_t *)enemy);
}

void enemy_update(entity_t *entity, infos_t *infos, float elapsed)
{
    enemy_t *enemy = (enemy_t *) entity;
    world_scene_t *world_scene = (world_scene_t *) infos->scene;
    sfVector2f move = {0, 0};
    float speed = 5 * elapsed;

    speed = speed;
    world_scene = world_scene;
    enemy->pos.x = 500;
    enemy->pos.y = 500;
    enemy->move((element_t *) enemy, (sfVector2f)
    {enemy->pos.x + move.x, enemy->pos.y + move.y});
}

enemy_t *enemy_create(infos_t *infos)
{
    element_t *element = element_create_default(sizeof(enemy_t), ENEMY,
    (sfVector2f){0, 0});
    enemy_t *enemy = (enemy_t *) element;
    sfSprite *sprite = sfSprite_create();

    if (!enemy || !sprite)
        return(NULL);
    sfSprite_setTexture(sprite, get_texture(infos, PLAYER_TEXT), 0);
    enemy->sprite = sprite;
    enemy->update = &enemy_update;
    sprite_set_origin_center(sprite);
    element_set_hitbox(element, sfSprite_getGlobalBounds(sprite));
    enemy->health = 1;
    return (enemy);
}