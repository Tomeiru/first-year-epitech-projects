/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** texts
*/

#include "../include/my_defender.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_revstr(char *str)
{
    char temp;
    int j = my_strlen (str) - 1;
    int i = 0;

    for (i; i <= j; i++) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    return (str);
}

char *int_to_char(int nbr)
{
    char *result = malloc(10);
    int i;

    if (nbr == 0)
        return ("0");
    for (i = 0; nbr > 0; i++) {
        result[i] = nbr % 10 + 48;
        nbr /= 10;
    }
    result[i] = '\0';
    my_revstr(result);
    return (result);
}

void init_texts(game_t *game)
{
    game->texts.font = sfFont_createFromFile("assets/font.ttf");
    game->texts.gold = sfText_create();
    sfText_setFont(game->texts.gold, game->texts.font);
    sfText_setPosition(game->texts.gold, (sfVector2f){1655, 925});
    game->texts.wave = sfText_create();
    sfText_setFont(game->texts.wave, game->texts.font);
    sfText_setPosition(game->texts.wave, (sfVector2f){1655, 980});
    game->texts.ennemies = sfText_create();
    sfText_setFont(game->texts.ennemies, game->texts.font);
    sfText_setPosition(game->texts.ennemies, (sfVector2f){1655, 1035});
}

void draw_texts(game_t *game, sfRenderWindow *window)
{
    sfText_setString(game->texts.gold, int_to_char(game->game_scene->gold));
    sfText_setString(game->texts.ennemies,
        int_to_char(game->game_scene->wave.nbr_ennemies));
    sfText_setString(game->texts.wave, int_to_char(game->game_scene->wave.index));
    sfRenderWindow_drawText(window, game->texts.gold, NULL);
    sfRenderWindow_drawText(window, game->texts.ennemies, NULL);
    sfRenderWindow_drawText(window, game->texts.wave, NULL);
}