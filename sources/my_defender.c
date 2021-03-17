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
    value = is_cursor_on_buttons_menu(game->scenes[0]->entities,
    game->mouse_info);
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


void cursor_on_volume_sound(entity_t **entities, mouse_t *mouse_info,
options_t *options)
{
    if (!(mouse_info->pos.y >= entities[0]->position.y && mouse_info->pos.y <= 
    entities[0]->position.y + entities[0]->texture_rect.height))
        return;
    if (mouse_info->pos.x >= entities[0]->position.x && mouse_info->pos.x <= 
    entities[0]->position.x + entities[0]->texture_rect.width) {
        if (options->sound_off == 0)
            options->sound_off = 1;
        else
            options->sound_off = 0;
    }if (mouse_info->pos.x >= entities[1]->position.x && mouse_info->pos.x <= 
    entities[1]->position.x + entities[1]->texture_rect.width) {
        if (options->volume_off == 0)
            options->volume_off = 1;
        else
            options->volume_off = 0;
    }
}

void cursor_on_fps(entity_t **entities, mouse_t *mouse_info,
options_t *options, sfRenderWindow *window)
{
    if (!(mouse_info->pos.y >= entities[4]->position.y && mouse_info->pos.y <= 
    entities[4]->position.y + entities[4]->texture_rect.height))
        return;
    if (mouse_info->pos.x >= entities[4]->position.x && mouse_info->pos.x <= 
    entities[4]->position.x + entities[4]->texture_rect.width) {
        options->fps = 0;
        sfWindow_setFramerateLimit(window, 10);
    }if (mouse_info->pos.x >= entities[5]->position.x && mouse_info->pos.x <= 
    entities[5]->position.x + entities[5]->texture_rect.width) {
        options->fps = 1;
        sfWindow_setFramerateLimit(window, 30);
    }if (mouse_info->pos.x >= entities[6]->position.x && mouse_info->pos.x <= 
    entities[6]->position.x + entities[6]->texture_rect.width) {
        options->fps = 2;
        sfWindow_setFramerateLimit(window, 60);
    }if (mouse_info->pos.x >= entities[7]->position.x && mouse_info->pos.x <= 
    entities[7]->position.x + entities[7]->texture_rect.width) {
        options->fps = 3;
        sfWindow_setFramerateLimit(window, 120);
    }
}

void change_resolution(sfRenderWindow *window, int x)
{
    sfView *view;

    if (x == 0)
        view = create_view(480, 270);
    if (x == 1)
        view = create_view(960, 540);
    if (x == 2)
        view = create_view(1440, 810);
    if (x == 3)
        view = create_view(1920, 1080);
    sfRenderWindow_setView(window, view);
}

void cursor_on_resolution(entity_t **entities, mouse_t *mouse_info,
options_t *options, sfRenderWindow *window)
{
    if (!(mouse_info->pos.y >= entities[8]->position.y && mouse_info->pos.y <= 
    entities[8]->position.y + entities[8]->texture_rect.height))
        return;
    if (mouse_info->pos.x >= entities[8]->position.x && mouse_info->pos.x <= 
    entities[8]->position.x + entities[8]->texture_rect.width) {
        options->resolution = 0;
        change_resolution(window, 0);
    }if (mouse_info->pos.x >= entities[9]->position.x && mouse_info->pos.x <= 
    entities[9]->position.x + entities[9]->texture_rect.width) {
        options->resolution = 1;
        change_resolution(window, 1);
    }if (mouse_info->pos.x >= entities[10]->position.x && mouse_info->pos.x <= 
    entities[10]->position.x + entities[10]->texture_rect.width) {
        options->resolution = 2;
        change_resolution(window, 2);
    }if (mouse_info->pos.x >= entities[11]->position.x && mouse_info->pos.x <= 
    entities[11]->position.x + entities[11]->texture_rect.width) {
        options->resolution = 3;
        change_resolution(window, 3);
    }
}

void left_click_options_event(game_t *game, sfRenderWindow *window)
{
    cursor_on_volume_sound(game->scenes[1]->entities, game->mouse_info,
    game->options);
    cursor_on_fps(game->scenes[1]->entities, game->mouse_info,
    game->options, window);
    cursor_on_resolution(game->scenes[1]->entities, game->mouse_info,
    game->options, window);
}

void event_options_menu(game_t *game, sfRenderWindow *window)
{
    if (game->stats->num_scene != OPTIONS)
        return;
    if (game->event.type == sfEvtMouseButtonReleased &&
    game->event.mouseButton.button == sfMouseLeft)
        left_click_options_event(game, window);
    if (!(game->event.type == sfEvtKeyReleased &&
    game->event.key.code == sfKeyEscape))
        return;
    game->stats->num_scene = MAIN_MENU;
}

void draw_options_buttons(game_t *game, sfRenderWindow *window)
{
    draw_sprites_wo_speed(window, game->scenes[1]->entities[0]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[1]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[2]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[3]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[4]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[5]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[6]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[7]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[8]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[9]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[10]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[11]);
}

void adjust_rect_volume_sound(entity_t **entities, options_t *options)
{
    entities[0]->texture_rect.left = options->sound_off * 200;
    entities[1]->texture_rect.left = options->volume_off * 200;
}

void adjust_rect_fps(entity_t **entities, options_t *options)
{
    entities[4]->texture_rect.left = 100;
    entities[5]->texture_rect.left = 100;
    entities[6]->texture_rect.left = 100;
    entities[7]->texture_rect.left = 100;
    entities[options->fps + 4]->texture_rect.left = 0;
}

void adjust_rect_resolution(entity_t **entities, options_t *options)
{
    entities[8]->texture_rect.left = 100;
    entities[9]->texture_rect.left = 100;
    entities[10]->texture_rect.left = 100;
    entities[11]->texture_rect.left = 100;
    entities[options->resolution + 8]->texture_rect.left = 0;
}

void adjust_rect_options(entity_t **entities, options_t *options)
{
    adjust_rect_volume_sound(entities, options);
    adjust_rect_fps(entities, options);
    adjust_rect_resolution(entities, options);
}

void option_menu(sfRenderWindow *window, game_t *game)
{
    if (game->stats->num_scene != OPTIONS)
        return;
    adjust_rect_options(game->scenes[1]->entities, game->options);
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