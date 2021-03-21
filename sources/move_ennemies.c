/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** move_ennemies
*/

#include "../include/my_defender.h"

void turn_to_face(ennemy_t *ennemy)
{
    if (ennemy->entity.position.x >= 1440 && ennemy->entity.position.x <= 1469 && ennemy->entity.position.y <= 480) {
        ennemy->entity.position.x = 1470;
        ennemy->entity.speed.x = 0;
        ennemy->entity.speed.y = ennemy->speed;
        ennemy->entity.texture_rect.top = 0;
    }
    if (ennemy->entity.position.x > 960 && ennemy->entity.position.x <= 990) {
        ennemy->entity.position.x = 990;
        ennemy->entity.speed.x = 0;
        ennemy->entity.speed.y = ennemy->speed;
        ennemy->entity.texture_rect.top = 0;
    }
    if (ennemy->entity.position.x > 480 && ennemy->entity.position.x <= 510) {
        ennemy->entity.position.x = 510;
        ennemy->entity.speed.x = 0;
        ennemy->entity.speed.y = ennemy->speed;
        ennemy->entity.texture_rect.top = 0;
    }
}

void turn_to_back(ennemy_t *ennemy)
{
    if (ennemy->entity.position.x > 1200 && ennemy->entity.position.x <= 1230) {
        ennemy->entity.position.x = 1230;
        ennemy->entity.speed.x = 0;
        ennemy->entity.speed.y = ennemy->speed * -1;
        ennemy->entity.texture_rect.top = 210;
    }
    if (ennemy->entity.position.x > 720 && ennemy->entity.position.x <= 750) {
        ennemy->entity.position.x = 750;
        ennemy->entity.speed.x = 0;
        ennemy->entity.speed.y = ennemy->speed * -1;
        ennemy->entity.texture_rect.top = 210;
    }
}

void turn_to_left(ennemy_t *ennemy)
{
    if (ennemy->entity.position.y <= 144) {
        ennemy->entity.position.y = 145;
        ennemy->entity.speed.y = 0;
        ennemy->entity.speed.x = ennemy->speed * -1;
        ennemy->entity.texture_rect.top = 70;
    }
    if (ennemy->entity.position.y >= 624) {
        ennemy->entity.position.y = 625;
        ennemy->entity.speed.y = 0;
        ennemy->entity.speed.x = ennemy->speed * -1;
        ennemy->entity.texture_rect.top = 70;
    }
    if (ennemy->entity.position.x <= 510 && ennemy->entity.position.y >= 385) {
        ennemy->entity.position.y = 385;
        ennemy->entity.speed.y = 0;
        ennemy->entity.speed.x = ennemy->speed * -1;
        ennemy->entity.texture_rect.top = 70;
    }
}

void move_mob(game_t *game, ennemy_t *ennemy)
{
    if (ennemy->entity.speed.x != 0) {
        turn_to_face(ennemy);
        turn_to_back(ennemy);
    } else if (ennemy->entity.speed.y != 0) {
        turn_to_left(ennemy);
    }
    ennemy->entity.position.x += ennemy->entity.speed.x * game->game_scene->wave.mul_speed;
    ennemy->entity.position.y += ennemy->entity.speed.y * game->game_scene->wave.mul_speed;
}