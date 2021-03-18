/*
** EPITECH PROJECT, 2021
** duo_stumper2
** File description:
** structs
*/

#include "stumper.h"
#include <stdlib.h>


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
    return (game);
}
      
