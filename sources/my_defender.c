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

void update_mouse_info(game_t *game, sfRenderWindow *window, sfView *view)
{
    game->mouse_info->pos = sfMouse_getPositionRenderWindow(window);
    game->mouse_info->rpos = sfRenderWindow_mapPixelToCoords(window,
    game->mouse_info->pos, view);
}

void set_music_volume(game_t *game, float value)
{
    sfSound_setVolume(game->scenes[0]->sound[0], value);
}

void set_sound_volume(game_t *game, float value)
{
    sfSound_setVolume(game->scenes[0]->sound[1], value);
    sfSound_setVolume(game->scenes[0]->sound[2], value);
}

void volume_and_sound_check(game_t *game)
{
    float zero = 0;
    float hundred = 100;

    if (game->options->volume_off == 1 &&
    sfSound_getVolume(game->scenes[0]->sound[0]) != zero)
        set_music_volume(game, zero);
    if (game->options->volume_off == 0 &&
    sfSound_getVolume(game->scenes[0]->sound[0]) != hundred)
        set_music_volume(game, hundred);
    if (game->options->sound_off == 1 &&
    sfSound_getVolume(game->scenes[0]->sound[1]) != zero)
        set_sound_volume(game, zero);
    if (game->options->sound_off == 0 &&
    sfSound_getVolume(game->scenes[0]->sound[1]) != hundred)
        set_sound_volume(game, hundred);
}

void run_game(sfRenderWindow *window, game_t *game, sfView *view)
{
    while (sfRenderWindow_isOpen(window)) {
        update_mouse_info(game, window, view);
        while(sfRenderWindow_pollEvent(window, &game->event))
            analyse_event(game, window);
        scene_manager(window, game);
        volume_and_sound_check(game);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
}

int my_defender(void)
{
    sfView *view = create_view(1920, 1080);
    sfRenderWindow *window = create_window(1900, 1060, "MyDefender", view);
    game_t *game = ini_game_struct();

    run_game(window, game, view);
    return (0);
}