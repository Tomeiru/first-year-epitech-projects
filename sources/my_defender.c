/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-mathieu.brujan
** File description:
** my_defender
*/

#include "my_defender.h"

sfRenderWindow *create_window(int width, int height, char *window_name)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window;
    
    window = sfRenderWindow_create(mode, window_name, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

game_t *ini_game_struct()
{

}

int my_defender(void)
{
    sfRenderWindow *window = create_window(1920, 1080, "MyDefender");
    game_t *game = ini_game_struct();
}