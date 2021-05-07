/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** world type list
*/

#ifndef WORLD_TYPE_LIST_H_
#define WORLD_TYPE_LIST_H_

#include "scene/world_scene.h"

#define WORLD_TYPE_NB 4

const char *WORLD_TYPE_NAME[] = {
    "VILLAGE",
    "FOREST",
    "RIVER",
    "MONTAINS",
};

const world_type_t WORLD_TYPE[] = {
    VILLAGE,
    FOREST,
    RIVER,
    MONTAINS,
};

#endif /* !WORLD_TYPE_LIST_H_ */
