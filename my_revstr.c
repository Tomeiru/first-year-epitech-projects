/*
** EPITECH PROJECT, 2020
** my_rev_str
** File description:
** my_rev_str
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
    int p = 0;

    while (str[l] != '\0')
        l++;
    l--;
    m = l;
    while (l != m / 2) {
        last_letter_swap(&str[p], &str[l]);
        p++;
        l--;
    }
    return (str);
}
