/*
** EPITECH PROJECT, 2020
** my_print_comb
** File description:
** my_print_comb
*/

int my_print_comb(void)
{
    int a;
    int b;
    int c;
    int n;

    n = 0;
    while (n<=789) {
        a = n % 10;
        b = n / 10 % 10;
        c = n / 100 % 10;
    if (c < b && b < a) {
        my_putchar(c+48);
        my_putchar(b+48);
        my_putchar(a+48);

        if (n<789) {
            my_putchar(',');
            my_putchar(' ');
        }
    }   
    n++;           
    }
    return (0);
}
        
