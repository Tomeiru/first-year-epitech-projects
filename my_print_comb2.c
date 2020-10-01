/*
** EPITECH PROJECT, 2020
** my_print_comb2
** File description:
** my_print_comb2
*/

int my_print_comb2(void)
{

    int m = 1;
    int a = 0;
    int b = 0;
    int z = 0;
    int y = 0;
    int n = 0;
    
    while (m <= 99) {
        a = m % 10;
        b = m / 10 % 10;
        z = n % 10;
        y = n / 10 % 10;
        m++;
        my_putchar (y + 48);
        my_putchar (z + 48);
        my_putchar (' ');
        my_putchar (b + 48);
        my_putchar (a + 48);
        if (n < 98){
            my_putchar (',');
            my_putchar (' ');
        }
        if (m == 100 && n < 98) {
            n++;
            m = n + 1;
        }
    }
}
