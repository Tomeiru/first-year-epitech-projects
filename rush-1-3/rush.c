/*
** EPITECH PROJECT, 2020
** rush
** File description:
** rush
*/

void top_line(int a)
{
    int amax = a;

    if (a == amax) {
        my_putchar('A');
        a--;
    }
    while (a < amax && a > 1) {
        my_putchar('B');
        a--;
    }
    if (a == 1)
        my_putchar('A');
    my_putchar('\n');
}

void between_lines (int b, int c)
{
    c = c -2;
    int bmax = b;

    while (c > 0) {
        if (b == bmax)
            my_putchar('B');
        while (b != 2 && b > 0) {
            my_putchar (' ');
            b--;
        }
        b--;
        if (b == 1)
            my_putchar('B');
        c--;
        b = bmax;
        my_putchar('\n');
    }
}

void bot_line(int d)
{
    int dmax = d;

    if (d == dmax) {
        my_putchar('C');
        d--;
    }
    while (d < dmax && d > 1) {
        my_putchar('B');
        d--;
    }
    if (d == 1)
        my_putchar('C');
    my_putchar('\n');
}

void exception(int e, int f)
{
    if (e == 1 && f > 1)
        while (f != 0) {
            my_putchar('B');
            my_putchar('\n');
            f--;
        }
    if (e > 1 && f == 1) {
        while (e != 0) {
            my_putchar('B');
            e--;
        }
        my_putchar('\n');
    }
}

void rush(int x, int y)
{
    if (x > 2147483647 || y > 2147483647 || x < 1 || y < 1) {
        write(2, "Invalid size\n", 13);
        return;
    }
    if (x == 1 && y == 1) {
        my_putchar('B');
        my_putchar('\n');
    }
    if ((x == 1 && y > 1) || ( x > 1 && y == 1))
        exception(x, y);
    if (x > 1 && y > 1) {
        top_line(x);
        between_lines(x,y);
        if (y >=  2)
        bot_line(x);
    }
}
