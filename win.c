/*
** EPITECH PROJECT, 2021
** duo_stumper2
** File description:
** game
*/

#include "stumper.h"

int win_horinzontal (game_t *game, int i, int j)
{
    int x = j;
    int cpt = 0;

    for ( ; game->map[i][x]; x++) {
        if (game->map[i][x] != game->current_player
            && game->map[i][x] != '#')
            break;
	cpt++;
    }
    if (cpt > 3) {
        game->win = 1;
        for (int x = j; x < j + cpt; x++)
            game->map[i][x] = '#';
    }
}

void win_vertical (game_t *game, int i, int j)
{
    int y = i;
    int cpt = 0;

    for (; game->map[y][j]; y++) {
        if (game->map[y][j] != game->current_player
            && game->map[y][j] != '#')
	    break;
	cpt++;
    }
    if (cpt > 3) {
        game->win = 1;
        for (int y = i; y < i + cpt; y++)
            game->map[y][j] = '#';
    }
}

void win_diagonal_r (game_t *game, int i, int j)
{
    int y = i;
    int x = j;
    int cpt = 0;

    for (; game->map[y][x]; y++) {
        if (game->map[y][x] != game->current_player
            && game->map[y][x] != '#')
	    break;
	cpt++;
	x++;
    }
    if (cpt > 3) {
        game->win = 1;
        y = i;
        x = j;
        for (; y < i + cpt; y++)
            game->map[y][x++] = '#';
    }
}

void win_diagonal_l (game_t *game, int i, int j)
{
    int y = i;
    int x = j;
    int cpt = 0;

    for (; game->map[y][x]; y++) {
        if (game->map[y][x] != game->current_player
            && game->map[y][x] != '#')
	    break;
	cpt++;
	x--;
    }
    if (cpt > 3) {
        game->win = 1;
        y = i;
        x = j;
        for (; y < i + cpt; y++)
            game->map[y][x--] = '#';
    }
}

void tie (game_t *game)
{
    if (game->turn >= game->width * game->height)
        game->win = 2;
}
