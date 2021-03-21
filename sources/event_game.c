/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-mathieu.brujan
** File description:
** event_game
*/

#include "../include/my_defender.h"

void adjust_cycle(game_t *game)
{
    if (game->game_scene->phase == 1) {
        game->game_scene->gold_cycle += 5;
        game->game_scene->gold -= 10;
    }if (game->game_scene->phase == 2) {
        game->game_scene->damage_cycle += 5;
        game->game_scene->gold -= 10;
    }if (game->game_scene->phase == 3) {
        game->game_scene->time_cycle -= 0.25;
        game->game_scene->gold -= 10;
    }if (game->game_scene->phase == 4) {
        game->game_scene->damage_cycle += 15;
        game->game_scene->time_cycle -= 0.75;
        game->game_scene->gold -= 50;
    }if (game->game_scene->phase == 5) {
        game->game_scene->damage_cycle += 40;
        game->game_scene->time_cycle -= 2;
        game->game_scene->gold -= 100;
    }
}

sfSprite *apply_sprite_tower(int tower_type)
{
    sfSprite *sprite;

    if (tower_type == 1)
        sprite = filepath_to_sprite("assets/Towers/pawn.png");
    if (tower_type == 2)
        sprite = filepath_to_sprite("assets/Towers/knight.png");
    if (tower_type == 3)
        sprite = filepath_to_sprite("assets/Towers/bishop.png");
    if (tower_type == 4)
        sprite = filepath_to_sprite("assets/Towers/rook.png");
    if (tower_type == 5)
        sprite = filepath_to_sprite("assets/Towers/queen.png");
    return (sprite);
}

void create_tower(game_t *game, int x, int tower_type)
{
    tower_t *new_tower = malloc(sizeof(tower_t));

    new_tower->sprite = apply_sprite_tower(tower_type);
    new_tower->texture_rect = create_int_rect(0, 0, 120, 120);
    new_tower->position = create_float_vector((x % 15 + 1) * 120, x / 15 * 120);
    if (game->game_scene->tower == NULL) {
        new_tower->next = NULL;
        game->game_scene->tower = new_tower;
    }else {
        new_tower->next = game->game_scene->tower;
        game->game_scene->tower = new_tower;
    }
}

void check_placement(game_t *game)
{
    int x = 0;

    if (game->game_scene->phase == 0 || game->mouse_info->rpos.y > (float)840 ||
    game->mouse_info->rpos.x < (float)120)
        return;
    x = ((int)game->mouse_info->rpos.x - 120) / 120;
    x += ((int)game->mouse_info->rpos.y / 120 * 15);
    if (game->game_scene->map_nbr[x] != '1')
        return;
    adjust_cycle(game);
    create_tower(game, x, game->game_scene->phase);
    game->game_scene->map_nbr[x] = 0;
    game->game_scene->phase = 0;
}

void event_game(game_t *game, sfRenderWindow *window)
{
    if (game->stats->num_scene != GAME)
        return;
    if (!(game->event.type == sfEvtMouseButtonReleased))
        return;
    check_shop(game, game->mouse_info, game->game_scene->entities);
    check_placement(game);
}