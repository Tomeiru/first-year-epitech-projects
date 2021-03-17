/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_defender
*/

#ifndef MY_DEFENDER_H_
#define MY_DEFENDER_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "structures.h"

//fonctions
//cast_struct.c
sfVector2f create_float_vector(int x, int y);
sfFloatRect create_float_rect(float top, float left, float width, float height);
sfIntRect create_int_rect(int top, int left, int width, int height);

//event.c
void event_options_menu(game_t *game, sfRenderWindow *window);
void event_main_menu(game_t *game, sfRenderWindow *window);
void analyse_event(game_t *game, sfRenderWindow *window);

//events_options_menu.c
void cursor_on_volume_sound(entity_t **entities, mouse_t *mouse_info, options_t *options);
void cursor_on_fps(entity_t **entities, mouse_t *mouse_info, options_t *options, sfRenderWindow *window);
void change_resolution(sfRenderWindow *window, int x);
void cursor_on_resolution(entity_t **entities, mouse_t *mouse_info, options_t *options, sfRenderWindow *window);
void left_click_options_event(game_t *game, sfRenderWindow *window);

//ini_struct.c
sfRenderWindow *create_window(int width, int height, char *window_name, sfView *view);
sfView *create_view(float width, float height);
clock_t *ini_clock_struct(void);
sfSound *filepath_to_sound(char *filepath);
sfSprite *filepath_to_sprite(char *filepath);
entity_t **malloc_options_struct(void);
void apply_sprite_option_struct(entity_t **buttons);
void create_rect_and_vector_option_struct(entity_t **buttons);
entity_t **ini_option_entity_struct(void);
entity_t **ini_main_menu_entity_struct(void);
scene_t **ini_scene_struct(void);
stats_t *ini_stats_struct();
mouse_t *ini_mouse_struct(void);
options_t *ini_options_struct(void);
game_t *ini_game_struct(void);

//main_menu.c
void draw_menu_buttons(sfRenderWindow *window, game_t *game);
int is_cursor_on_buttons_menu(entity_t **entities, mouse_t *mouse_info);
void highlight_menu_buttons(entity_t **entities, mouse_t *mouse_info);
void main_menu(sfRenderWindow *window, game_t *game);

//my_defender.c
void draw_sprites_wo_speed(sfRenderWindow *window, entity_t *entity);
void update_mouse_info(game_t *game, sfRenderWindow *window);
void run_game(sfRenderWindow *window, game_t *game);
int my_defender(void);

//options_menu.c
void draw_options_buttons(game_t *game, sfRenderWindow *window);
void adjust_rect_volume_sound(entity_t **entities, options_t *options);
void adjust_rect_fps(entity_t **entities, options_t *options);
void adjust_rect_resolution(entity_t **entities, options_t *options);
void adjust_rect_options(entity_t **entities, options_t *options);
void option_menu(sfRenderWindow *window, game_t *game);

//scene_manager.c
void scene_manager(sfRenderWindow *window, game_t *game);

#endif /* !MY_DEFENDER_H_ */
