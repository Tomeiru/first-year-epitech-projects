/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-mathieu.brujan
** File description:
** load_files
*/

#include "my_runner.h"

void load_audio(struct game_struct *game_man)
{
    game_man->game_audio->theme_song = filepath_to_sound("files/theme.ogg");
    sfSound_setLoop(game_man->game_audio->theme_song, 1);
    game_man->game_audio->jump_sound = filepath_to_sound("files/jump.ogg");
}

void setpos_sprites(struct game_struct *game_man)
{
    sfSprite_setPosition(game_man->game_gui->ground, coord_to_pos(0, 936));
    sfSprite_setPosition(game_man->game_gui->underground, 
    coord_to_pos(0, 1008));
    sfSprite_setPosition(game_man->game_gui->grass, coord_to_pos(0, 864));
    sfSprite_setPosition(game_man->game_gui->ground_second, 
    coord_to_pos(2160, 936));
    sfSprite_setPosition(game_man->game_gui->underground_second, 
    coord_to_pos(2160, 1008));
    sfSprite_setPosition(game_man->game_gui->grass_second, 
    coord_to_pos(2160, 864));
    sfSprite_setPosition(game_man->game_gui->mario, coord_to_pos(200, 720));
    sfSprite_setPosition(game_man->game_gui->jumping_mario, 
    coord_to_pos(200, 720));
    sfSprite_setPosition(game_man->game_gui->obstacle, coord_to_pos(1920, 824));
    sfSprite_setPosition(game_man->game_gui->lives, coord_to_pos(0, 943));
    sfSprite_setPosition(game_man->game_gui->crown, coord_to_pos(1200, 943));
}

void load_sprites(struct game_struct *game_man)
{
    char *background_path = "files/background_runner.png";

    game_man->game_gui->background = filepath_to_sprite(background_path);
    game_man->game_gui->underground = filepath_to_sprite("files/Ground.png");
    game_man->game_gui->ground = filepath_to_sprite("files/Ground.png");
    game_man->game_gui->grass = filepath_to_sprite("files/Ground.png");
    game_man->game_gui->underground_second = 
    filepath_to_sprite("files/Ground.png");
    game_man->game_gui->ground_second = filepath_to_sprite("files/Ground.png");
    game_man->game_gui->grass_second = filepath_to_sprite("files/Ground.png");
    game_man->game_gui->mario = filepath_to_sprite("files/running_mario.png");
    game_man->game_gui->jumping_mario = 
    filepath_to_sprite("files/jumping_mario.png");
    game_man->game_gui->obstacle = filepath_to_sprite("files/obstacles.png");
    game_man->game_gui->lives = filepath_to_sprite("files/lives.png");
    game_man->game_gui->game_over = 
    filepath_to_sprite("files/gameover_screen.png");
    game_man->game_gui->crown = filepath_to_sprite("files/crown.png");
    setpos_sprites(game_man);
}

void load_text(struct game_struct *game_man)
{
    game_man->game_gui->score = sfText_create();
    sfText_setString(game_man->game_gui->score, "Score");
    sfText_setFont(game_man->game_gui->score, game_man->game_gui->font);
    sfText_setColor(game_man->game_gui->score, sfWhite);
    sfText_setCharacterSize(game_man->game_gui->score, 144);
    sfText_setPosition(game_man->game_gui->score, coord_to_pos(486, 920));
    game_man->game_gui->score_value = sfText_create();
    sfText_setString(game_man->game_gui->score_value, 
    print_u(game_man->game_stats->score));
    sfText_setFont(game_man->game_gui->score_value, game_man->game_gui->font);
    sfText_setColor(game_man->game_gui->score_value, sfWhite);
    sfText_setCharacterSize(game_man->game_gui->score_value, 144);
    sfText_setPosition(game_man->game_gui->score_value, 
    coord_to_pos(1000, 920));
    game_man->game_gui->hscore_value = sfText_create();
    sfText_setString(game_man->game_gui->hscore_value, 
    print_u(game_man->game_stats->high_score));
    sfText_setFont(game_man->game_gui->hscore_value, game_man->game_gui->font);
    sfText_setColor(game_man->game_gui->hscore_value, sfWhite);
    sfText_setCharacterSize(game_man->game_gui->hscore_value, 144);
    sfText_setPosition(game_man->game_gui->hscore_value, 
    coord_to_pos(1370, 920));
}

void load_files(struct game_struct *game_man)
{
    load_audio(game_man);
    load_sprites(game_man);
    game_man->game_gui->font = sfFont_createFromFile("files/mariofont.ttf");
    load_text(game_man);
}