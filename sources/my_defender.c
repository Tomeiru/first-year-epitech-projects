/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-mathieu.brujan
** File description:
** my_defender
*/

#include "../include/my_defender.h"

void draw_sprites_wo_speed(sfRenderWindow *window, entity_t *entity)
{
    sfSprite_setPosition(entity->sprite, entity->position);
    sfSprite_setTextureRect(entity->sprite, entity->texture_rect);
    sfRenderWindow_drawSprite(window, entity->sprite, NULL);
}

void update_mouse_info(game_t *game, sfRenderWindow *window)
{
    game->mouse_info->pos = sfMouse_getPositionRenderWindow(window);
}

void run_game(sfRenderWindow *window, game_t *game)
{
    while (sfRenderWindow_isOpen(window)) {
        update_mouse_info(game, window);
        while(sfRenderWindow_pollEvent(window, &game->event))
            analyse_event(game, window);
        scene_manager(window, game);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
}

int my_defender(void)
{
    sfView *view = create_view(1920, 1080);
    sfRenderWindow *window = create_window(1920, 1080, "MyDefender", view);
    game_t *game = ini_game_struct();

    run_game(window, game);
    return (0);
}