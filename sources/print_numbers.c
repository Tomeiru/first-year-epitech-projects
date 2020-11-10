/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_di
*/

#include "my_printf.h"

char *print_di(long long nb)
{
    int len = det_len_signed(nb);
    char *number = malloc(sizeof(char) * len);
    int i = 0;
    int neg = 0;

    if (nb < 0)
        neg = 1;
    if (nb == 0)
        return (my_strdup("0"));
    for (i; nb != 0; nb /= 10) {
        if (neg == 1)
            number[i++] = nb % 10 * -1 + 48;
        else
            number[i++] = nb % 10 + 48;
    }
    if (neg == 1)
        number[i++] = '-';
    number[i] = '\0';
    my_revstr(number);
    return (number);
}

char *print_b(unsigned long long decimal)
{
    int len = det_len_unsigned_bin(decimal);
    char *binary = malloc(sizeof(char) * len);
    int i = 0;

    if (decimal == 0)
        return (my_strdup("0"));
    for ( ; decimal != 0; decimal /= 2)
        binary[i++] = decimal % 2 + 48;
    binary[i] = '\0';
    my_revstr(binary);
    return (binary);
}

char *print_o(unsigned long long decimal)
{
    int len = det_len_unsigned_oct(decimal);
    char *octal = malloc(sizeof(char) * len);
    int i = 0;

    if (decimal == 0)
        return (my_strdup("0"));
    for ( ; decimal != 0; decimal /= 8)
        octal[i++] = decimal % 8 + 48;
    octal[i] = '\0';
    my_revstr(octal);
    return (octal);
}

char *print_u(unsigned long long nb)
{
    int len = det_len_unsigned_dec(nb);
    char *number = malloc(sizeof(char) * len);
    int i = 0;

    if (nb == 0)
        return (my_strdup("0"));
    for (i; nb != 0; nb /= 10) {
        number[i++] = nb % 10 + 48;
    }
    number[i] = '\0';
    my_revstr(number);
    return (number);
}