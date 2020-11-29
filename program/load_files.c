/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-mathieu.brujan
** File description:
** load_files
*/

#include "my_hunter.h"

sfVector2f coord_to_pos(int x, int y)
{
    sfVector2f position = {x, y};

    return(position);
}

void load_files(struct game_struct *game_man)
{
    load_sprites(game_man);
    game_man->game_gui->font = sfFont_createFromFile("files/PrStart.ttf");
    load_text_score(game_man);
    load_text_round(game_man);
    load_end_text(game_man);
    load_end_score(game_man);
}

unsigned int which_pos_score(int score)
{
    if (score < 10)
        return (966);
    if (score >= 10 && score < 100)
        return (934);
    if (score >= 100 && score < 1000)
        return (902);
    if (score >= 1000 && score < 10000)
        return (870);
    if (score >= 10000 && score < 100000)
        return (838);
    if (score >= 100000)
        return (806);
}

unsigned int which_pos_hscore(int score)
{
    if (score < 10)
        return (194);
    if (score >= 10 && score < 100)
        return (162);
    if (score >= 100 && score < 1000)
        return (130);
    if (score >= 1000 && score < 10000)
        return (98);
    if (score >= 10000 && score < 100000)
        return (66);
    if (score >= 100000)
        return (34);
}

void load_end_score(struct game_struct *game_man)
{
    game_man->game_gui->sn_end = sfText_create();
    sfText_setString(game_man->game_gui->sn_end,
    print_di(game_man->game_stats->score));
    sfText_setFont(game_man->game_gui->sn_end, game_man->game_gui->font);
    sfText_setColor(game_man->game_gui->sn_end, sfWhite);
    sfText_setCharacterSize(game_man->game_gui->sn_end, 40);
    sfText_setPosition(game_man->game_gui->sn_end, coord_to_pos(250, 475));
    game_man->game_gui->end_text = sfText_create();
    sfText_setString(game_man->game_gui->end_text,
    "Press 'q' to quit\nPress 'r' to restart");
    sfText_setFont(game_man->game_gui->end_text, game_man->game_gui->font);
    sfText_setColor(game_man->game_gui->end_text, sfWhite);
    sfText_setCharacterSize(game_man->game_gui->end_text, 40);
    sfText_setPosition(game_man->game_gui->end_text, coord_to_pos(0, 575));
}

void load_end_text(struct game_struct *game_man)
{
    game_man->game_gui->game_over = sfText_create();
    sfText_setString(game_man->game_gui->game_over, "Game Over");
    sfText_setFont(game_man->game_gui->game_over, game_man->game_gui->font);
    sfText_setColor(game_man->game_gui->game_over, sfRed);
    sfText_setCharacterSize(game_man->game_gui->game_over, 116);
    sfText_setPosition(game_man->game_gui->game_over, coord_to_pos(0, 250));
    game_man->game_gui->new_hs = sfText_create();
    sfText_setString(game_man->game_gui->new_hs, "New High Score!");
    sfText_setFont(game_man->game_gui->new_hs, game_man->game_gui->font);
    sfText_setColor(game_man->game_gui->new_hs, sfGreen);
    sfText_setCharacterSize(game_man->game_gui->new_hs, 50);
    sfText_setPosition(game_man->game_gui->new_hs, coord_to_pos(0, 400));
    game_man->game_gui->s_end = sfText_create();
    sfText_setString(game_man->game_gui->s_end, "Score:");
    sfText_setFont(game_man->game_gui->s_end, game_man->game_gui->font);
    sfText_setColor(game_man->game_gui->s_end, sfWhite);
    sfText_setCharacterSize(game_man->game_gui->s_end, 40);
    sfText_setPosition(game_man->game_gui->s_end, coord_to_pos(0, 475));
}

void load_text_round(struct game_struct *game_man)
{
    unsigned int round_score = which_pos_hscore(game_man->game_stats->round);

    game_man->game_gui->round = sfText_create();
    sfText_setString(game_man->game_gui->round, 
    print_di(game_man->game_stats->round));
    sfText_setFont(game_man->game_gui->round, game_man->game_gui->font);
    sfText_setColor(game_man->game_gui->round, sfWhite);
    sfText_setCharacterSize(game_man->game_gui->round, 32);
    sfText_setPosition(game_man->game_gui->round,
    coord_to_pos(round_score, 765));
}

void load_text_score(struct game_struct *game_man)
{
    unsigned int x_score = which_pos_score(game_man->game_stats->score);
    unsigned int x_hscore = which_pos_hscore(game_man->game_stats->high_score);

    game_man->game_gui->score = sfText_create();
    sfText_setString(game_man->game_gui->score,
    print_di(game_man->game_stats->score));
    sfText_setFont(game_man->game_gui->score, game_man->game_gui->font);
    sfText_setColor(game_man->game_gui->score, sfWhite);
    sfText_setCharacterSize(game_man->game_gui->score, 32);
    sfText_setPosition(game_man->game_gui->score, coord_to_pos(x_score, 829));
    game_man->game_gui->high_score = sfText_create();
    sfText_setString(game_man->game_gui->high_score, 
    print_di(game_man->game_stats->high_score));
    sfText_setFont(game_man->game_gui->high_score, game_man->game_gui->font);
    sfText_setColor(game_man->game_gui->high_score, sfWhite);
    sfText_setCharacterSize(game_man->game_gui->high_score, 32);
    sfText_setPosition(game_man->game_gui->high_score,
    coord_to_pos(x_hscore, 829));
}

void load_sprites(struct game_struct *game_man)
{
    char *background_path = "files/backgrounds.png";

    game_man->game_birds->sprite = filepath_to_sprite("files/ducks.png");
    game_man->game_gui->crosshair = filepath_to_sprite("files/crosshairhq.png");
    game_man->game_gui->background = filepath_to_sprite(background_path);
    game_man->game_gui->menu = filepath_to_sprite("files/menu.png");
    game_man->game_gui->red_duck = filepath_to_sprite(background_path);
    game_man->game_gui->green_duck = filepath_to_sprite(background_path);
    game_man->game_gui->gun_shot = filepath_to_sound("files/gunshot.wav");
    game_man->game_gui->round_win = filepath_to_sound("files/finish_round.wav");
    game_man->game_gui->game_over_sound =
    filepath_to_sound("files/game_over.wav");
    game_man->game_gui->game_menu_sound =
    filepath_to_sound("files/main_menu.wav");
    game_man->game_gui->touched = filepath_to_sound("files/touched.wav");
}