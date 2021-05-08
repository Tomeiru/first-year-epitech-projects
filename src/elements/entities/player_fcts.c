/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** player fcts
*/

#include "my_rpg.h"
#include "graphics/texture.h"
#include "scene/world_scene.h"
#include "elements/entities/enemy.h"
#include "elements/entities/player.h"
#include "elements/entities/particles/hit_particle.h"
#include "audio/sound.h"

void player_attack(player_t *player, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    sfIntRect hit_hb = get_hit_hitbox(player->pos, player->dir);
    element_t *element;

    if (player->attack_cooldown > 0)
        return;
    play_sound(infos, SWORD_SLASH);
    player->can_move = 1;
    player->anim = 120;
    player->attack_cooldown = 10;
    element = element_collision((element_t*) player,
    hit_hb, world_scene->entities);
    if (!element || element->type != ENEMY)
        return;
    enemy_take_damage((enemy_t*) element, 1, infos);
}

void player_damage(player_t *player, float damage, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    hit_particle_t *hit_particle = hit_particle_create((element_t*) player);

    play_sound(infos, HIT);
    player->damage_time = 15;
    player->health -= damage;
    health_bar_set_value(world_scene->hud->health_bar, player->health);
    sfSprite_setColor(player->sprite, (sfColor) {255, 127, 127, 255});
    if (hit_particle)
        scene_add_element(infos->scene, (element_t*) hit_particle, 1);
}

void player_get_move_from_keyboard(player_t *player,
sfVector2f *move, float *speed, float elapsed)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift) && player->stamina > 0) {
        *speed *= 1.5;
        player->stamina -= elapsed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) ^ sfKeyboard_isKeyPressed(sfKeyS))
        move->y = sfKeyboard_isKeyPressed(sfKeyZ) ? -*speed : *speed;
    if (sfKeyboard_isKeyPressed(sfKeyQ) ^ sfKeyboard_isKeyPressed(sfKeyD))
        move->x = sfKeyboard_isKeyPressed(sfKeyQ) ? -*speed : *speed;
    walk_animation_set_anim_and_dir(&(player->anim),
    &(player->dir), *move, *speed);
}

void player_stamina(player_t *player, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;

    if (player->stamina <= 0) {
        player->stamina -= 0.5;
        if (player->stamina <= -50)
            player->stamina = -player->stamina;
    } else {
        player->stamina += 0.5;
        if (player->stamina > 100)
            player->stamina = 100;
    }
    if (player->stamina < 0) {
        bar_set_color(world_scene->hud->stamina_bar, RED_BAR);
        bar_set_value(world_scene->hud->stamina_bar, -player->stamina);
    } else {
        bar_set_color(world_scene->hud->stamina_bar, GREEN_BAR);
        bar_set_value(world_scene->hud->stamina_bar, player->stamina);
    }
}

void player_level_up(player_t *player, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    bar_t *exp_bar = world_scene->inventory->exp_bar;
    health_bar_t *health_bar = world_scene->hud->health_bar;
    float value = exp_bar->value - exp_bar->max;

    play_sound(infos, LEVEL_UP);
    exp_bar->max *= 1.5;
    bar_set_value(exp_bar, value);
    if (player->max_health < MAX_HEALTH) {
        player->max_health += 2;
        player->health = player->max_health;
        health_bar_update_values(health_bar, player);
    }
}