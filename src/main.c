/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main
*/

#include "my_rpg.h"

sfRenderWindow *create_window(int width, int height)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window =
    sfRenderWindow_create(mode, WINDOW_TITLE, sfDefaultStyle, NULL);
    sfView *view = sfView_create();
    sfVector2f view_size = {WINDOW_WIDTH, WINDOW_HEIGHT};
    sfVector2f view_center = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};

    sfView_setSize(view, view_size);
    sfView_setCenter(view, view_center);
    sfRenderWindow_setView(window, view);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

static void print_help(void)
{
    my_putstr("MY_DEFENDER\n" \
    "DESCRIPTION\n" \
    "     Protect your base from enemies by build defenses\n" \
    "\nCONTROLS\n" \
    "     Escape: pause (during game)\n");
}

int main(int ac, char *av[])
{
    sfRenderWindow *window;
    int ret;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    }
    window = create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    ret = my_rpg(window);
    return (ret);
}