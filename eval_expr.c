/*
** EPITECH PROJECT, 2020
** sumfac
** File description:
** takes care of add, sub, mul, div and modulo
*/

int my_strtol(char *str, char **endptr)
{
    int nbr = 0;
    int i = 0;
    int sign = 1;

    if (str[i] == '-') {
        sign *= -1;
        i++;
    }
    else if (str[i] == '+' || str[i] == '*' || str[i] == '/' || str[i] == '%')
        i++;
    for ( ; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            nbr = nbr * 10 + str[i] - 48;
        if (str[i] < '0' || str[i] > '9')
            break;
    }
    nbr *= sign;
    *endptr = &str[i];
    return (nbr);
}

int factors(char *str, char **endptr)
{
    int res = my_strtol(str, endptr);

    while (**endptr == '*' || **endptr == '/' || **endptr == '%') {
        if (**endptr == '*')
            res = res * my_strtol(*endptr, endptr);
        else if (**endptr == '/')
            res = res / my_strtol(*endptr, endptr);
        else
            res = res % my_strtol(*endptr, endptr);
    }
    return (res);
}

int summands(char **str_ptr)
{
    char *endptr = "test";
    int res = factors(*str_ptr, &endptr);

    while (*endptr == '+' || *endptr == '-')
            res += factors(endptr, &endptr);
    return (res);
}

int main(int argc, char **argv)
{
    if (argc == 2 && error(argv[1]) == 1) {
        my_put_nbr(summands(&argv[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}