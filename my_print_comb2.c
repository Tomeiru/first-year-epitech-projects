/*
** EPITECH PROJECT, 2020
** my_print_comb2
** File description:
** Write a function that displays, in ascending order, all the different combinations of two two-digit numbers.
*/

int my_print_comb2(void)
{
    int a;
    int b;
    int m = 0;
    int y;
    int z;
    int n = 1;

    while (m<=99) {
        a = m % 10;
        b = m / 10 % 10;
        m++;
        my_putchar (48);
        my_putchar (48);
        my_putchar (' ');
        my_putchar (b + 48);
        my_putchar (a + 48);
        my_putchar (',');
        my_putchar (' ');
    }
    while (n<=98) {
        y = n % 10;
        z = n / 10 % 10;
        n++;
        my_putchar (z + 48);
        my_putchar (y + 48);
        my_putchar (' ');
        my_putchar (z + 48);
        my_putchar (y + 49);
        my_putchar (',');
        my_putchar (' ');
        my_putchar (z + 48);
        my_putchar (y + 48);
        my_putchar (' ');
        my_putchar (b + 48);
        my_putchar (b + 48);
        if(n <= 98) {
        my_putchar (',');
        my_putchar (' ');
        }
    }
}
