/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

unsigned char my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    int number = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '-')
            sign = sign * -1;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10;
            number = number + str[i] - '0';
        }
    }
    number = number * sign;
    if (number > 2147483647 || number < -2147483647)
        return (0);
    return ((unsigned char)number);
}

int my_put_nbr(int nb)
{
    int den = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    while ((nb/den) >= 10) {
        den*=10;
    }
    while (den > 0) {
        my_putchar((nb/den) % 10 + '0');
        den /= 10;
    }
    return (0);
}