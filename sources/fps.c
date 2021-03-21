/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** fps
*/

#include "../include/my_defender.h"

void first_two_fps(entity_t **entities, mouse_t *mouse_info,
    game_t *game, sfRenderWindow *window)
{
    if (mouse_info->rpos.x >= entities[3]->position.x && mouse_info->rpos.x <=
        entities[3]->position.x + entities[3]->texture_rect.width) {
        sfSound_play(game->scenes[0]->sound[2]);
        game->options->fps = 0;
        sfRenderWindow_setFramerateLimit(window, 10);
    }
    if (mouse_info->rpos.x >= entities[4]->position.x && mouse_info->rpos.x <=
        entities[4]->position.x + entities[4]->texture_rect.width) {
        sfSound_play(game->scenes[0]->sound[2]);
        game->options->fps = 1;
        sfRenderWindow_setFramerateLimit(window, 30);
    }
}

void other_two_fps(entity_t **entities, mouse_t *mouse_info,
    game_t *game, sfRenderWindow *window)
{
    if (mouse_info->rpos.x >= entities[5]->position.x && mouse_info->rpos.x <=
        entities[5]->position.x + entities[5]->texture_rect.width) {
        sfSound_play(game->scenes[0]->sound[2]);
        game->options->fps = 2;
        sfRenderWindow_setFramerateLimit(window, 60);
    }
    if (mouse_info->rpos.x >= entities[6]->position.x && mouse_info->rpos.x <=
        entities[6]->position.x + entities[6]->texture_rect.width) {
        sfSound_play(game->scenes[0]->sound[2]);
        game->options->fps = 3;
        sfRenderWindow_setFramerateLimit(window, 120);
    }
}

void cursor_on_fps(entity_t **entities, mouse_t *mouse_info,
    game_t *game, sfRenderWindow *window)
{
    if (!(mouse_info->rpos.y >= entities[3]->position.y && mouse_info->rpos.y
        <= entities[3]->position.y + entities[3]->texture_rect.height * 2))
        return;
    if (mouse_info->rpos.y >= entities[3]->position.y && mouse_info->rpos.y <=
        entities[3]->position.y + entities[3]->texture_rect.height)
        first_two_fps(entities, mouse_info, game, window);
    else
        other_two_fps(entities, mouse_info, game, window);
}