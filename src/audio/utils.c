/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** utils
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_rpg.h"
#include "audio/sound.h"
#include "audio/music.h"

void audio_set_volume(infos_t *infos)
{
    sound_couple_t *sound_couple = NULL;

    for (list_t *list = infos->sounds; list; list = list->next) {
        sound_couple = (sound_couple_t*) list->data;
        sfSound_setVolume(sound_couple->sound, infos->settings.sound_level);
    }
    for (list_t *list = infos->music->musics; list; list = list->next)
        sfMusic_setVolume((sfMusic*) list->data, infos->settings.sound_level);
}

void music_pause(music_struct_t *music)
{
    list_t *list = music->musics;

    if (music->actual_music == NONE)
        return;
    for (int i = 0; i < (int) music->actual_music; i++, list = list->next);
    sfMusic_pause((sfMusic*) list->data);
}

void music_continue(music_struct_t *music)
{
    list_t *list = music->musics;

    if (music->actual_music == NONE)
        return;
    for (int i = 0; i < (int) music->actual_music; i++, list = list->next);
    sfMusic_play((sfMusic*) list->data);
}

void music_stop(music_struct_t *music)
{
    list_t *list = music->musics;

    if (music->actual_music == NONE)
        return;
    for (int i = 0; i < (int) music->actual_music; i++, list = list->next);
    sfMusic_stop((sfMusic*) list->data);
    music->actual_music = NONE;
}