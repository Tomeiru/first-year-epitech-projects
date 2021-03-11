/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-mathieu.brujan
** File description:
** my_defender
*/

#include "my_defender.h"

sfRenderWindow *create_window(int width, int height, char *window_name,
sfView *view)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window;
    
    window = sfRenderWindow_create(mode, window_name, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setView(window, view);
    return (window);
}

sfFloatRect create_float_rect(float top, float left, float width, float height)
{
    sfFloatRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfView *create_view(float width, float height)
{
    sfFloatRect view_rect = create_float_rect(0, 0, width, height);
    sfView *view = sfView_createFromRect(view_rect);

    return (view);
}

void draw_sprites_wo_speed(sfRenderWindow *window, entity_t *entity)
{
    sfSprite_setPosition(entity->sprite, entity->position);
    sfSprite_setTextureRect(entity->sprite, entity->texture_rect);
    sfRenderWindow_drawSprite(window, entity->sprite, NULL);
}

void main_menu(sfView *view, sfRenderWindow *window, game_t *game)
{
    draw_sprites_wo_speed(window, game->scenes[0]->entities[0]);
    draw_sprites_wo_speed(window, game->scenes[0]->entities[1]);
    draw_sprites_wo_speed(window, game->scenes[0]->entities[2]);
    draw_sprites_wo_speed(window, game->scenes[0]->entities[3]);
}

void run_game(sfView *view, sfRenderWindow *window, game_t *game)
{
    while (sfRenderWindow_isOpen(window)) {
        if (game->stats->num_scene == 0)
            main_menu(view, window, game);
        sfRenderWindow_display(window);
    }
}

int my_defender(void)
{
    sfView *view = create_view(1920, 1080);
    sfRenderWindow *window = create_window(1920, 1080, "MyDefender", view);
    game_t *game = ini_game_struct();

    run_game(view, window, game);
    return (0);
}