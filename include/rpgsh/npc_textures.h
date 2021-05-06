/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** NPC textures
*/

#ifndef NPC_TEXTURES_H_
#define NPC_TEXTURES_H_

#include "graphics/texture.h"

#define NPC_NB 5

const char *NPC_NAME[] = {
    "DANDY",
    "FAT",
    "GUARD",
    "NURSE",
    "VILLAIN",
};

const texture_t NPC_TEXTURE[] = {
    DANDY_TEXT,
    FAT_TEXT,
    GUARD_TEXT,
    NURSE_TEXT,
    VILLAIN_TEXT,
};

#endif /* !NPC_TEXTURES_H_ */