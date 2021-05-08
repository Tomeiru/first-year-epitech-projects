/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

typedef struct infos_s infos_t;
typedef struct element_s element_t;
typedef void (*rpgsh_command_fct_t)(char ***line,
char **args, infos_t *infos, element_t *element);

#ifndef BONUS
#define NB_COMMANDS 12
#else
#define NB_COMMANDS 13
#endif

void cam_target_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element);
void set_player_move_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element);
void destroy_element_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element);
void dialogue_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element);

void add_npc_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element);
void add_trigger_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element);
void add_enemy_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element);
void move_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element);

void world_type_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element);
void play_music_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element);

void add_item_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element);
void remove_item_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element);

#ifdef BONUS
void open_url_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element);
#endif

const char *COMMAND_STR[] = {
    "MOVE",
    "CAM_TARGET",
    "SET_PLAYER_MOVE",
    "DESTROY",
    "DIALOGUE",
    "ADD_NPC",
    "ADD_TRIGGER",
    "ADD_ENEMY",
    "SET_WORLD_TYPE",
    "PLAY_MUSIC",
    "ADD_ITEM",
    "REMOVE_ITEM",
    "OPEN_URL",
};

const int COMMAND_LENGTH[] = {
    4,
    10,
    15,
    7,
    8,
    7,
    11,
    9,
    14,
    10,
    8,
    11,
    8,
};

const rpgsh_command_fct_t COMMAND_FCT[] = {
    &move_rpgsh_command,
    &cam_target_rpgsh_command,
    &set_player_move_rpgsh_command,
    &destroy_element_rpgsh_command,
    &dialogue_rpgsh_command,
    &add_npc_rpgsh_command,
    &add_trigger_rpgsh_command,
    &add_enemy_rpgsh_command,
    &world_type_rpgsh_command,
    &play_music_rpgsh_command,
    &add_item_rpgsh_command,
    &remove_item_rpgsh_command,
#ifdef BONUS
    &open_url_rpgsh_command,
#endif
};

#endif /* !COMMANDS_H_ */
