/*
** EPITECH PROJECT, 2020
** rush
** File description:
** rush
*/

#include <unistd.h>
#include "rush.h"

static char *top_line(int a, char *square)
{
    int amax = a;
    int i = 0;

    if (a == amax) {
        square[i] = 'A';
        a--;
        i++;
    }
    while (a < amax && a > 1) {
        square[i] = 'B';
        a--;
        i++;
    }
    if (a == 1) {
        square[i] = 'A';
        i++;
    }
    square[i] = '\n';
    return (square);
}

static char *between_lines(int b, int c, char *square, int i)
{
    int bmax = b;

    for (c -= 2; c > 0; c-- && i++) {
        if (b == bmax) {
            square[i] = 'B';
            i++;
        } 
        for (b; b > 2; b--) {
            square[i] = ' ';
            i++;
        }
        b--;
        if (b == 1) {
            square[i] = 'B';
            i++;
        }
        b = bmax;
        square[i] = '\n';
    }
    return (square);
}

static char *bot_line(int a, char *square)
{
    int amax = a;
    int i = 0;

    for (i; square[i] != '\0'; i++);
    if (a == amax) {
        square[i] = 'C';
        a--;
        i++;
    }
    while (a < amax && a > 1) {
        square[i] = 'B';
        a--;
        i++;
    }
    if (a == 1) {
        square[i] = 'C';
        i++;
    }
    square[i] = '\n';
    return (square);
}

static char *exception(int e, int f, char *square)
{
    int i = 0;

    if (e == 1 && f > 1)
        while (f != 0) {
            square[i] = 'B';
            i++;
            square[i] = '\n';
            i++;
            f--;
        }
    if (e > 1 && f == 1) {
        while (e != 0) {
            square[i] = 'B';
            i++;
            e--;
        }
        square[i] = '\n';
    }
    return (square);
}

char *rush_three(int x, int y)
{
    char *square = malloc(sizeof(char) * (y * (x + 1) + 1));
    int i = 0;

    if (x == 1 && y == 1) {
        square[0] = 'B';
        square[1] = '\n';
    }
    if ((x == 1 && y > 1) || ( x > 1 && y == 1))
        square = exception(x, y, square);
    if (x > 1 && y > 1) {
        square = top_line(x, square);
        for (i; square[i] != '\0'; i++);
        square = between_lines(x, y, square, i);
        if (y >= 2)
            square = bot_line(x, square);
    }
    square[(y * (x + 1) + 1)] = '\0';
    return (square);
}