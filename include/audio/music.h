/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** music
*/

#ifndef MUSIC_H_
#define MUSIC_H_

typedef enum music_e {
    NONE = -1,
    VILLAGE_MUSIC,
    FOREST_MUSIC,
    RIVER_MUSIC,
    MONTAINS_MUSIC,
    GAMEOVER_MUSIC,
    VICTORY_MUSIC,
    INTRO_MUSIC,
    MENU_MUSIC,
    MANSION_MUSIC,
} music_t;

typedef struct music_s {
    music_t actual_music;
    list_t *musics;
} music_struct_t;

music_struct_t *load_musics(void);
void play_music(infos_t *infos, music_t id);
void destroy_musics(music_struct_t *music);

void music_pause(music_struct_t *music);
void music_continue(music_struct_t *music);
void music_stop(music_struct_t *music);

#endif /* !MUSIC_H_ */
