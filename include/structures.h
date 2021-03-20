/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** structures
*/

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include "my_defender.h"

enum scene {
    MAIN_MENU = 0, OPTIONS, GAME, PAUSE
};

typedef struct entity_s {
    sfSprite *sprite;
    sfIntRect texture_rect;
    sfVector2f position;
    sfVector2f speed;
} entity_t; //backgrounds, entities, buildings, buttons, etc, pareil que scene // garder le next pour les boutton (à voir) et retirer le next pour le reste

typedef struct ennemy_s {
    float attack;
    float speed;
    float HP;
    float gold;
    entity_t entity;
    struct ennemy_s *next;
} ennemy_t;

typedef struct wave_s {
    int mobs_spawned;
    float mul_speed;
    float mul_HP;
    float mul_gold; //increases at the end of every wave
    float mul_damage;
    float freq_spawn;
    int nbr_ennemies;
    int index;
    int type; //indicates which caracteristic is going to increase at the end : speed(1), HP(2), damage(3) ou fréquence de spawn (4)
} wave_t;

typedef struct clocks_s
{
    sfClock *clock;
    float wave_time;
    int wave_check;
} clocks_t;

typedef struct scene_s {
    entity_t **entities;
} scene_t;

typedef struct stats_s {
    enum scene num_scene;
    int score;
} stats_t;

typedef struct mouse_s {
    sfVector2i pos;
    sfVector2f rpos;
} mouse_t;

typedef struct options_s
{
    int sound_off;
    int volume_off;
    int grid_off;
    int fps;
    int resolution;
} options_t;

typedef struct game_scene_s {
    int gold;
    int castle_pv;
    wave_t wave;
    ennemy_t *ennemies_types;
    ennemy_t *ennemies;
    entity_t **entities;
} game_scene_t;

typedef struct game_s {
    game_scene_t *game_scene;
    scene_t **scenes;
    stats_t *stats;
    clocks_t *clock;
    mouse_t *mouse_info;
    options_t *options;
    sfEvent event;
} game_t;

//à faire : structure player

// se docu avec la function view en csfml
// faire un choix de framerate

#endif /* !STRUCTURES_H_ */
