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

void player_attack(player_t *player, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    sfIntRect hit_hb = get_hit_hitbox(player->pos, player->dir);
    element_t *element;

    if (player->attack_cooldown > 0)
        return;
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

    player->damage_time = 15;
    player->health -= damage;
    health_bar_set_value(world_scene->hud->health_bar, player->health);
    sfSprite_setColor(player->sprite, (sfColor) {255, 127, 127, 255});
    if (hit_particle)
        scene_add_element(infos->scene, (element_t*) hit_particle, 1);
}

void player_get_move_from_keyboard(player_t *player,
sfVector2f *move, float *speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift) && player->stamina > 0)
        *speed *= 1.5;
    if (sfKeyboard_isKeyPressed(sfKeyZ) ^ sfKeyboard_isKeyPressed(sfKeyS))
        move->y = sfKeyboard_isKeyPressed(sfKeyZ) ? -*speed : *speed;
    if (sfKeyboard_isKeyPressed(sfKeyQ) ^ sfKeyboard_isKeyPressed(sfKeyD))
        move->x = sfKeyboard_isKeyPressed(sfKeyQ) ? -*speed : *speed;
    walk_animation_set_anim_and_dir(&(player->anim),
    &(player->dir), *move, *speed);
}

void player_stamina(player_t *player, infos_t *infos, float elapsed)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;

    if (sfKeyboard_isKeyPressed(sfKeyLShift) && player->stamina > 0) {
        player->stamina -= elapsed;
        bar_set_value(world_scene->hud->stamina_bar, player->stamina);
    } else {
        if (player->stamina <= 0) {
            player->stamina -= 0.5;
            if (player->stamina <= -20) {
                player->stamina = -player->stamina;
                bar_set_value(world_scene->hud->stamina_bar, player->stamina);
            } else
                bar_set_value(world_scene->hud->stamina_bar, -player->stamina);
        } else {
            player->stamina += 0.5;
            if (player->stamina > 100)
                player->stamina = 100;
            bar_set_value(world_scene->hud->stamina_bar, player->stamina);
        }
    }
}