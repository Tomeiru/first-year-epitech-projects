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
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(path);
    sfSound *sound = sfSound_create();

    if (!buffer || !sound)
        return (1);
    sfSound_setBuffer(sound, buffer);
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
    sfSound_play((sfSound*) list->data);
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
    sfSound *sound;
    const sfSoundBuffer *buffer;

    while (sounds) {
        tmp = sounds->next;
        if (sounds->data) {
            sound = (sfSound*) sounds->data;
            buffer = sfSound_getBuffer(sound);
            sfSound_destroy(sound);
            sfSoundBuffer_destroy(buffer);
        }
        free(sounds);
        sounds = tmp;
    }
}