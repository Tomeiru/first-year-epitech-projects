/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** resolution
*/

#include "../include/my_defender.h"

void change_resolution(sfRenderWindow *window, int x)
{
    if (x == 0)
        sfRenderWindow_setSize(window, create_unsigned_vector(480, 270));
    if (x == 1)
        sfRenderWindow_setSize(window, create_unsigned_vector(960, 540));
    if (x == 2)
        sfRenderWindow_setSize(window, create_unsigned_vector(1440, 810));
    if (x == 3)
        sfRenderWindow_setSize(window, create_unsigned_vector(1920, 1080));
}

void first_two_resolution(entity_t **entities, mouse_t *mouse_info,
    game_t *game, sfRenderWindow *window)
{
    if (mouse_info->rpos.x >= entities[7]->position.x && mouse_info->rpos.x <=
        entities[7]->position.x + entities[7]->texture_rect.width) {
        sfSound_play(game->scenes[0]->sound[2]);
        game->options->resolution = 0;
        change_resolution(window, 0);
    }
    if (mouse_info->rpos.x >= entities[8]->position.x && mouse_info->rpos.x <=
        entities[8]->position.x + entities[8]->texture_rect.width) {
        sfSound_play(game->scenes[0]->sound[2]);
        game->options->resolution = 1;
        change_resolution(window, 1);
    }
}

void other_two_resolution(entity_t **entities, mouse_t *mouse_info,
    game_t *game, sfRenderWindow *window)
{
    if (mouse_info->rpos.x >= entities[9]->position.x && mouse_info->rpos.x
        <= entities[9]->position.x + entities[9]->texture_rect.width) {
        sfSound_play(game->scenes[0]->sound[2]);
        game->options->resolution = 2;
        change_resolution(window, 2);
    }
    if (mouse_info->rpos.x >= entities[10]->position.x && mouse_info->rpos.x
        <= entities[10]->position.x + entities[10]->texture_rect.width) {
        sfSound_play(game->scenes[0]->sound[2]);
        game->options->resolution = 3;
        change_resolution(window, 3);
    }
}

void cursor_on_resolution(entity_t **entities, mouse_t *mouse_info,
    game_t *game, sfRenderWindow *window)
{
    if (!(mouse_info->rpos.y >= entities[7]->position.y && mouse_info->rpos.y <=
    entities[7]->position.y + entities[7]->texture_rect.height * 2))
        return;
    if (mouse_info->rpos.y >= entities[7]->position.y && mouse_info->rpos.y <=
    entities[7]->position.y + entities[7]->texture_rect.height)
        first_two_resolution(entities, mouse_info, game, window);
    else
        other_two_resolution(entities, mouse_info, game, window);
}