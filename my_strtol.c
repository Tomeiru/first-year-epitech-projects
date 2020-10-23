/*
** EPITECH PROJECT, 2020
** my_strtol
** File description:
** my_strtol
*/

void my_strtolfac(char const *str, char **endptr)
{
    int i = 0;
    int sign = 1;
    long number = 0;

    if (str[0] == '-') {
        sign = sign * -1;
        i++;
    }
    for ( ; str[i]; i++) {
        if ((str[i] > 57 || str[i] < 48) && (str[i] != '*') && (str[i] != '%')&&
        (str[i] != '/'))
            break;
    }
    for (int a = 0; a <= i; str++ && a++);
    *endptr = str;
}

int my_strtol(char const *str, char **endptr)
{
    int i = 0;
    int sign = 1;
    long number = 0;

    if (str[0] == '-') {
            sign = sign * -1;
            i++;
    }
    for (i; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            number = number * 10 + str[i] - '0';
        if (str[i] > 57 || str[i] < 48)
            break;
    }
    number = number * sign;
    if (number > 2147483647 || number < -2147483648)
        return (0);
    for (int a = 0; a <= i; str++ && a++);
    *endptr = str;
    return ((int)number);
}

int my_strsign(char const *str)
{
    int i = 0;
    int sign = 1;
    long number = 0;

    if (str[0] == '-') {
            sign *= -1;
            i++;
    }
    for (i; str[i]; i++) {
        if (str[i] > 57 || str[i] < 48)
            break;
    }
    return(str[i]);
}

int assign_value(char const *str, char **endptr)
{
    int nbr = 0;
    int count = fac_counter(str);

    if (my_strsign(str) == '+' || my_strsign(str) == '-')
        nbr = my_strtol(str, endptr);
    else {
        nbr = multi_fac(str, count);
        my_strtolfac(str, endptr);
    }
    return (nbr);
}