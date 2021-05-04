/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** player
*/

#include "my_rpg.h"
#include "elements/entities/player.h"
#include "scene/world_scene.h"
#include "graphics/texture.h"

player_t *player_create(infos_t *infos)
{
    element_t *element = element_create_default(sizeof(player_t),
    PLAYER, (sfVector2f) {0, 0});
    player_t *player = (player_t*) element;
    sfSprite *sprite = sfSprite_create();

    if (!player || !sprite)
        return (NULL);
    sfSprite_setTexture(sprite, get_texture(infos, PLAYER_TEXT), 0);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 64, 64});
    player->sprite = sprite;
    player->update = &player_update;
    player->health = 6;
    player->max_health = 6;
    player->speed = 3;
    player->can_move = 1;
    player->anim = 0;
    player->dir = NORTH;
    player->damage_time = 0;
    sprite_set_origin_center(sprite);
    element_set_hitbox(element, sfSprite_getGlobalBounds(sprite));
    return (player);
}

void player_update(entity_t *entity, infos_t *infos, float elapsed)
{
    player_t *player = (player_t*) entity;
    world_scene_t *world_scene = (world_scene_t*) infos->scene;

    if (player->damage_time > 0)
        player->damage_time -= elapsed;
    player_move_update(player, world_scene->map, infos, elapsed);
    element_behind_wall((element_t*) player, world_scene->map);
    living_walk_sprite_anim(player->sprite, player->dir, player->anim);
}

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
}

void player_get_move_from_keyboard(player_t *player,
sfVector2f *move, float *speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        *speed *= 1.5;
    if (sfKeyboard_isKeyPressed(sfKeyZ) ^ sfKeyboard_isKeyPressed(sfKeyS))
        move->y = sfKeyboard_isKeyPressed(sfKeyZ) ? -*speed : *speed;
    if (sfKeyboard_isKeyPressed(sfKeyQ) ^ sfKeyboard_isKeyPressed(sfKeyD))
        move->x = sfKeyboard_isKeyPressed(sfKeyQ) ? -*speed : *speed;
    walk_animation_set_anim_and_dir(&(player->anim),
    &(player->dir), *move, *speed);
}