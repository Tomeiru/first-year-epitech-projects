/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** structures
*/

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include "my_defender.h"

typedef struct clocks_s
{
    sfClock *clock;
} clocks_t;

typedef struct entity_s {
    sfSprite *sprite;
    sfIntRect texture_rect;
    sfVector2f position;
    sfVector2f speed;
} entity_t; //backgrounds, entities, buildings, buttons, etc, pareil que scene // garder le next pour les boutton (à voir) et retirer le next pour le reste

enum scene {
    MAIN_MENU = 0, OPTIONS
};

typedef struct scene_s {
    entity_t **entities;
} scene_t;

typedef struct stats_s {
    enum scene num_scene;
    int score;
} stats_t;

typedef struct mouse_s {
    sfVector2i pos;
} mouse_t;

typedef struct options_s
{
    int sound_off;
    int volume_off;
    int sound;
    int volume;
    int fps;
    int resolution;
} options_t;


typedef struct game_s {
    scene_t **scenes;
    stats_t *stats;
    clock_t *clock;
    mouse_t *mouse_info;
    options_t *options;
    sfEvent event;
} game_t;

// se docu avec la function view en csfml
// faire un choix de framerate

#endif /* !STRUCTURES_H_ */
