/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-mathieu.brujan
** File description:
** ini_struct
*/

#include "../include/my_defender.h"

sfRenderWindow *create_window(int width, int height, char *window_name,
sfView *view)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, window_name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setView(window, view);
    return (window);
}

sfView *create_view(float width, float height)
{
    sfFloatRect view_rect = create_float_rect(0, 0, width, height);
    sfView *view = sfView_createFromRect(view_rect);

    sfView_setCenter(view, create_float_vector(width/2, height/2));
    return (view);
}

clocks_t *ini_clock_struct(void)
{
    clocks_t *clock = malloc(sizeof(clocks_t));

    clock->clock = sfClock_create();
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

entity_t **ini_main_menu_entity_struct(void)
{
    entity_t **buttons = malloc(sizeof(entity_t *) * 5);

    for (int i = 0; i < 5; i++) {
        buttons[i] = malloc(sizeof(entity_t));
        buttons[i]->speed = create_float_vector(0, 0);
        if (i != 4)
            buttons[i]->texture_rect = create_int_rect(0, 0, 500, 100);
    }buttons[4]->texture_rect = create_int_rect(0, 0, 1920, 1080);
    buttons[4]->position = create_float_vector(0, 0);
    buttons[4]->sprite = filepath_to_sprite("assets/Buttons/Background_mm.png");
    buttons[0]->sprite = filepath_to_sprite("assets/Buttons/Play.png");
    buttons[1]->sprite = filepath_to_sprite("assets/Buttons/Tutorial.png");
    buttons[2]->sprite = filepath_to_sprite("assets/Buttons/Settings.png");
    buttons[3]->sprite = filepath_to_sprite("assets/Buttons/Quit.png");
    buttons[0]->position = create_float_vector(1266, 588);
    buttons[1]->position = create_float_vector(1266, 711);
    buttons[2]->position = create_float_vector(1266, 834);
    buttons[3]->position = create_float_vector(1266, 957);
    return (buttons);
}

sfSound **ini_audio_main_menu(void)
{
    sfSound **sound = malloc(sizeof(sfSound *) * 3);

    sound[0] = filepath_to_sound("assets/Buttons/main_menu_music.ogg");
    sound[1] = filepath_to_sound("assets/Buttons/button_sound.ogg");
    sound[2] = filepath_to_sound("assets/Buttons/click.ogg");
    return (sound);
}

int *generate_sound_started(void)
{
    int *values = malloc(sizeof(int) * 3);
    
    for (int i = 0; i < 3; i++)
        values[i] = 0;
    return (values);
}

scene_t **ini_scene_struct(void)
{
    scene_t **scenes = malloc(sizeof(scene_t *) * 2);

    for (int i = 0; i < 2; i++)
        scenes[i] = malloc(sizeof(scene_t));
    scenes[0]->entities = ini_main_menu_entity_struct();
    scenes[0]->sound = ini_audio_main_menu();
    scenes[0]->sound_started = generate_sound_started();
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
    options->grid_off = 0;
    options->fps = 2;
    options->resolution = 3;
    return (options);
}

entity_t **ini_game_scene_entities(void)
{
    entity_t **sprites = malloc(sizeof(entity_t *) * 9);
    int j = 178;

    for (int i = 0; i < 4; i++) {
        sprites[i] = malloc(sizeof(entity_t));
        sprites[i]->texture_rect = create_int_rect(0, 0, 1920, 1080);
        sprites[i]->speed = create_float_vector(0, 0);
        sprites[i]->position = create_float_vector(0, 0);
    }sprites[0]->sprite = filepath_to_sprite("assets/Map/map.png");
    sprites[1]->sprite = filepath_to_sprite("assets/Map/grid.png");
    sprites[2]->sprite = filepath_to_sprite("assets/Map/shop.png");
    sprites[3]->sprite = filepath_to_sprite("assets/Map/shop_stat.png");
    for (int i = 4; i < 9; i++) {
        sprites[i] = malloc(sizeof(entity_t));
        sprites[i]->texture_rect = create_int_rect(0, 0, 150, 150);
        sprites[i]->speed = create_float_vector(0, 0);
        sprites[i]->position = create_float_vector(j, 922);
        sprites[i]->sprite = filepath_to_sprite("assets/Map/Scroll.png");
        j += 263;
    }return (sprites);
}

game_scene_t *ini_game_scene_struct(void)
{
    game_scene_t *game_scene = malloc(sizeof(game_scene_t));

    game_scene->gold = 0;
    game_scene->castle_pv = 0;
    game_scene->entities = ini_game_scene_entities();
    return (game_scene);
}

game_t *ini_game_struct(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->scenes = ini_scene_struct();
    game->stats = ini_stats_struct();
    game->clock = ini_clock_struct();
    game->mouse_info = ini_mouse_struct();
    game->options = ini_options_struct();
    game->game_scene = ini_game_scene_struct();
    init_wave(game);
    init_ennemies_array(game);
    return (game);
}