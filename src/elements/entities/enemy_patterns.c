/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** enemy_patterns
*/

#include "my_rpg.h"
#include "elements/entities/enemy.h"
#include "graphics/texture.h"
#include "scene/world_scene.h"

void enemy_vertical_move(enemy_t *enemy, sfVector2f *move, int speed)
{
    if (enemy->move_status == 1 && enemy->pos.y > enemy->pos_start.y + 200)
        enemy->move_status = 2;
    if (enemy->move_status == 2 && enemy->pos.y < enemy->pos_start.y)
        enemy->move_status = 1;
    if (enemy->move_status == 1)
        *move = (sfVector2f){0, speed};
    if (enemy->move_status == 2)
        *move = (sfVector2f){0, -speed};
}

void enemy_horizontal_move(enemy_t *enemy, sfVector2f *move, int speed)
{
    if (enemy->move_status == 1 && enemy->pos.x > enemy->pos_start.x + 200)
        enemy->move_status = 2;
    if (enemy->move_status == 2 && enemy->pos.x < enemy->pos_start.x)
        enemy->move_status = 1;
    if (enemy->move_status == 1)
        *move = (sfVector2f){speed, 0};
    if (enemy->move_status == 2)
        *move = (sfVector2f){-speed, 0};
}

void enemy_horizontal_update(entity_t *entity, infos_t *infos, float elapsed)
{
    enemy_t *enemy = (enemy_t *) entity;
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    sfVector2f move = (sfVector2f){0, 0};
    float speed = elapsed * 2;

    if (enemy->attack_cooldown >= 0)
        enemy->attack_cooldown -= elapsed;
    if (enemy->damage_time > 0) {
        enemy->damage_time -= elapsed;
        get_knockback_move(&move, enemy->dir, speed);
    } else
        enemy_horizontal_move(enemy, &move, speed);
    prior_map_collision(&move, enemy->hitbox, world_scene->map);
    prior_element_collision((element_t*) enemy, &move, enemy->hitbox, infos);
    enemy->move((element_t *) enemy, (sfVector2f) {enemy->pos.x + move.x,
        enemy->pos.y + move.y});
    walk_animation_set_anim_and_dir(&(enemy->anim), &enemy->dir, move, speed);
    living_walk_sprite_anim(enemy->sprite, enemy->dir, enemy->anim);
    enemy->attack(enemy, infos);
}

void enemy_vertical_update(entity_t *entity, infos_t *infos, float elapsed)
{
    enemy_t *enemy = (enemy_t *) entity;
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    sfVector2f move = (sfVector2f){0, 0};
    float speed = elapsed * 2;

    if (enemy->attack_cooldown >= 0)
        enemy->attack_cooldown -= elapsed;
    if (enemy->damage_time > 0) {
        enemy->damage_time -= elapsed;
        get_knockback_move(&move, enemy->dir, speed);
    } else
        enemy_vertical_move(enemy, &move, speed);
    prior_map_collision(&move, enemy->hitbox, world_scene->map);
    prior_element_collision((element_t*) enemy, &move, enemy->hitbox, infos);
    enemy->move((element_t *) enemy, (sfVector2f) {enemy->pos.x + move.x,
        enemy->pos.y + move.y});
    walk_animation_set_anim_and_dir(&(enemy->anim), &enemy->dir, move, speed);
    living_walk_sprite_anim(enemy->sprite, enemy->dir, enemy->anim);
    enemy->attack(enemy, infos);
}