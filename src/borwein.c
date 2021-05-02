/*
** EPITECH PROJECT, 2021
** 110borwein
** File description:
** borwein
*/

#include "borwein.h"

double borwein_calc(double n, double x)
{
    double ret = 0;

    if (x == 0)
        return (1);
    ret = (sin(x))/(x);
    for (double k = 1; k <= n ; k++) {
        ret *= ((sin(x/(2 * k + 1)))/(x/(2 * k + 1)));
    }return (ret);
}

void midpoint(int n, double half_pi)
{
    double x = 0;
    double y = 0.5;
    double result = 0;

    for (int i = 0; i < 10000; i++) {
        result += (borwein_calc((double)n, ((x + y)/2)) * (0.5));
        x += 0.5;
        y += 0.5;
    }printf("Midpoint:\nI%i = %.10f\ndiff = %.10f\n\n", n, result, fabs(result - half_pi));
}

void trapezoidal(int n, double half_pi)
{
    double x = 0;
    double y = 0.5;
    double result = 0;

    for (int i = 0; i < 10000; i++) {
        result += (borwein_calc((double)n, x) + borwein_calc((double)n, y)) * (0.25);
        x += 0.5;
        y += 0.5;
    }printf("Trapezoidal:\nI%i = %.10f\ndiff = %.10f\n\n", n, result, fabs(result - half_pi));
}

void simpson(int n, double half_pi)
{
    double x = 0;
    double y = 0.5;
    double result = 0;

    for (int i = 0; i < 10000; i++) {
        result += ((borwein_calc((double)n, x) + borwein_calc((double)n, y)) + (4 * (borwein_calc((double)n, ((x + y) / 2))))) * (0.5/6);
        x += 0.5;
        y += 0.5;
    }
    printf("Simpson:\nI%i = %.10f\ndiff = %.10f\n", n, result, fabs(result - half_pi));
}

void borwein(int n)
{
    double half_pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679/2;

    midpoint(n, half_pi);
    trapezoidal(n, half_pi);
    simpson(n, half_pi);
}