/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** navy
*/

#include "navy.h"

char *get_pos_str(char *pos_file)
{
    int fd = open(pos_file, O_RDONLY);
    char *pos_str;

    if (fd == -1)
        return ("!");
    pos_str = malloc(sizeof(char) * (32 + 1));
    if (read(fd, pos_str, 32) == -1)
        return ("!");
    pos_str[32] = '\0';
    close(fd);
    return (pos_str);
}

void reset_glob(void)
{
    game_struct.wait = 0;
    game_struct.status = 2;
    game_struct.signal_rec_x = 0;
    game_struct.signal_rec_y = 0;
    game_struct.x = 0;
    game_struct.y = 0;
}

void init_struct(void)
{
    game_struct.pid = 0;
    game_struct.enemy_pid = 0;
    game_struct.wait = 0;
    game_struct.hit = 0;
    game_struct.enemy_hit = 0;
    game_struct.signal_rec_x = 0;
    game_struct.signal_rec_y = 0;
    game_struct.x = 0;
    game_struct.y = 0;
    game_struct.start = 0;
    game_struct.status = 0;
}

int navy(int ac, char **av)
{
    if (error_args(ac, av) == 84)
        return (84);
    init_struct();
    if (ac == 2)
        return (host(av[1]));
    else
        return (player_two(my_getnbr(av[1]), av[2]));
    return (0);
}