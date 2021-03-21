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
    MAIN_MENU = 0, OPTIONS, GAME, PAUSE, TUTO
};

typedef struct entity_s {
    sfSprite *sprite;
    sfIntRect texture_rect;
    sfVector2f position;
    sfVector2f speed;
} entity_t; 

typedef struct tower_s {
    sfSprite *sprite;
    sfIntRect texture_rect;
    sfVector2f position;
    struct tower_s *next;
} tower_t;

typedef struct ennemy_s {
    int display;
    float attack;
    float speed;
    float HP;
    float gold;
    entity_t entity;
    struct ennemy_s *next;
} ennemy_t;

typedef struct wave_s {
    int phase;
    int mobs_spawned;
    float mul_speed;
    float mul_HP;
    float mul_gold;
    float mul_damage;
    float freq_spawn;
    int nbr_ennemies;
    int index;
    int type;
} wave_t;

typedef struct clocks_s
{
    sfClock *clock;
    float wave_time;
    int wave_check;
} clocks_t;

typedef struct scene_s {
    entity_t **entities;
    sfSound **sound;
    int *sound_started;
} scene_t;

typedef struct stats_s {
    enum scene num_scene;
    int score;
    sfSprite *tuto;
    sfSprite *game_over;
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
    int phase;
    int time_check_rec;
    int time_check_cycle;
    char *map_nbr;
    double damage_cycle;
    double time_cycle;
    double gold_cycle;
    double rec_time;
    double elapsed_cycle;
    wave_t wave;
    ennemy_t *ennemies_types;
    ennemy_t *ennemies;
    entity_t **entities;
    tower_t *tower;
} game_scene_t;

typedef struct texts_s {
    sfFont *font;
    sfText *gold;
    sfText *wave;
    sfText *ennemies;
} texts_t;

typedef struct game_s {
    game_scene_t *game_scene;
    texts_t texts;
    scene_t **scenes;
    stats_t *stats;
    clocks_t *clock;
    mouse_t *mouse_info;
    options_t *options;
    sfEvent event;
} game_t;


#endif /* !STRUCTURES_H_ */
