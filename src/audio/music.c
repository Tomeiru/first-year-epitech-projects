/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** musics
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_rpg.h"
#include "audio/music.h"
#include "audio/music_list.h"

static int load_music(list_t **musics, const char *path)
{
    sfMusic *music = sfMusic_createFromFile(path);

    if (!music)
        return (1);
    sfMusic_setLoop(music, 1);
    create_list(musics, music);
    return (0);
}

music_struct_t *load_musics(void)
{
    music_struct_t *music = malloc(sizeof(music_struct_t));
    list_t *list = NULL;
    char destroy = 0;

    if (!music)
        return (NULL);
    for (int i = 0; i < MUSICS_NB && !destroy; i++) {
        if (load_music(&list, MUSICS_PATH[MUSICS_NB - i - 1]))
            destroy = 1;
    }
    if (destroy) {
        write(2, "Musics failed to load\n", 22);
        destroy_musics(music);
        return (NULL);
    }
    music->actual_music = NONE;
    music->musics = list;
    return (music);
}

void play_music(infos_t *infos, music_t id)
{
    music_struct_t *music = infos->music;
    list_t *list = music->musics;

    if (music->actual_music > -1)
        music_stop(music);
    for (int i = 0; i < (int) id; i++, list = list->next);
    sfMusic_play((sfMusic*) list->data);
    music->actual_music = id;
}

void destroy_musics(music_struct_t *music)
{
    list_t *musics = music->musics;
    list_t *tmp;

    while (musics) {
        tmp = musics->next;
        if (musics->data)
            sfMusic_destroy((sfMusic*) musics->data);
        free(musics);
        musics = tmp;
    }
    free(music);
}