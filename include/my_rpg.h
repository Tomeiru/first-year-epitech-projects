/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main header
*/

#ifndef MY_DEFENDER_H_
#define MY_DEFENDER_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_list.h"

#include "scene/scene.h"
#include "elements/element.h"
#include "elements/entities/entity.h"
#include "elements/entities/text.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define WINDOW_TITLE "my_rpg"

#define FPS (float)(1.0 / 60.0 * 1000000)

typedef enum game_state_e {
    MAIN_MENU,
    GAME,
    HOWTOPLAY,
    SETTINGS,
} game_state_t;

typedef struct infos_s {
    sfRenderWindow *window;
    game_state_t state;
    scene_t *scene;
    list_t *sounds;
    list_t *textures;
    sfFont *font;
    sfMusic *music;
    text_t *hover_infos;
    int sound_level;
    int fps;
} infos_t;

sfRenderWindow *create_window(int width, int height);

int my_rpg(sfRenderWindow *window);
int poll_events(infos_t *infos);

int setup_infos(infos_t *infos, sfRenderWindow *window);
void delete_infos(infos_t *infos);

int on_click_interact(list_t *list, infos_t *infos,
sfVector2f pos, sfMouseButtonEvent *mouse_ev);
int on_hover_interact(list_t *list, infos_t *infos, sfVector2f pos);

float get_distance(sfVector2f pos1, sfVector2f pos2);
int cmp_element_type(void *data1, void *data2);
void int_to_str(int value, char *buff, int buff_len);
int cmp_lb_entries(void *data1, void *data2);
void update_hover(infos_t *infos);

void sprite_set_origin_center(sfSprite *sprite);
void text_set_origin_center(sfText *text);

#endif /* !MY_DEFENDER_H_ */
