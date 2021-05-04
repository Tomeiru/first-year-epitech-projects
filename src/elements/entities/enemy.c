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
    sfVector2f player_pos = world_scene->player->pos;
    float distance = get_distance(enemy->pos, player_pos);
    projectile_t *projectile;
    float angle;

    if (distance <= 500 && enemy->attack_cooldown <= 0) {
        angle = atan2(player_pos.y - enemy->pos.y,
        player_pos.x - enemy->pos.x) * (180 /  3.141592);
        enemy->attack_cooldown = 100;
        projectile =  projectile_create(enemy->pos,
        angle, 2, get_texture(infos, ARROW_TEXT));
        scene_add_element((scene_t*) world_scene, (element_t*) projectile, 1);
    }
}

void enemy_close_attack(enemy_t *enemy, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    sfVector2f player_pos = world_scene->player->pos;
    float distance = get_distance(enemy->pos, player_pos);

    if (distance <= 50 && enemy->attack_cooldown <= 0) {
        enemy->attack_cooldown = 20;
        enemy->move_status = 0;
        //player takes damage
    } else if (distance > 50 && enemy->move_status == 0)
        enemy->move_status = 1;
}

void enemy_take_damage(enemy_t *enemy, int damage)
{
    enemy->damage_time = 15;
    enemy->health -= damage;
    if (enemy->health <= 0)
        enemy->destroy((element_t *)enemy);
}

void enemy_default_update(entity_t *entity, infos_t *infos, float elapsed)
{
    enemy_t *enemy = (enemy_t *) entity;
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    sfVector2f move;
    float speed = elapsed * 2;

    if (enemy->attack_cooldown >= 0)
        enemy->attack_cooldown -= elapsed;
    if (enemy->damage_time > 0) {
        enemy->damage_time -= elapsed;
        get_knockback_move(&move, enemy->dir, elapsed * 2);
    } else
        move = enemy->pos;
    prior_map_collision(&move, enemy->hitbox, world_scene->map);
    prior_element_collision((element_t*) enemy, &move, enemy->hitbox, infos);
    walk_animation_set_anim_and_dir(&(enemy->anim), &enemy->dir, move, speed);
    enemy->move((element_t *) enemy, move);
    living_walk_sprite_anim(enemy->sprite, enemy->dir, enemy->anim);
    enemy->attack(enemy, infos);
}

enemy_t *enemy_create(size_t size, infos_t *infos, sfVector2f pos)
{
    element_t *element = element_create_default(size, ENEMY, pos);
    enemy_t *enemy = (enemy_t *) element;
    sfSprite *sprite = sfSprite_create();

    if (!enemy || !sprite)
        return(NULL);
    sfSprite_setTexture(sprite, get_texture(infos, PLAYER_TEXT), 0);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 64, 64});
    enemy->sprite = sprite;
    enemy->update = &enemy_default_update;
    enemy->health = 1;
    enemy->pos_start = enemy->pos;
    enemy->move_status = 1;
    enemy->attack = enemy_close_attack;
    enemy->attack_cooldown = 0;
    enemy->dir = SOUTH;
    enemy->anim = 0;
    enemy->damage_time = 0;
    sprite_set_origin_center(sprite);
    element_set_hitbox(element, sfSprite_getGlobalBounds(sprite));
    return (enemy);
}