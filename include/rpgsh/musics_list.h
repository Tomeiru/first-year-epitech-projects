/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** musics list
*/

#ifndef MUSICS_LIST_H_
#define MUSICS_LIST_H_

#include "audio/music.h"

#define MUSICS_NB 5

const char *MUSICS_NAME[] = {
    "VILLAGE",
    "FOREST",
    "RIVER",
    "MONTAINS",
    "MANSION",
};

const music_t MUSICS_ID[] = {
    VILLAGE_MUSIC,
    FOREST_MUSIC,
    RIVER_MUSIC,
    MONTAINS_MUSIC,
    MANSION_MUSIC,
};

#endif /* !MUSICS_LIST_H_ */
