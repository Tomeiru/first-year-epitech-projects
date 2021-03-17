/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** main_menu
*/

#include "../include/my_defender.h"

void draw_menu_buttons(sfRenderWindow *window, game_t *game)
{
    draw_sprites_wo_speed(window, game->scenes[0]->entities[0]);
    draw_sprites_wo_speed(window, game->scenes[0]->entities[1]);
    draw_sprites_wo_speed(window, game->scenes[0]->entities[2]);
    draw_sprites_wo_speed(window, game->scenes[0]->entities[3]);
}

int is_cursor_on_buttons_menu(entity_t **entities, mouse_t *mouse_info)
{
    if (!(mouse_info->pos.x >= entities[0]->position.x && mouse_info->pos.x <= 
    entities[0]->position.x + entities[0]->texture_rect.width))
        return (4);
    if (mouse_info->pos.y >= entities[0]->position.y && mouse_info->pos.y <= 
    entities[0]->position.y + entities[0]->texture_rect.height)
        return (0);
    if (mouse_info->pos.y >= entities[1]->position.y && mouse_info->pos.y <= 
    entities[1]->position.y + entities[1]->texture_rect.height)
        return (1);
    if (mouse_info->pos.y >= entities[2]->position.y && mouse_info->pos.y <= 
    entities[2]->position.y + entities[2]->texture_rect.height)
        return (2);
    if (mouse_info->pos.y >= entities[3]->position.y && mouse_info->pos.y <= 
    entities[3]->position.y + entities[3]->texture_rect.height)
        return (3);
    return (4);
}

void highlight_menu_buttons(entity_t **entities, mouse_t *mouse_info)
{
    int value = is_cursor_on_buttons_menu(entities, mouse_info);

    entities[0]->texture_rect.left = 0;
    entities[1]->texture_rect.left = 0;
    entities[2]->texture_rect.left = 0;
    entities[3]->texture_rect.left = 0;
    if (value == 4)
        return;
    entities[value]->texture_rect.left = entities[0]->texture_rect.width;
}

void main_menu(sfRenderWindow *window, game_t *game)
{
    if (game->stats->num_scene != MAIN_MENU)
        return;
    highlight_menu_buttons(game->scenes[0]->entities, game->mouse_info);
    draw_menu_buttons(window, game);
}