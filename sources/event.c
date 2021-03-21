/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** event
*/

#include "../include/my_defender.h"

void event_tuto(game_t *game)
{
    if (game->stats->num_scene != TUTO)
        return;
    if (game->event.type == sfEvtKeyReleased &&
        game->event.key.code == sfKeyEscape)
        game->stats->num_scene = MAIN_MENU;
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
    sfSound_play(game->scenes[0]->sound[1]);
    if (value == 0) {
        game->stats->num_scene = 2;
        sfSound_stop(game->scenes[0]->sound[0]);
    }
    if (value == 2)
        game->stats->num_scene = 1;
    if (value == 3)
        sfRenderWindow_close(window);
    if (value == 1)
        game->stats->num_scene = TUTO;
}

void analyse_event(game_t *game, sfRenderWindow *window)
{
    if ((game->event.type == sfEvtKeyReleased && game->event.key.code == sfKeyQ)
        || game->event.type == sfEvtClosed )
        sfRenderWindow_close(window);
    event_main_menu(game, window);
    event_options_menu(game, window);
    event_game(game, window);
    event_tuto(game);
}