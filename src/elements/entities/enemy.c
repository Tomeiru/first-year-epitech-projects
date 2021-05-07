/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** enemy
*/

#include <math.h>
#include "my_rpg.h"
#include "graphics/texture.h"
#include "scene/world_scene.h"
#include "elements/entities/enemy.h"
#include "elements/entities/projectile.h"
#include "elements/entities/particles/hit_particle.h"

static void enemy_init(enemy_t *enemy)
{
    enemy->update = &enemy_default_update;
    enemy->health = 2;
    enemy->speed = 2;
    enemy->pos_start = enemy->pos;
    enemy->dist = 100;
    enemy->move_status = 1;
    enemy->attack_cooldown = 0;
    enemy->dir = SOUTH;
    enemy->anim = 0;
    enemy->damage_time = 0;
}

enemy_t *enemy_create(size_t size,
infos_t *infos, sfVector2f pos, texture_t texture)
{
    element_t *element = element_create_default(size, ENEMY, pos);
    enemy_t *enemy = (enemy_t *) element;
    sfSprite *sprite = sfSprite_create();

    if (!enemy || !sprite)
        return(NULL);
    sfSprite_setTexture(sprite, get_texture(infos, texture), 0);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 64, 64});
    enemy->sprite = sprite;
    enemy_init(enemy);
    sprite_set_origin_center(sprite);
    element_set_hitbox(element, sfSprite_getGlobalBounds(sprite));
    return (enemy);
}

void enemy_default_update(entity_t *entity, infos_t *infos, float elapsed)
{
    enemy_t *enemy = (enemy_t *) entity;
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    sfVector2f move = (sfVector2f) {0, 0};
    float speed = enemy->speed * elapsed;

    if (enemy->attack_cooldown >= 0)
        enemy->attack_cooldown -= elapsed;
    if (enemy->damage_time > 0) {
        enemy->damage_time -= elapsed;
        if (enemy->damage_time <= 0)
            sfSprite_setColor(enemy->sprite, (sfColor) {255, 255, 255, 255});
    } else
        enemy->pattern(enemy, &move, infos, speed);
    prior_map_collision(&move, enemy->hitbox, world_scene->map);
    prior_element_collision((element_t*) enemy, &move, enemy->hitbox, infos);
    walk_animation_set_anim_and_dir(&(enemy->anim), &enemy->dir, move, speed);
    enemy->move((element_t *) enemy,
    (sfVector2f) {enemy->pos.x + move.x, enemy->pos.y + move.y});
    living_walk_sprite_anim(enemy->sprite, enemy->dir, enemy->anim);
    enemy->attack(enemy, infos);
}

void enemy_take_damage(enemy_t *enemy, int damage, infos_t *infos)
{
    hit_particle_t *hit_particle = hit_particle_create((element_t*) enemy);
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    bar_t *exp_bar = world_scene->inventory->exp_bar;

    enemy->damage_time = 15;
    enemy->health -= damage;
    sfSprite_setColor(enemy->sprite, (sfColor) {255, 127, 127, 255});
    if (hit_particle)
        scene_add_element(infos->scene, (element_t*) hit_particle, 1);
    if (enemy->health <= 0) {
        scene_remove_element(infos->scene, (element_t*) enemy, 1);
        bar_set_value(exp_bar, exp_bar->value + 10);
        if (exp_bar->value == exp_bar->max)
            player_level_up(world_scene->player, infos);
    }
}