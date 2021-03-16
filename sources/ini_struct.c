/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-mathieu.brujan
** File description:
** ini_struct
*/

#include "my_defender.h"

clock_t *ini_clock_struct(void)
{
    clock_t *clock = malloc(sizeof(clock_t));
    return (clock);
}

sfVector2f create_float_vector(int x, int y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfIntRect create_int_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfSound *filepath_to_sound(char *filepath)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(filepath);

    sfSound_setBuffer(sound, buffer);
    return (sound);
}

sfSprite *filepath_to_sprite(char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

entity_t **malloc_options_struct(void)
{
    entity_t **buttons = malloc(sizeof(entity_t *) * 12);

    for (int i = 0; i < 12; i++) {
        buttons[i] = malloc(sizeof(entity_t));
        buttons[i]->speed = create_float_vector(0,0);
    }return (buttons);
}

void apply_sprite_option_struct(entity_t **buttons)
{
    buttons[0]->sprite = filepath_to_sprite("assets/Option/Sound.png");
    buttons[1]->sprite = filepath_to_sprite("assets/Option/Volume.png");
    buttons[2]->sprite = filepath_to_sprite("assets/Option/Slider_sound.png");
    buttons[3]->sprite = filepath_to_sprite("assets/Option/Slider_volume.png");
    buttons[4]->sprite = filepath_to_sprite("assets/Option/10fps.png");
    buttons[5]->sprite = filepath_to_sprite("assets/Option/30fps.png");
    buttons[6]->sprite = filepath_to_sprite("assets/Option/60fps.png");
    buttons[7]->sprite = filepath_to_sprite("assets/Option/120fps.png");
    buttons[8]->sprite = filepath_to_sprite("assets/Option/480x270.png");
    buttons[9]->sprite = filepath_to_sprite("assets/Option/960x540.png");
    buttons[10]->sprite = filepath_to_sprite("assets/Option/1440x810.png");
    buttons[11]->sprite = filepath_to_sprite("assets/Option/1920x1080.png");
}

void create_rect_and_vector_option_struct(entity_t **buttons)
{
    for (int i = 0; i < 2; i++)
        buttons[i]->texture_rect = create_int_rect(0, 0, 200, 100);
    for (int i = 2; i < 4; i++)
        buttons[i]->texture_rect = create_int_rect(0, 0, 400, 100);
    for (int i = 4; i < 12; i++)
        buttons[i]->texture_rect = create_int_rect(0, 0, 100, 100);
    buttons[0]->position = create_float_vector(760, 340);
    buttons[1]->position = create_float_vector(960, 340);
    buttons[2]->position = create_float_vector(760, 440);
    buttons[3]->position = create_float_vector(760, 540);
    buttons[4]->position = create_float_vector(760, 640);
    buttons[5]->position = create_float_vector(860, 640);
    buttons[6]->position = create_float_vector(960, 640);
    buttons[7]->position = create_float_vector(1060, 640);
    buttons[8]->position = create_float_vector(760, 740);
    buttons[9]->position = create_float_vector(860, 740);
    buttons[10]->position = create_float_vector(960, 740);
    buttons[11]->position = create_float_vector(1060, 740);
}

entity_t **ini_option_entity_struct(void)
{
    entity_t **buttons = malloc_options_struct();

    apply_sprite_option_struct(buttons);
    create_rect_and_vector_option_struct(buttons);
    return (buttons);
}

entity_t **ini_main_menu_entity_struct(void)
{
    entity_t **buttons = malloc(sizeof(entity_t *) * 4);

    for (int i = 0; i < 4; i++) {
        buttons[i] = malloc(sizeof(entity_t));
        buttons[i]->texture_rect = create_int_rect(0, 0, 500, 100);
        buttons[i]->speed = create_float_vector(0, 0);
    }buttons[0]->sprite = filepath_to_sprite("assets/Buttons/Play.png");
    buttons[1]->sprite = filepath_to_sprite("assets/Buttons/Tutorial.png");
    buttons[2]->sprite = filepath_to_sprite("assets/Buttons/Settings.png");
    buttons[3]->sprite = filepath_to_sprite("assets/Buttons/Quit.png");
    buttons[0]->position = create_float_vector(710, 565);
    buttons[1]->position = create_float_vector(710, 688);
    buttons[2]->position = create_float_vector(710, 811);
    buttons[3]->position = create_float_vector(710, 934);
    return (buttons);
}

scene_t **ini_scene_struct(void)
{
    scene_t **scenes = malloc(sizeof(scene_t *) * 2);

    for (int i = 0; i < 2; i++)
        scenes[i] = malloc(sizeof(scene_t));
    scenes[0]->entities = ini_main_menu_entity_struct();
    scenes[1]->entities = ini_option_entity_struct();
    return (scenes);
}

stats_t *ini_stats_struct()
{
    stats_t *stats = malloc(sizeof(stats_t));

    stats->num_scene = MAIN_MENU;
    stats->score = 0;
    return (stats);
}

mouse_t *ini_mouse_struct(void)
{
    mouse_t *mouse_info = malloc(sizeof(mouse_t));

    mouse_info->pos.x = 0;
    mouse_info->pos.y = 0;
    return (mouse_info);
}

game_t *ini_game_struct(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->scenes = ini_scene_struct();
    game->stats = ini_stats_struct();
    game->clock = ini_clock_struct();
    game->mouse_info = ini_mouse_struct();
    return (game);
}