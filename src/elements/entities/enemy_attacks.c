/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** enemy attacks
*/

#include <math.h>
#include "my_rpg.h"
#include "elements/entities/enemy.h"
#include "elements/entities/projectile.h"
#include "graphics/texture.h"
#include "scene/world_scene.h"

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
        angle, 6, get_texture(infos, ROCK_TEXT));
        scene_add_element((scene_t*) world_scene, (element_t*) projectile, 1);
    }
}

void enemy_close_attack(enemy_t *enemy, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    sfVector2f player_pos = world_scene->player->pos;
    float distance = get_distance(enemy->pos, player_pos);

    if (distance <= 100 && enemy->attack_cooldown <= 0) {
        enemy->attack_cooldown = 100;
        enemy->move_status = 0;
        player_damage(world_scene->player, 1, infos);
    } else if (distance > 50 && enemy->move_status == 0)
        enemy->move_status = 1;
}