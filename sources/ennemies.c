/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** ennemies
*/

#include "../include/my_defender.h"

void init_ennemies_array(game_t *game)
{
    game->game_scene->ennemies_types = malloc(sizeof(ennemy_t) * 3);
    game->game_scene->ennemies_types[0].entity.sprite = filepath_to_sprite("assets/Ennemies/assasin.png");
    game->game_scene->ennemies_types[0].entity.texture_rect = (sfIntRect){0, 210, 60, 70};
    game->game_scene->ennemies_types[0].attack = 2;
    game->game_scene->ennemies_types[0].gold = 10;
    game->game_scene->ennemies_types[0].HP = 10;
    game->game_scene->ennemies_types[0].speed = 100;
    game->game_scene->ennemies_types[1].entity.sprite = filepath_to_sprite("assets/Ennemies/assasin.png");
    game->game_scene->ennemies_types[1].entity.texture_rect = (sfIntRect){0, 210, 60, 70};
    game->game_scene->ennemies_types[1].attack = 100;
    game->game_scene->ennemies_types[1].gold = 10;
    game->game_scene->ennemies_types[1].HP = 100;
    game->game_scene->ennemies_types[1].speed = 2;
    game->game_scene->ennemies_types[2].entity.sprite = filepath_to_sprite("assets/Ennemies/assasin.png");
    game->game_scene->ennemies_types[2].entity.texture_rect = (sfIntRect){0, 210, 60, 70};
    game->game_scene->ennemies_types[2].attack = 10;
    game->game_scene->ennemies_types[2].gold = 10;
    game->game_scene->ennemies_types[2].HP = 10;
    game->game_scene->ennemies_types[2].speed = 10;
}//OK, run in setup

void draw_mob(sfRenderWindow *window, entity_t *entity)
{
    sfSprite_setPosition(entity->sprite, entity->position);
    sfSprite_setTextureRect(entity->sprite, entity->texture_rect);
    sfRenderWindow_drawSprite(&window, entity->sprite, NULL);
}//???

void mob_attack(game_t *game, ennemy_t ennemy)
{
    game->game_scene->castle_pv -= ennemy.attack * game->game_scene->wave.mul_damage;
}

void move_mob(game_t *game)
{
    //adjust to map
}

void create_mob(game_t *game)
{
    int type = rand() % 3;
    ennemy_t *new_ennemy = malloc(sizeof(ennemy_t));

    new_ennemy->attack = game->game_scene->ennemies_types[type].attack;
    new_ennemy->HP = game->game_scene->ennemies_types[type].HP;
    new_ennemy->speed = game->game_scene->ennemies_types[type].speed;
    new_ennemy->gold = game->game_scene->ennemies_types[type].gold;
    new_ennemy->entity.sprite = game->game_scene->ennemies_types[type].entity.sprite;
    new_ennemy->entity.texture_rect = game->game_scene->ennemies_types[type].entity.texture_rect;
    new_ennemy->entity.position = (sfVector2f){0, 0}; //adjust to map
    new_ennemy->entity.speed = (sfVector2f){0, new_ennemy->speed};
    return;
}

void gestion_mobs()
{
    //if spawned mobs < 10 + index / 2 && freq spawn OK
        //create_mob(game);
    //for i in mobs
        //if i.position = end way position
            //attaque()
        //else
            //avance()
        //draw_mob(window, mob)
    return;
}