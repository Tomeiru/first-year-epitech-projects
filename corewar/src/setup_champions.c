/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** setup
*/

#include "../include/corewar.h"

unsigned char *openfile(char *filepath, int *len)
{
    int fd = open(filepath, O_RDONLY);
    struct stat file;
    unsigned char *buff;

    if (fd <= 0)
        return (NULL);
    if (stat(filepath, &file) != 0 || file.st_size == 0)
        return (NULL);
    buff = malloc(sizeof(unsigned char) * (file.st_size + 1));
    if (!buff)
        return (NULL);
    if (read(fd, buff, file.st_size) == -1)
        return (NULL);
    *len = file.st_size;
    close(fd);
    buff[file.st_size] = '\0';
    return (buff);
}

int load_instructions(info_t *info, champion_t *champion, char *filepath)
{
    int len = 0;
    unsigned char *buff = openfile(filepath, &len);
    int cpt = 4;
    int i = 0;

    if (!buff) {
        return (84);
    }
    if (buff[1] != 0xea || buff[2] != 0x83 || buff[3] != 0xf3) {
        return (84);
    }
    for (; buff[cpt] != 0; cpt++)
        champion->name[i++] = buff[cpt];
    champion->name[i] = '\0';
    cpt = PROG_NAME_LENGTH + 16 + COMMENT_LENGTH;
    for (i = champion->PC; cpt <= len; cpt++)
        info->arena->memory[i++] = buff[cpt];
    return (0);
}

int init_champion(info_t *info, params_t *params)
{
    champion_t *champion = malloc(sizeof(champion_t));

    info->nbr_alive++;
    champion->op_cycle = 1;
    champion->carry = 0;
    champion->PC = 1;
    if (params->load_address >= 0)
        champion->PC = params->load_address;
    else if (info->nbr_alive > 1)
        champion->PC = MEM_SIZE/info->nbr_champions;
    champion->last_live = 0;
    if (params->prog_number >= 0)
        champion->id = params->prog_number;
    else
        champion->id = info->nbr_alive;
    champion->params = NULL;
    champion->current_op = NULL;
    champion->next = info->champions;
    info->champions = champion;
    return (load_instructions(info, champion, params->filepath));
}

int get_flags(info_t *info, params_t *params, char **av)
{
    if (my_strcmp(av[0], "-dump") == 1) {
        info->dump = my_getnbr(av[1]);
        av += 2;
        return (0);
    }
    if (my_strcmp(av[0], "-n") == 1) {
        params->prog_number = my_getnbr(av[1]);
        av += 2;
        return (0);
    }
    if (my_strcmp(av[0], "-a") == 1) {
        params->load_address = my_getnbr(av[1]);
        av += 2;
        return (0);
    }
    return (84);
}

int get_params(char **av, info_t *info)
{
    params_t *params = malloc(sizeof(params));

    av++;
    while (av[0] != NULL) {
        if (av[0][0] == '-' && get_flags(info, params, av) == 84) {
            return (84);
        } else if (av[0][0] != '-'){
            params->filepath = av[0];
            init_champion(info, params);
            av++;
            params = &(params_t){-1, -1, NULL};
        }
    }
    return (0);
}