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

void draw_menu_buttons(sfRenderWindow *window, game_t *game)
{
    draw_sprites_wo_speed(window, game->scenes[0]->entities[0]);
    draw_sprites_wo_speed(window, game->scenes[0]->entities[1]);
    draw_sprites_wo_speed(window, game->scenes[0]->entities[2]);
    draw_sprites_wo_speed(window, game->scenes[0]->entities[3]);
}

int is_cursor_on_buttons(entity_t **entities, mouse_t *mouse_info)
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
    int value = is_cursor_on_buttons(entities, mouse_info);

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

void update_mouse_info(game_t *game, sfRenderWindow *window)
{
    game->mouse_info->pos = sfMouse_getPositionRenderWindow(window);
}

void event_main_menu(game_t *game, sfRenderWindow *window)
{
    int value = -1;

    if (game->stats->num_scene != MAIN_MENU)
        return;
    if (!(game->event.type == sfEvtMouseButtonReleased &&
    game->event.mouseButton.button == sfMouseLeft))
        return;
    value = is_cursor_on_buttons(game->scenes[0]->entities, game->mouse_info);
    if (value == 4)
        return;
    printf("Click on button %i\n", value);
    game->scenes[0]->entities[value]->texture_rect.left =
    game->scenes[0]->entities[0]->texture_rect.width * 2;
    if (value == 2)
        game->stats->num_scene = 1;
    if (value == 3)
        sfRenderWindow_close(window);
}

void event_options_menu(game_t *game, sfRenderWindow *window)
{
    if (game->stats->num_scene != OPTIONS)
        return;

}

void draw_options_buttons(game_t *game, sfRenderWindow *window)
{
    for (int i = 0; i < 12; i++)
        draw_sprites_wo_speed(window, game->scenes[1]->entities[i]);
}

void option_menu(sfRenderWindow *window, game_t *game)
{
    if (game->stats->num_scene != OPTIONS)
        return;
    draw_options_buttons(game, window);
}

void analyse_event(game_t *game, sfRenderWindow *window)
{
    event_main_menu(game, window);
    event_options_menu(game, window);
}

void scene_manager(sfRenderWindow *window, game_t *game)
{
    main_menu(window, game);
    option_menu(window, game);
}

void run_game(sfView *view, sfRenderWindow *window, game_t *game)
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

    run_game(view, window, game);
    return (0);
}