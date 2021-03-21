/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-mathieu.brujan
** File description:
** ini_struct
*/

#include "../include/my_defender.h"

entity_t **ini_main_menu_entity_struct(void)
{
    entity_t **buttons = malloc(sizeof(entity_t *) * 5);

    for (int i = 0; i < 5; i++) {
        buttons[i] = malloc(sizeof(entity_t));
        buttons[i]->speed = create_float_vector(0, 0);
        if (i != 4)
            buttons[i]->texture_rect = create_int_rect(0, 0, 500, 100);
    }
    buttons[4]->texture_rect = create_int_rect(0, 0, 1920, 1080);
    buttons[4]->position = create_float_vector(0, 0);
    buttons[4]->sprite = filepath_to_sprite("assets/Buttons/Background_mm.png");
    buttons[0]->sprite = filepath_to_sprite("assets/Buttons/Play.png");
    buttons[1]->sprite = filepath_to_sprite("assets/Buttons/Tutorial.png");
    buttons[2]->sprite = filepath_to_sprite("assets/Buttons/Settings.png");
    buttons[3]->sprite = filepath_to_sprite("assets/Buttons/Quit.png");
    buttons[0]->position = create_float_vector(1266, 588);
    buttons[1]->position = create_float_vector(1266, 711);
    buttons[2]->position = create_float_vector(1266, 834);
    buttons[3]->position = create_float_vector(1266, 957);
    return (buttons);
}

entity_t **ini_game_scene_entities(void)
{
    entity_t **sprites = malloc(sizeof(entity_t *) * 9);
    int j = 178;

    for (int i = 0; i < 4; i++) {
        sprites[i] = malloc(sizeof(entity_t));
        sprites[i]->texture_rect = create_int_rect(0, 0, 1920, 1080);
        sprites[i]->speed = create_float_vector(0, 0);
        sprites[i]->position = create_float_vector(0, 0);
    }sprites[0]->sprite = filepath_to_sprite("assets/Map/map.png");
    sprites[1]->sprite = filepath_to_sprite("assets/Map/grid.png");
    sprites[2]->sprite = filepath_to_sprite("assets/Map/shop.png");
    sprites[3]->sprite = filepath_to_sprite("assets/Map/shop_stat.png");
    for (int i = 4; i < 9; i++) {
        sprites[i] = malloc(sizeof(entity_t));
        sprites[i]->texture_rect = create_int_rect(0, 0, 150, 150);
        sprites[i]->speed = create_float_vector(0, 0);
        sprites[i]->position = create_float_vector(j, 922);
        sprites[i]->sprite = filepath_to_sprite("assets/Map/Scroll.png");
        j += 263;
    }return (sprites);
}

char *ini_map_nbr(void)
{
    char *map_nbr = malloc(sizeof(char) * 106);

    map_nbr = my_strdup("111111111111111111000100011111111010101011111\
        000010101010000111110101010111111110001000111111111111111111");
    return (map_nbr);
}

game_scene_t *ini_game_scene_struct(void)
{
    game_scene_t *game_scene = malloc(sizeof(game_scene_t));

    game_scene->time_check_cycle = 0;
    game_scene->time_check_rec = 0;
    game_scene->gold = 10;
    game_scene->castle_pv = 0;
    game_scene->phase = 0;
    game_scene->gold_cycle = 0;
    game_scene->damage_cycle = 1;
    game_scene->time_cycle = 5;
    game_scene->entities = ini_game_scene_entities();
    game_scene->map_nbr = ini_map_nbr();
    game_scene->tower = NULL;
    return (game_scene);
}

game_t *ini_game_struct(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->scenes = ini_scene_struct();
    game->stats = ini_stats_struct();
    game->clock = ini_clock_struct();
    game->mouse_info = ini_mouse_struct();
    game->options = ini_options_struct();
    game->game_scene = ini_game_scene_struct();
    init_wave(game);
    init_ennemies_array(game);
    init_texts(game);
    return (game);
}