/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** sound
*/

#include "../include/my_defender.h"

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

sfSound **ini_audio_main_menu(void)
{
    sfSound **sound = malloc(sizeof(sfSound *) * 3);

    sound[0] = filepath_to_sound("assets/Buttons/main_menu_music.ogg");
    sound[1] = filepath_to_sound("assets/Buttons/button_sound.ogg");
    sound[2] = filepath_to_sound("assets/Buttons/click.ogg");
    return (sound);
}

int *generate_sound_started(void)
{
    int *values = malloc(sizeof(int) * 3);

    for (int i = 0; i < 3; i++)
        values[i] = 0;
    return (values);
}