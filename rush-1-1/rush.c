/*
** EPITECH PROJECT, 2020
** rush
** File description:
** rush
*/

void top_bot_line(int a)
{
    int amax = a;
    
    while (a != 0) {
        if (a == amax || a == 1) {
            my_putchar('o');
            a--;
        }
        if (a < amax && a > 1) {
            my_putchar('-');
            a --;
        }
    }
    my_putchar('\n');
}

void between_lines(int b, int c)
{
    int bmax = b;

    c = c - 2;
    while (c > 0) {
        if (b == bmax)
            my_putchar('|');
        while (b > 2) {
            my_putchar(' ');
            b--;
        }
        b--;
        if (b == 1)
            my_putchar('|');
        c--;
        b = bmax;
        my_putchar('\n');
    }
}

void rush(int x, int y)
{
    if (x > 2147483647 || y > 2147483647 || x < 1 || y < 1) {
        write(2,"Invalid size\n", 13);
        return;
    }
     top_bot_line(x);
     between_lines(x, y);
     if (y >= 2)
         top_bot_line(x);
}
