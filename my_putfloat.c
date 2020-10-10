/*
** EPITECH PROJECT, 2020
** my_putfloat
** File description:
** my_putfloat
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int mod;

    if (nb >= 10)
    {
        mod = (nb % 10);
        nb = (nb - mod) / 10;
        my_put_nbr(nb);
        my_putchar(48 + mod);
    }
    else
        my_putchar(48 + nb % 10);
}

int my_putfloat(int ltr, int ltr_max)
{
    int f = (ltr * 10000 / ltr_max);
    int dec = f % 100;
    int val = f / 100;

    my_putchar(' ');
    my_putchar('(');
    my_put_nbr(val);
    my_putchar('.');
    if (dec < 10 && dec != 0)
        my_putchar('0');
    my_put_nbr(dec);
    if (dec == 0)
        my_putchar('0');
    my_putchar('%');
    my_putchar(')');
}