/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** sounds
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_rpg.h"
#include "sound.h"
#include "sound_list.h"

static int load_sound(list_t **sounds, const char *path)
{
    sound_couple_t *sound = malloc(sizeof(sound_couple_t));
    sfSoundBuffer *buffer_sfml = sfSoundBuffer_createFromFile(path);
    sfSound *sound_sfml = sfSound_create();

    if (!sound || !buffer_sfml || !sound_sfml)
        return (1);
    sound->buffer = buffer_sfml;
    sound->sound = sound_sfml;
    sfSound_setBuffer(sound_sfml, buffer_sfml);
    create_list(sounds, sound);
    return (0);
}

list_t *load_sounds(void)
{
    list_t *list = NULL;
    char destroy = 0;

    for (int i = 0; i < SOUNDS_NB && !destroy; i++) {
        if (load_sound(&list, SOUNDS_PATH[SOUNDS_NB - i - 1]))
            destroy = 1;
    }
    if (destroy) {
        write(2, "Sounds failed to load\n", 22);
        destroy_sounds(list);
        return (NULL);
    } else
        return (list);
}

void play_sound(infos_t *infos, sound_t id)
{
    list_t *list = infos->sounds;

    for (int i = 0; i < (int) id; i++, list = list->next);
    sfSound_play(((sound_couple_t*) list->data)->sound);
}

void sound_set_volume(infos_t *infos)
{
    sfMusic_setVolume(infos->music, infos->settings.sound_level);
    for (list_t *list = infos->sounds; list; list = list->next)
        sfSound_setVolume((sfSound*) list->data, infos->settings.sound_level);
}

void destroy_sounds(list_t *sounds)
{
    list_t *tmp;
    sound_couple_t *sound;

    while (sounds) {
        tmp = sounds->next;
        if (sounds->data) {
            sound = (sound_couple_t*) sounds->data;
            sfSound_destroy(sound->sound);
            sfSoundBuffer_destroy(sound->buffer);
            free(sound);
        }
        free(sounds);
        sounds = tmp;
    }
}