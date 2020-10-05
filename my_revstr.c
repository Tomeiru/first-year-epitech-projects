/*
** EPITECH PROJECT, 2020
** my_evil_str
** File description:
** my_evil_str
*/

void last_letter_swap(char *p, char *l)
{
    char z;

    z = *p;
    *p = *l;
    *l = z;
}

char *my_revstr(char *str)
{
    int l = 0;
    int m;
    int p;

    while (str[l] != '\0') {
        l++;
    }
    l--;
    m = l;
    p = 0;
    while (l != m / 2) {
        last_letter_swap(&str[p], &str[l]);
        p++;
        l--;
    }
    return (str);
}
