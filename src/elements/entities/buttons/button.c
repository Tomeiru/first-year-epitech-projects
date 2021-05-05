/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button
*/

#include "my_rpg.h"
#include "audio/sound.h"
#include "graphics/texture.h"
#include "elements/entities/text.h"
#include "elements/entities/button.h"

static int button_setup_sprite_and_text(infos_t *infos,
button_t *button, char *text_str)
{
    sfSprite *sprite = sfSprite_create();
    sfText *text_sfml = sfText_create();

    if (!sprite || !text_sfml)
        return (1);
    sfText_setString(text_sfml, text_str);
    sfText_setFont(text_sfml, infos->font);
    sfText_setCharacterSize(text_sfml, 30);
    button->sprite = sprite;
    button->text = text_sfml;
    return (0);
}

button_t *button_create_default(size_t size, infos_t *infos,
char *text_str, sfVector2f pos)
{
    button_t *button = (button_t*)
    element_create_default(size, BUTTON, pos);

    if (!button || button_setup_sprite_and_text(infos, button, text_str))
        return (NULL);
    button->move = &button_move;
    button->rotate = &text_rotate;
    button->draw = &text_draw;
    button->update = &button_update;
    button->destroy = &text_destroy;
    button->is_hover = 0;
    button->press_time = -1;
    button->texture_height_offset = 0;
    return (button);
}

void button_set_hover(button_t *button, char hover)
{
    int height_offset = button->height * button->texture_height_offset;
    sfIntRect rect = {hover ? button->width : 0,
    height_offset, button->width, button->height};

    button->is_hover = hover;
    sfSprite_setTextureRect(button->sprite, rect);
}

void button_set_clicked(button_t *button, char clicked, infos_t *infos)
{
    int height_offset = button->height * button->texture_height_offset;
    sfIntRect rect = {button->width * 2 * clicked,
    height_offset, button->width, button->height};

    button->press_time = clicked ? 0 : -1;
    if (clicked)
        play_sound(infos, CLICK_SOUND);
    sfSprite_setTextureRect(button->sprite, rect);
}

void button_set_texture_rect(button_t *button)
{
    int height_offset = button->height * button->texture_height_offset;
    sfIntRect rect = {0, height_offset, button->width, button->height};

    sfSprite_setTextureRect(button->sprite, rect);
}