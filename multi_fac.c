/*
** EPITECH PROJECT, 2020
** multi_fac
** File description:
** multi_fac
*/

int multi_fac(char const *str)
{
    int count = fac_counter(str);
    int *numb;
    int j = 1;
    char **endptr;

    numb = malloc(sizeof(int) * (count + 1));
    numb[0] = my_strtol(str, &endptr);
    for (int i = 1; i <= count; i++)
        numb[i] = my_strtol(endptr, &endptr);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '*')
            numb[0] *= numb[j];
        if (str[i] == '/')
            numb[0] /= numb[j];
        if (str[i] == '%')
            numb[0] %= numb[j];
        if (str[i] == '*' || str[i] == '/' || str[i] == '%')
            j++;
        if (str[i] == '+')
            break;
    }
    return (numb[0]);
}