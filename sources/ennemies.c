/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** ennemies
*/

#include "../include/my_defender.h"

void init_ennemies_array_second(game_t *game)
{
    game->game_scene->ennemies_types[1].attack = 15;
    game->game_scene->ennemies_types[1].gold = 10;
    game->game_scene->ennemies_types[1].HP = 25;
    game->game_scene->ennemies_types[1].speed = 1;
    game->game_scene->ennemies_types[2].entity.sprite =
        filepath_to_sprite("assets/Ennemies/assasin.png");
    game->game_scene->ennemies_types[2].entity.texture_rect =
        (sfIntRect){0, 70, 60, 70};
    game->game_scene->ennemies_types[2].attack = 5;
    game->game_scene->ennemies_types[2].gold = 10;
    game->game_scene->ennemies_types[2].HP = 10;
    game->game_scene->ennemies_types[2].speed = 5;
}

void init_ennemies_array(game_t *game)
{
    game->game_scene->ennemies_types = malloc(sizeof(ennemy_t) * 3);
    game->game_scene->ennemies_types[0].entity.sprite =
        filepath_to_sprite("assets/Ennemies/assasin.png");
    game->game_scene->ennemies_types[0].entity.texture_rect =
        (sfIntRect){0, 70, 60, 70};
    game->game_scene->ennemies_types[0].attack = 2;
    game->game_scene->ennemies_types[0].gold = 10;
    game->game_scene->ennemies_types[0].HP = 10;
    game->game_scene->ennemies_types[0].speed = 10;
    game->game_scene->ennemies_types[1].entity.sprite =
        filepath_to_sprite("assets/Ennemies/assasin.png");
    game->game_scene->ennemies_types[1].entity.texture_rect =
        (sfIntRect){0, 70, 60, 70};
    init_ennemies_array_second(game);
}

void draw_mob(sfRenderWindow *window, ennemy_t *ennemy)
{
    if (ennemy->display == 1) {
        sfSprite_setPosition(ennemy->entity.sprite, ennemy->entity.position);
        sfSprite_setTextureRect(ennemy->entity.sprite,
            ennemy->entity.texture_rect);
        sfRenderWindow_drawSprite(window, ennemy->entity.sprite, NULL);
    }
}

void mob_attack(game_t *game, ennemy_t *ennemy)
{
    if (ennemy->display == 0)
        return;
    ennemy->entity.speed = (sfVector2f){0, 0};
    game->game_scene->castle_pv -= ennemy->attack *
        game->game_scene->wave.mul_damage;
    ennemy->display = 0;
    game->game_scene->wave.nbr_ennemies--;
}

void create_mob(game_t *game)
{
    int type = rand() % 3;
    ennemy_t *new_ennemy = malloc(sizeof(ennemy_t));

    new_ennemy->display = 1;
    new_ennemy->attack = game->game_scene->ennemies_types[type].attack;
    new_ennemy->HP = game->game_scene->ennemies_types[type].HP;
    new_ennemy->speed = game->game_scene->ennemies_types[type].speed;
    new_ennemy->gold = game->game_scene->ennemies_types[type].gold;
    new_ennemy->entity.sprite =
        game->game_scene->ennemies_types[type].entity.sprite;
    new_ennemy->entity.texture_rect =
        game->game_scene->ennemies_types[type].entity.texture_rect;
    new_ennemy->entity.position = (sfVector2f){1830, 385};
    new_ennemy->entity.speed = (sfVector2f){new_ennemy->speed * -1, 0};
    new_ennemy->next = game->game_scene->ennemies;
    game->game_scene->ennemies = new_ennemy;
    game->game_scene->wave.mobs_spawned += 1;
    game->game_scene->wave.nbr_ennemies += 1;
    return;
}