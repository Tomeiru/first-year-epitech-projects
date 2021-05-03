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
#include "math.h"

void enemy_ranged_attack(enemy_t *enemy, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    float distance = fabs(enemy->pos.x - world_scene->player->pos.x) +
        fabs(enemy->pos.y - world_scene->player->pos.y);

    if (distance <= 10) {
        enemy->move_status = 0;
        //player takes damage
    } else
        enemy->move_status = 1;
}

void enemy_close_attack(enemy_t *enemy, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    float distance = fabs(enemy->pos.x - world_scene->player->pos.x) +
        fabs(enemy->pos.y - world_scene->player->pos.y);

    if (distance <= 3) {
        enemy->move_status = 0;
        //player takes damage
    } else
        enemy->move_status = 1;
}

void enemy_take_damage(enemy_t *enemy, int damage)
{
    enemy->health -= damage;
    if (enemy->health <= 0)
        enemy->destroy((element_t *)enemy);
}

void enemy_default_update(entity_t *entity, infos_t *infos, float elapsed)
{
    enemy_t *enemy = (enemy_t *) entity;
    sfVector2f move;

    move = enemy->pos;
    enemy->move((element_t *) enemy, move);
    enemy->attack(enemy, infos);
    UNUSED(elapsed);
}

enemy_t *enemy_create(size_t size, infos_t *infos, sfVector2f pos)
{
    element_t *element = element_create_default(size, ENEMY, pos);
    enemy_t *enemy = (enemy_t *) element;
    sfSprite *sprite = sfSprite_create();

    if (!enemy || !sprite)
        return(NULL);
    sfSprite_setTexture(sprite, get_texture(infos, PLAYER_TEXT), 0);
    enemy->sprite = sprite;
    enemy->update = &enemy_default_update;
    sprite_set_origin_center(sprite);
    element_set_hitbox(element, sfSprite_getGlobalBounds(sprite));
    enemy->health = 1;
    enemy->pos_start = enemy->pos;
    enemy->move_status = 1;
    return (enemy);
}