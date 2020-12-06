/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** error
*/

#include "cipher.h"

static int help(void)
{
    printf("USAGE\n    ./103cipher message key flag\n\n");
    printf("DESCRIPTION\n    message     a message, made of ASCII characters\n    key         the encryption key, made of ASCII characters\n");
    printf("    flag        0 for the message to be encrypted, 1 to be decrypted\n");
    exit(84);
}

static void check_args(char **av)
{
    for (int i = 0; av[i]; i++) {
        for (int j = 0; av[i][j]; j++) {
            if (av[i][j] < 32 || av[i][j] > 127) {
                printf("Error: the message and the key must be in a printable ascii character, currently '%s'\n", av[i]);
                exit(84);
            }
        }
    }
    if (strcmp(av[3], "0") != 0 && strcmp(av[3], "1") != 0) {
        printf("Error: the flag must be one (for encryption) or zero (for decryption), currently '%s'\n", av[3]);
        exit(84);
    }
}

int error(int ac, char **av)
{
    if ((ac == 2 && av[1][0] == '-' && av[1][1] == 'h') || ac != 4)
        return (help());
    check_args(av);
    return (0);
}