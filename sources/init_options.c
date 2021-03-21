/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** init_options
*/

#include "../include/my_defender.h"

entity_t **malloc_options_struct(void)
{
    entity_t **buttons = malloc(sizeof(entity_t *) * 12);

    for (int i = 0; i < 12; i++) {
        buttons[i] = malloc(sizeof(entity_t));
        buttons[i]->speed = create_float_vector(0,0);
    }
    return (buttons);
}

void apply_sprite_option_struct(entity_t **buttons)
{
    buttons[0]->sprite = filepath_to_sprite("assets/Option/Sound.png");
    buttons[1]->sprite = filepath_to_sprite("assets/Option/Volume.png");
    buttons[2]->sprite = filepath_to_sprite("assets/Option/Grid.png");
    buttons[3]->sprite = filepath_to_sprite("assets/Option/10fps.png");
    buttons[4]->sprite = filepath_to_sprite("assets/Option/30fps.png");
    buttons[5]->sprite = filepath_to_sprite("assets/Option/60fps.png");
    buttons[6]->sprite = filepath_to_sprite("assets/Option/120fps.png");
    buttons[7]->sprite = filepath_to_sprite("assets/Option/480x270.png");
    buttons[8]->sprite = filepath_to_sprite("assets/Option/960x540.png");
    buttons[9]->sprite = filepath_to_sprite("assets/Option/1440x810.png");
    buttons[10]->sprite = filepath_to_sprite("assets/Option/1920x1080.png");
    buttons[11]->sprite = filepath_to_sprite("assets/Option/Background_op.png");
}

void create_rect_and_vector_option_struct(entity_t **buttons)
{
    for (int i = 0; i < 3; i++)
        buttons[i]->texture_rect = create_int_rect(0, 0, 300, 76);
    for (int i = 3; i < 11; i++)
        buttons[i]->texture_rect = create_int_rect(0, 0, 200, 50);
    buttons[11]->texture_rect = create_int_rect(0, 0, 1920, 1080);
    buttons[0]->position = create_float_vector(810, 352);
    buttons[1]->position = create_float_vector(810, 452);
    buttons[2]->position = create_float_vector(810, 552);
    buttons[3]->position = create_float_vector(760, 640);
    buttons[4]->position = create_float_vector(960, 640);
    buttons[5]->position = create_float_vector(760, 690);
    buttons[6]->position = create_float_vector(960, 690);
    buttons[7]->position = create_float_vector(760, 740);
    buttons[8]->position = create_float_vector(960, 740);
    buttons[9]->position = create_float_vector(760, 790);
    buttons[10]->position = create_float_vector(960, 790);
    buttons[11]->position = create_float_vector(0, 0);
}

entity_t **ini_option_entity_struct(void)
{
    entity_t **buttons = malloc_options_struct();

    apply_sprite_option_struct(buttons);
    create_rect_and_vector_option_struct(buttons);
    return (buttons);
}

options_t *ini_options_struct(void)
{
    options_t *options = malloc(sizeof(options_t));

    options->sound_off = 0;
    options->volume_off = 0;
    options->grid_off = 0;
    options->fps = 2;
    options->resolution = 3;
    return (options);
}