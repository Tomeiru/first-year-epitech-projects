/*
** EPITECH PROJECT, 2021
** duo_stumper2
** File description:
** structs
*/

#include "stumper.h"
#include <stdlib.h>


char **create_map(game_t *game)
{
    char **map = malloc(sizeof(char *) * (game->height + 3));
    int i = 0;

    for (i = 0; i < game->height + 2; i++)
        map[i] = malloc(sizeof(char) * (game->width + 3));
    map[i] = NULL;
    for (i = 0; i < game->width + 2; i++) {
        map[0][i] = '+';
        map[game->height + 1][i] = '+';
    }map[0][i] = '\0';
    map[game->height + 1][i] = '\0';
    for (i = 1; i < game->height + 1; i++) {
        for (int j = 0; j < game->width + 2; j++) {
            map[i][j] = '.';
            map[i][0] = '|';
            map[i][game->width + 1] = '|';
        }
    }
    return (map);
}

void game_default(game_t *game)
{
    game->width = 7;
    game->height = 6;
    game->p1 = 'X';
    game->p2 = 'O';
    game->referee = '#';
}

game_t *init_game(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));

    game_default(game);
    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "-w") == 0)
	    game->width = atoi(av[i + 1]);
	if (strcmp(av[i], "-h") == 0)
	    game->height = atoi(av[i + 1]);
	if (strcmp(av[i], "-p1") == 0)
	    game->p1 = av[i + 1][0];
	if (strcmp(av[i], "-p2") == 0)
	    game->p2 = av[i + 1][0];
	if (strcmp(av[i], "-a") == 0)
	    game->referee = av[i + 1][0];
    }
    game->map = create_map(game);
    return (game);
}
