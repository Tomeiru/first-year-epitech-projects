/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** player movements
*/

#include <math.h>
#include "my_rpg.h"
#include "elements/entities/player.h"
#include "scene/world_scene.h"
#include "graphics/texture.h"

void player_move_update(player_t *player,
map_t *map, infos_t *infos, float elapsed)
{
    sfVector2f move = {0, 0};
    float speed = player->speed * elapsed;

    if (!player->can_move &&
    (player->mov_target.x == -1 || player->mov_target.y == -1))
        return;
    if (player->damage_time > 0)
        get_knockback_move(&move, player->dir, speed);
    else if (player->mov_target.x != -1 && player->mov_target.y != -1)
        player_move_to_target(player, &move, speed);
    else
        player_get_move_from_keyboard(player, &move, &speed, elapsed);
    prior_map_collision(&move, player->hitbox, map);
    if (player->mov_target.x == -1 || player->mov_target.y == -1)
        player_prior_element_collision((element_t*) player,
    &move, player->hitbox, infos);
    if (move.x == 0 && move.y == 0)
        return;
    player->move((element_t*) player, (sfVector2f)
    {player->pos.x + move.x, player->pos.y + move.y});
}

void player_move_to_target(player_t *player, sfVector2f *move, float speed)
{
    sfVector2f diff = (sfVector2f) {player->mov_target.x - player->pos.x,
    player->mov_target.y - player->pos.y};
    sfVector2f new_move = vector_normalize(diff);

    new_move.x *= speed;
    new_move.y *= speed;
    walk_animation_set_anim_and_dir(&(player->anim),
    &(player->dir), new_move, speed);
    if (fabs(diff.x) <= fabs(new_move.x) && fabs(diff.y) <= fabs(new_move.y)) {
        move->x = diff.x;
        move->y = diff.y;
        player->mov_target = (sfVector2f) {-1, -1};
    } else {
        move->x = new_move.x;
        move->y = new_move.y;
    }
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