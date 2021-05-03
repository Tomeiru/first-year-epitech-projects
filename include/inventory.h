/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** inventory
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "graphics/subwindow.h"
#include "elements/entities/slot_button.h"

#define INVENTORY_SPEED 50
#define INVENTORY_SIZE 21
#define INV_KEYB_NB 3
#define SHIFT_VALUE 36

typedef enum item_e {
    EMPTY = 0,
    HEALTH_POTION
} item_t;

typedef struct inventory_s {
    sfSprite *background;
    sfVector2f pos;
    list_t *elements;
    list_t *entities;
    subwindow_move_fct_t move;
    subwindow_update_fct_t update;
    subwindow_draw_fct_t draw;
    subwindow_destroy_fct_t destroy;
    char show;
    char anim;
    slot_button_t *slot_ptr;
    slot_button_t *slots[24];
} inventory_t;

inventory_t *inventory_create(infos_t *infos);
void inventory_update(subwindow_t *subwindow, infos_t *infos, float elapsed);
void inventory_anim_move(inventory_t *inventory,
const sfView *view, int target, float elapsed);
void inventory_show(inventory_t *inventory);

int inventory_create_slots(inventory_t *inv, infos_t *infos);
int add_item_to_inventory(inventory_t *inv, unsigned char item_id);
int remove_item_from_inventory(inventory_t *inv, int slot);
int button_inv_slot_click(element_t *element,
infos_t *infos, sfMouseButton button_type);

#endif /* !INVENTORY_H_ */
