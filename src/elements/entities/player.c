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
    player->sprite = sprite;
    player->update = &player_update;
    player->can_move = 1;
    sprite_set_origin_center(sprite);
    element_set_hitbox(element, sfSprite_getGlobalBounds(sprite));
    return (player);
}

void player_update(entity_t *entity, infos_t *infos, float elapsed)
{
    player_t *player = (player_t*) entity;
    world_scene_t *world_scene = (world_scene_t*) infos->scene;

    player_move_update(player, world_scene->map, elapsed);
    element_behind_wall((element_t*) player, world_scene->map);
}

void player_move_update(player_t *player, map_t *map, float elapsed)
{
    sfVector2f move = {0, 0};
    float speed = 5 * elapsed;

    if (!player->can_move)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyZ) ^ sfKeyboard_isKeyPressed(sfKeyS))
        move.y = sfKeyboard_isKeyPressed(sfKeyZ) ? -speed : speed;
    if (sfKeyboard_isKeyPressed(sfKeyQ) ^ sfKeyboard_isKeyPressed(sfKeyD))
        move.x = sfKeyboard_isKeyPressed(sfKeyQ) ? -speed : speed;
    prior_map_collision(&move, player->hitbox, map);
    if (move.x == 0 && move.y == 0)
        return;
    player->move((element_t*) player, (sfVector2f)
    {player->pos.x + move.x, player->pos.y + move.y});
}