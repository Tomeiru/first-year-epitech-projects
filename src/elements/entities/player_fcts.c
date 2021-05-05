/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** player fcts
*/

#include "my_rpg.h"
#include "elements/entities/player.h"
#include "scene/world_scene.h"
#include "graphics/texture.h"

void player_move_update(player_t *player,
map_t *map, infos_t *infos, float elapsed)
{
    sfVector2f move = {0, 0};
    float speed = player->speed * elapsed;

    if (!player->can_move)
        return;
    if (player->damage_time > 0)
        get_knockback_move(&move, player->dir, speed);
    else
        player_get_move_from_keyboard(player, &move, &speed);
    prior_map_collision(&move, player->hitbox, map);
    player_prior_element_collision((element_t*) player,
    &move, player->hitbox, infos);
    if (move.x == 0 && move.y == 0)
        return;
    player->move((element_t*) player, (sfVector2f)
    {player->pos.x + move.x, player->pos.y + move.y});
}

void player_damage(player_t *player, float damage, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;

    player->damage_time = 15;
    player->health -= damage;
    health_bar_set_value(world_scene->hud->health_bar, player->health);
    sfSprite_setColor(player->sprite, (sfColor) {255, 127, 127, 255});
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