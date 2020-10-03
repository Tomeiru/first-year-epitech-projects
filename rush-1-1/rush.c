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
        if (a < amax && a > 1){
            my_putchar('-');
            a --;
        }
    }
    my_putchar('\n');
}

void between_lines(int b, int c)
{
    c = c - 2;
    int bmax = b;

    while (c > 0) {
        if (b == bmax)
            my_putchar('|');
        while (b != 2 && b > 0) {
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
    top_bot_line(x);
    between_lines(x, y);
    if (y >= 2)
    top_bot_line(x);
}

int main (void)
{
    rush (4, 4);
    return (0);
}
