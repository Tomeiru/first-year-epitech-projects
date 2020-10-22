/*
** EPITECH PROJECT, 2020
** mix
** File description:
** mix
*/

int mix(char const *str)
{
    int count = add_counter(str);
    int *numb;
    int j = 1;
    char **endptr;

    numb = malloc(sizeof(int) * (count + 1));
    if (my_strsign(str) == '+' || my_strsign(str) == '-')
        numb[0] = my_strtol(str, &endptr);
    else {
        numb[0] = multi_fac(str);
        my_strtolfac(str, &endptr);
    }
    for (int i = 1; i <= count; i++)
        if (my_strsign(endptr) == '+' || my_strsign(endptr) == '-')
            numb[i] = my_strtol(endptr, &endptr);
        else {
            numb[i] = multi_fac(endptr);
            my_strtolfac(endptr, &endptr);
        }
    for (int i = 0; str[i]; i++) {
        if (str[i] == '+')
            numb[0] += numb[j];
        if (str[i] == '-')
            numb[0] -= numb[j];
        if (str[i] == '-' || str[i] == '+')
            j++;
    }
    return (numb[0]);
}