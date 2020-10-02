/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** Function that counts and returns the number of characters found in the string passed as parameter.
*/

int my_put_nbr(int l)
{
    int den = 1;

    if (l < 0){
        my_putchar(',');
        l = l * -1;
    }
    while ((l/den) >= 10){
        den*=10;
    }
    while (den > 0){
        my_putchar((l/den) % 10 + '0');
        den /= 10;
    }
    return (0);
}

int my_strlen(char const *str)
{
    int l;

    while (str[l] != '\0'){
        l = l + 1;
    }
    my_put_nbr(l);
}
