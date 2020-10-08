/*
** EPITECH PROJECT, 2020
** concat_params
** File description:
** concat_params
*/

#include <stdlib.h>

int letcounter(int argc, char **argv)
{
    int nbarg = 0;
    int nblet = 0;
    int nblettot = 0;

    while (nbarg < argc) {
        while (argv[nbarg][nblet] != '\0') {
            nblettot++;
            nblet++;
        }
        nblettot++;
        nbarg++;
        nblet = 0;
    }
    return (nblettot);
}

char *concat_params(int argc, char **argv)
{
    char *ret;
    int nbarg = 0;
    int nblet = 0;
    int nblettot = 0;

    ret = malloc(sizeof(char) * letcounter(argc, argv));
    for (nbarg = 0; nbarg < argc; nbarg++) {
        while (argv[nbarg][nblet] != '\0') {
            ret[nblettot] = argv[nbarg][nblet];
            nblet++;
            nblettot++;
        }
        ret[nblettot] = '\n';
        nblettot++;
        nblet = 0;
    }
    ret[nblettot - 1] = '\0';
    return (ret);
}