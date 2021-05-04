/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** enemy
*/

#include "my_rpg.h"
#include "elements/entities/enemy.h"
#include "elements/entities/projectile.h"
#include "graphics/texture.h"
#include "scene/world_scene.h"
#include "math.h"

#include <stdio.h>

void enemy_ranged_attack(enemy_t *enemy, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    float distance = fabs(enemy->pos.x - world_scene->player->pos.x) +
        fabs(enemy->pos.y - world_scene->player->pos.y);
    float angle;

    if (distance <= 500 && enemy->attack_cooldown <= 0) {
        angle = atan2(world_scene->player->pos.y - enemy->pos.y, world_scene->player->pos.x - enemy->pos.x);
        angle = angle * (180 /  3.141592);
        enemy->attack_cooldown = 100;
        enemy->move_status = 0;
        scene_add_element((scene_t*)world_scene,
            (element_t*)projectile_create(enemy->pos, angle, 1,
            get_texture(infos, ARROW_TEXT)), 1);
    } else if (distance > 500 && enemy->move_status == 0)
        enemy->move_status = 1;
}

void enemy_close_attack(enemy_t *enemy, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    float distance = fabs(enemy->pos.x - world_scene->player->pos.x) +
        fabs(enemy->pos.y - world_scene->player->pos.y);

    if (distance <= 50 && enemy->attack_cooldown <= 0) {
        enemy->attack_cooldown = 20;
        enemy->move_status = 0;
        //player takes damage
    } else if (distance > 50 && enemy->move_status == 0)
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
    if (enemy->attack_cooldown >= 0)
        enemy->attack_cooldown -= elapsed;
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
    enemy->attack = enemy_close_attack;
    enemy->attack_cooldown = 0;
    return (enemy);
}