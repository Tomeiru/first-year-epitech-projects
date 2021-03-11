/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-mathieu.brujan
** File description:
** ini_struct
*/

#include "my_defender.h"

clock_t *ini_clock_struct(void)
{
    clock_t *clock = malloc(sizeof(clock_t));
    return (clock);
}

sfVector2f create_float_vector(int x, int y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfIntRect create_int_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfSprite *filepath_to_sprite(char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

entity_t **ini_main_menu_entity_struct(void)
{
    entity_t **buttons = malloc(sizeof(entity_t *) * 4);

    for (int i = 0; i < 4; i++) {
        buttons[i] = malloc(sizeof(entity_t));
        buttons[i]->texture_rect = create_int_rect(0, 0, 500, 100);
        buttons[i]->speed = create_float_vector(0, 0);
    }buttons[0]->sprite = filepath_to_sprite("assets/Buttons/Play.png");
    buttons[1]->sprite = filepath_to_sprite("assets/Buttons/Tutorial.png");
    buttons[2]->sprite = filepath_to_sprite("assets/Buttons/Settings.png");
    buttons[3]->sprite = filepath_to_sprite("assets/Buttons/Quit.png");
    buttons[0]->position = create_float_vector(710, 565);
    buttons[1]->position = create_float_vector(710, 688);
    buttons[2]->position = create_float_vector(710, 811);
    buttons[3]->position = create_float_vector(710, 934);
    return (buttons);
}

scene_t **ini_scene_struct(void)
{
    scene_t **scenes = malloc(sizeof(scene_t *) * 1);
    scenes[0] = malloc(sizeof(scene_t));
    scenes[0]->entities = ini_main_menu_entity_struct();
    return (scenes);
}

stats_t *ini_stats_struct()
{
    stats_t *stats = malloc(sizeof(stats_t));

    stats->num_scene = MAIN_MENU;
    stats->score = 0;
    return (stats);
}

game_t *ini_game_struct(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->scenes = ini_scene_struct();
    game->stats = ini_stats_struct();
    game->clock = ini_clock_struct();
    return (game);
}