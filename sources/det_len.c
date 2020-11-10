/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** det_len
*/

#include "my_printf.h"

int det_len_signed(long long nb)
{
    int count = 0;
    int neg = 0;

    if (nb < 0)
        neg = 1;
    for ( ; nb != 0; count++)
        nb /= 10;
    if (neg == 1)
        count++;
    return (++count);
}

int det_len_unsigned_dec(unsigned long long nb)
{
    int count = 0;

    for ( ; nb != 0; count++)
        nb /= 10;
    return (++count);
}

int det_len_unsigned_oct(unsigned long long nb)
{
    int count = 0;

    for ( ; nb != 0; count++)
        nb /= 8;
    return (++count);
}

int det_len_unsigned_hexa(unsigned long long nb)
{
    int count = 0;

    for ( ; nb != 0; count++)
        nb /= 16;
    return (++count);
}

int det_len_unsigned_bin(unsigned long long nb)
{
    int count = 0;

    for ( ; nb != 0; count++)
        nb /= 2;
    return (++count);
}