/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** init_structures
*/

#include "../include/my_defender.h"

clocks_t *ini_clock_struct(void)
{
    clocks_t *clock = malloc(sizeof(clocks_t));

    clock->clock = sfClock_create();
    return (clock);
}

scene_t **ini_scene_struct(void)
{
    scene_t **scenes = malloc(sizeof(scene_t *) * 2);

    for (int i = 0; i < 2; i++)
        scenes[i] = malloc(sizeof(scene_t));
    scenes[0]->entities = ini_main_menu_entity_struct();
    scenes[0]->sound = ini_audio_main_menu();
    scenes[0]->sound_started = generate_sound_started();
    scenes[1]->entities = ini_option_entity_struct();
    return (scenes);
}

stats_t *ini_stats_struct()
{
    stats_t *stats = malloc(sizeof(stats_t));

    stats->num_scene = MAIN_MENU;
    stats->score = 0;
    stats->tuto = filepath_to_sprite("assets/tuto.png");
    stats->game_over = filepath_to_sprite("assets/gameover.png");
    return (stats);
}

mouse_t *ini_mouse_struct(void)
{
    mouse_t *mouse_info = malloc(sizeof(mouse_t));

    mouse_info->pos.x = 0;
    mouse_info->pos.y = 0;
    return (mouse_info);
}