/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-mathieu.brujan
** File description:
** ini_struct
*/

#include "my_defender.h"

sfRenderWindow *create_window(int width, int height, char *window_name,
sfView *view)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, window_name, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setView(window, view);
    return (window);
}

sfView *create_view(float width, float height)
{
    sfFloatRect view_rect = create_float_rect(0, 0, width, height);
    sfView *view = sfView_createFromRect(view_rect);

    return (view);
}

clock_t *ini_clock_struct(void)
{
    clocks_t *clock = malloc(sizeof(clocks_t));
    return (clock);
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

options_t *ini_options_struct(void)
{
    options_t *options = malloc(sizeof(options_t));

    options->sound_off = 0;
    options->volume_off = 0;
    options->sound = 100;
    options->volume = 100;
    options->fps = 2;
    options->resolution = 3;
    return (options);
}

game_t *ini_game_struct(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->scenes = ini_scene_struct();
    game->stats = ini_stats_struct();
    game->clock = ini_clock_struct();
    game->mouse_info = ini_mouse_struct();
    game->options = ini_options_struct();
    return (game);
}