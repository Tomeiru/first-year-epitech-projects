/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** health bar
*/

#include <stdio.h>

#include <math.h>
#include <stdlib.h>
#include "graphics/texture.h"
#include "elements/health_bar.h"
#include "elements/entities/player.h"

health_bar_t *health_bar_create(infos_t *infos, sfVector2f pos,
float value, int max_value)
{
    health_bar_t *health_bar = (health_bar_t*)
    element_create_default(sizeof(health_bar_t), BAR, pos);
    sfSprite *sprite = sfSprite_create();
    sfRenderTexture *render_text =
    sfRenderTexture_create(HEART_SIZE * MAX_HEARTS, HEART_SIZE, 0);
    sfSprite *heart_sprite = sfSprite_create();

    if (!health_bar || !sprite || !render_text || !heart_sprite)
        return (NULL);
    sfSprite_setTexture(sprite, sfRenderTexture_getTexture(render_text), 0);
    sfSprite_setTexture(heart_sprite, get_texture(infos, HEART_TEXT), 0);
    sfSprite_setTextureRect(heart_sprite, (sfIntRect) {0, 0, 64, 64});
    health_bar->sprite = sprite;
    health_bar->destroy = &health_bar_destroy;
    health_bar->render_text = render_text;
    health_bar->heart_sprite = heart_sprite;
    health_bar->max_value = max_value;
    health_bar_set_value(health_bar, value);
    return (health_bar);
}

void health_bar_update_values(health_bar_t *health_bar, player_t *player)
{
    health_bar->max_value = player->max_health;
    health_bar_set_value(health_bar, player->health);
}

void health_bar_set_value(health_bar_t *health_bar, float value)
{
    int full_hearts = (int) floor(value / 2);
    int empty_hearts = (health_bar->max_value - ((int) value)) / 2;

    sfRenderTexture_clear(health_bar->render_text, (sfColor) {0, 0, 0, 0});
    sfSprite_setPosition(health_bar->heart_sprite, (sfVector2f) {0, 0});
    health_bar_draw_hearts(health_bar, full_hearts, 0);
    if (((int) value) % 2 == 1)
        health_bar_draw_hearts(health_bar, 1, 1);
    health_bar_draw_hearts(health_bar, empty_hearts, 2);
    sfRenderTexture_display(health_bar->render_text);
}

void health_bar_draw_hearts(health_bar_t *health_bar, int nb, int type)
{
    sfSprite *heart_sprite = health_bar->heart_sprite;

    sfSprite_setTextureRect(heart_sprite,
    (sfIntRect) {type * HEART_SIZE, 0, HEART_SIZE, HEART_SIZE});
    for (int i = 0; i < nb; i++) {
        sfRenderTexture_drawSprite(health_bar->render_text, heart_sprite, 0);
        sfSprite_move(heart_sprite, (sfVector2f) {HEART_SIZE, 0});
    }
}

void health_bar_destroy(element_t *element)
{
    health_bar_t *health_bar = (health_bar_t*) element;

    sfSprite_destroy(health_bar->sprite);
    sfRenderTexture_destroy(health_bar->render_text);
    sfSprite_destroy(health_bar->heart_sprite);
    free(health_bar);
}