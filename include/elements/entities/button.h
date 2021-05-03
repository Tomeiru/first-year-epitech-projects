/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button
*/

#ifndef BUTTON_H_
#define BUTTON_H_

#include "elements/entities/entity.h"

#define PRESS_TIME 10

#define BLUE_BUTTON 0
#define RED_BUTTON 1
#define GREEN_BUTTON 2
#define YELLOW_BUTTON 3

typedef struct button_s {
    element_type_t type;
    sfVector2f pos;
    float rot;
    sfIntRect hitbox;
    sfSprite *sprite;
    move_element_fct_t move;
    rotate_element_fct_t rotate;
    draw_element_fct_t draw;
    on_click_fct_t on_click;
    get_infos_element_fct_t get_infos;
    destroy_element_fct_t destroy;
    update_entity_fct_t update;
    sfText *text;
    int width;
    int height;
    char is_hover;
    float press_time;
    int texture_height_offset;
} button_t;

button_t *button_create_default(size_t size, infos_t *infos,
char *text_str, sfVector2f pos);
void button_move(element_t *element, sfVector2f pos);
void button_set_hover(button_t *button, char hover);
void button_set_clicked(button_t *button, char clicked, infos_t *infos);
void button_set_texture_rect(button_t *button);

void button_move(element_t *element, sfVector2f pos);
void button_update(entity_t *entity, infos_t *infos, float elapsed);

int button_close_game(element_t *element,
infos_t *infos, sfMouseButton button_type);
int button_load_menu_scene(element_t *element,
infos_t *infos, sfMouseButton button_type);
int button_load_settings_scene(element_t *element,
infos_t *infos, sfMouseButton button_type);
int button_load_howtoplay_scene(element_t *element,
infos_t *infos, sfMouseButton button_type);
int button_load_world_scene(element_t *element,
infos_t *infos, sfMouseButton button_type);

int button_fps_minus(element_t *element,
infos_t *infos, sfMouseButton button_type);
int button_fps_plus(element_t *element,
infos_t *infos, sfMouseButton button_type);
int button_sound_minus(element_t *element,
infos_t *infos, sfMouseButton button_type);
int button_sound_plus(element_t *element,
infos_t *infos, sfMouseButton button_type);

int button_res_1920(element_t *element,
infos_t *infos, sfMouseButton button_type);
int button_res_1600(element_t *element,
infos_t *infos, sfMouseButton button_type);
int button_res_1280(element_t *element,
infos_t *infos, sfMouseButton button_type);

int button_htp_prev(element_t *element,
infos_t *infos, sfMouseButton button_type);
int button_htp_next(element_t *element,
infos_t *infos, sfMouseButton button_type);

button_t *text_button_create(infos_t *infos, char *text_str,
sfVector2f pos, int texture_height_offset);
button_t *inv_slot_create(infos_t *infos, char *text_str,
sfVector2f pos, int texture_height_offset);

#endif /* !BUTTON_H_ */
