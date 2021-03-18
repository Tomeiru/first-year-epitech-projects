/*
** EPITECH PROJECT, 2021
** duo_stumper2
** File description:
** main
*/

#include "stumper.h"

void loop(game_t *game)
{
    int col;

    while (game->win == 0) {
        game->turn += 1;
        col = get_col(game);
        add_piece(game, col);
        check_win(game);
	for (int i = 0; game->map[i]; i++)
            printf("%s\n", game->map[i]);
    }
    if (game->win == 1)
        printf("Congrats, player %c won!\n", game->current_player);
    if (game->win == 2)
        printf("It's a tie, nobody wins.\n");
}

int main (int ac, char **av)
{
  game_t *game;

  error(ac, av);
  game = init_game(ac, av);
  loop(game);
  return (0);
}
