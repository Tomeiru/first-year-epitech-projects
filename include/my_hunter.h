/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-mathieu.brujan
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_printf.h"

struct stats
{
    unsigned int score;
    unsigned int high_score;
    unsigned int round;
    int game_over_sound_played;
    int game_menu_sound_played;
    int bird_this_round;
    int phase;
    int shots;
    double act_speed;
    int missed;
    int killed;
    int score_this_round;
};

struct gui
{
    sfSprite *crosshair;
    sfSprite *background;
    sfSprite *red_duck;
    sfSprite *green_duck;
    sfSprite *menu;
    sfSound *gun_shot;
    sfSound *round_win;
    sfSound *game_over_sound;
    sfSound *game_menu_sound;
    sfSound *touched;
    sfText *score;
    sfText *high_score;
    sfText *round;
    sfText *new_hs;
    sfText *sn_end;
    sfText *s_end;
    sfText *game_over;
    sfText *end_text;
    sfFont *font;
    sfIntRect rect_second;
};

struct birds
{
    sfSprite *sprite;
    sfVector2f sprite_pos;
    sfIntRect rect;
    double speed;
    int need_spawn;
    int which_bird;
};

struct game_struct
{
    struct stats *game_stats;
    struct gui *game_gui;
    struct birds *game_birds;
};

sfSprite *filepath_to_sprite(char *filepath);
void analyse_events(sfRenderWindow *window, sfEvent event,
struct game_struct *game_man);
int run_game(sfRenderWindow *window);
int game(void);
sfVector2f coord_to_pos(int x, int y);
void load_files(struct game_struct *game_man);
void load_text(struct game_struct *game_man);
void load_sprites(struct game_struct *game_man);
struct stats *ini_stats_struct(void);
struct gui *ini_gui_struct(void);
struct birds *ini_birds_struct(void);
int main(int ac, char **av);
struct game_struct *ini_game_struct(void);
void missed(struct game_struct *game_man);
void touched(struct game_struct *game_man);
void score_manager(sfRenderWindow *window, struct game_struct *game_man);
void bird_manager(struct game_struct *game_man, sfClock *clock);
void crosshair_manager(sfRenderWindow *window, struct game_struct *game_man);
void red_bird(sfRenderWindow *window, struct game_struct *game_man);
void round_complete(struct game_struct *game_man);
void load_text_score(struct game_struct *game_man);
void load_text_round(struct game_struct *game_man);
void main_menu(sfRenderWindow *window, struct game_struct *game_man);
void main_game(sfRenderWindow *window, struct game_struct *game_man,
sfClock *clock);
void alt_game(sfRenderWindow *window, struct game_struct *game_man,
sfClock *clock);
void killed(sfRenderWindow *window, struct game_struct *game_man,
sfClock *clock);
int if_conditions(sfEvent event, struct game_struct *game_man);
void shot(struct game_struct *game_man, sfRenderWindow *window);
sfSound *filepath_to_sound(char *filepath);
void load_end_text(struct game_struct *game_man);
void restart(struct game_struct *game_man);
void load_end_score(struct game_struct *game_man);

#endif /* !MY_HUNTER_H_ */
