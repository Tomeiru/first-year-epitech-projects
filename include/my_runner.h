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

struct stats
{
    unsigned int score;
    unsigned int high_score;
    unsigned int lives;
    unsigned int moving_ground;
    unsigned int is_jumping;
    unsigned int clock_restart;
    unsigned int animation;
    unsigned int animation_run;
    unsigned int need_spawn;
    unsigned int invicible;
    unsigned int dodge;
    unsigned int speed;
    unsigned int ouch;
    int phase;
};

struct gui
{
    sfSprite *background;
    sfSprite *grass;
    sfSprite *ground;
    sfSprite *underground;
    sfSprite *grass_second;
    sfSprite *ground_second;
    sfSprite *underground_second;
    sfSprite *mario;
    sfSprite *jumping_mario;
    sfSprite *obstacle;
    sfSprite *lives;
    sfSprite *game_over;
    sfSprite *crown;
    sfIntRect bg_rect;
    sfIntRect grass_rect;
    sfIntRect ground_rect;
    sfIntRect underground_rect;
    sfIntRect grass_second_rect;
    sfIntRect ground_second_rect;
    sfIntRect underground_second_rect;
    sfIntRect mario_rect;
    sfIntRect jumping_mario_rect;
    sfIntRect obstacle_rect;
    sfIntRect lives_rect;
    sfText *score;
    sfText *score_value;
    sfText *hscore_value;
    sfFont *font;
};

struct audio
{
    sfSound *theme_song;
    unsigned int theme_song_launched;
    sfSound *jump_sound;
};

struct clock
{
    sfClock *immune;
    int clock_restarted;
};

struct game_struct
{
    struct stats *game_stats;
    struct gui *game_gui;
    struct audio *game_audio;
    struct clock *game_clock;
};

sfSprite *filepath_to_sprite(char *filepath);
void analyse_events(sfRenderWindow *window, sfEvent event,
struct game_struct *game_man, sfClock *clock);
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
void main_game(sfRenderWindow *window, struct game_struct *game_man);
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
