/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** my_strstr
*/

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int m = 0;
    int l = 0;

    while (str[i] != '\0') {
        l = 0;
        for (m = 0; to_find[m] != '\0'; m++) {
            if (str[i + m] != to_find[m]) {
                l = 1;
                break;
            }
        }
        if (l != 1)
            return (&str[i]);
        i++;
    }
    return (0);
}