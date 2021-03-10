/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** structures
*/

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include "my_defender.h"

typedef struct clock_s
{
    sfClock *clock;
} clock_t;

typedef struct entity_s {
    sfSprite *sprite;
    sfIntRect texture_rect;
    sfVector2f position;
    sfVector2f speed;
    struct entity_s *next;
} entity_t; //backgrounds, entities, buildings, buttons, etc, pareil que scene // garder le next pour les boutton (à voir) et retirer le next pour le reste

typedef struct scene_s {
    int index;
    entity_t *entities;
    struct scene_s *next;
} scene_t; // transformer ça en tableau avec enum

typedef struct stats_s {
    int score;
} stats_t;

typedef struct game_s {
    scene_t *scenes;
    stats_t stats;
    clock_t clock;
} game_t;

// se docu avec la function view en csfml
// faire un choix de framerate

#endif /* !STRUCTURES_H_ */
