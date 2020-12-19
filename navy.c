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
    struct stat stats;
    char *pos_str;

    if (fd == -1 || stat(pos_file, &stats) == -1)
        error_write(1);
    pos_str = malloc(sizeof(char) * (stats.st_size + 1));
    if (read(fd, pos_str, stats.st_size) == -1)
        error_write(1);
    pos_str[stats.st_size] = '\0';
    close(fd);
    return (pos_str);
}

void init_struct(void)
{
    game_struct.pid = 0;
    game_struct.enemy_pid = 0;
    game_struct.wait = 0;
    game_struct.hit = 0;
    game_struct.enemy_hit = 0;
    game_struct.signal_received_x = 0;
    game_struct.signal_received_y = 0;
    game_struct.x = 0;
    game_struct.y = 0;
    game_struct.start = 0;
    game_struct.status = 0;
}

int navy(int ac, char **av)
{
    error_args(ac, av);
    init_struct();
    if (ac == 2)
        host(av[1]);
    else
        player_two(my_getnbr(av[1]), av[2]);
    return (0);
}