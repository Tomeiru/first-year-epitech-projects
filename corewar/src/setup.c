/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** setup
*/

#include "corewar.h"

int init_arena(info_t *info)
{
    arena_t *arena = malloc(sizeof(arena_t));

    arena->memory[MEM_SIZE] = '\0';
    return (0);
}

int load_instructions(info_t *info, champion_t *champion, char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    unsigned short int *buff;
    struct stat file;

    if (fd <= 0)
        return (84);
    stat(filepath, &file);
    buff = malloc(sizeof(short int) * (file.st_size + 1));
    read(fd, buff, file.st_size);
    close(fd);
    //check magic number
    //get champions name
    //load instructions into memory
}

int init_champion(info_t *info, int prog_number, int load_address, char *filepath)
{
    champion_t *champion = malloc(sizeof(champion_t));

    info->nbr_alive++;
    champion->carry = 0;
    champion->last_live = 0;
    if (prog_number >= 0)
        champion->id = prog_number;
    else
        champion->id = info->nbr_alive;
    if (load_address >= 0)
        champion->PC = load_address;
    load_instructions(info, champion, filepath);
    champion->next = info->champions;
    info->champions = champion;
    return (0);
}

int get_params(char **av, info_t *info)
{
    int prog_number = -1;
    int load_address = -1;

    av++;
    while (av[0] != NULL) {
        if (my_strcmp(av[0], "-dump") == 1) {
            info->dump = my_getnbr(av[1]);
            av+=2;
        }
        if (my_strcmp(av[0], "-n") == 1) {
            prog_number = my_getnbr(av[1]);
            av+=2;
        }
        if (my_strcmp(av[0], "-a") == 1) {
            load_address = my_getnbr(av[1]);
            av+=2;
        }
        if (av[0][0] != '-') {
            init_champion(info, prog_number, load_address, av++[0]);
            prog_number = -1;
            load_address = -1;
        }
    }
}

int init_info(info_t *info, char **av)
{
    info->cycle = 0;
    info->cycle_to_die = CYCLE_TO_DIE;
    info->nbr_alive = 0;
    info->nbr_live = 0;
}