/*
** EPITECH PROJECT, 2020
** rush
** File description:
** rush
*/

#include <unistd.h>
#include "rush.h"

static char *top_bot_line(int a, char *square)
{
    int amax = a;
    int i = 0;

    for (i; square[i] != '\0'; i++);
    while (a != 0) {
        if (a < amax && a > 1)
            square[i] = '-';
        if (a == amax || a == 1)
            square[i] = 'o';
        i++;
        a--;
    }
    square[i] = '\n';
    return (square);
}

static char *between_lines(int b, int c, char *square, int i)
{
    int bmax = b;

    for (c -= 2; c > 0; c--) {
        if (b == bmax) {
            square[i] = '|';
            i++;
        } 
        for (b; b > 2; b--) {
            square[i] = ' ';
            i++;
        }
        b--;
        if (b == 1) {
            square[i] = '|';
            i++;
        }
        b = bmax;
        square[i++] = '\n';
    }
    return (square);
}

char *rush_one(int x, int y)
{
    char *square = malloc(sizeof(char) * (y * (x + 1) + 1));
    int i = 0;

    square = top_bot_line(x, square);
    for (i; square[i] != '\0'; i++);
    square = between_lines(x, y, square, i);
    if (y >= 2)
        square = top_bot_line(x, square);
    square[(y * (x + 1) + 1)] = '\0';
    return (square);
}