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
    char *endptr;

    numb = malloc(sizeof(int) * (count + 1));
    numb[0] = assign_value(str, &endptr);
    for (int i = 1; i <= count; i++)
        numb[i] = assign_value(endptr, &endptr);
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