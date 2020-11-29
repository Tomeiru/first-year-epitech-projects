/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-mathieu.brujan
** File description:
** main
*/

#include "my_hunter.h"

static void print_help()
{
    int fd = open("files/help", O_RDONLY);
    char *help_text = malloc(sizeof(char) * 511);

    read(fd, help_text, 510);
    help_text[510] = '\0';
    my_printf("%s\n", help_text);
    free(help_text);
    close(fd);
    return;
}

int main(int ac, char **av)
{
    if (ac == 2 && (av[1][0] == '-' || av[1][1] == 'h'))
        print_help();
    else if(ac == 1)
        game();
    else
        return (84);
}