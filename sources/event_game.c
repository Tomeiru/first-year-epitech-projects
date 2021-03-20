/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-mathieu.brujan
** File description:
** event_game
*/

#include "../include/my_defender.h"

void event_game(game_t *game, sfRenderWindow *window)
{
    if (game->stats->num_scene != GAME)
        return;
    if (game->event.type == sfEvtKeyReleased &&
    game->event.key.code == sfKeyEscape)
        game->stats->num_scene = 3;
}