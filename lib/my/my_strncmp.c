/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int p = 0;
    int ans = 0;

    if (n == 0)
        return (0);
    while (s1[p] != '\0' || s2[p] != '\0') {
        if (s1[p] == s2[p] || n < p)
            p++;
        else {
            ans = s1[p] - s2[p];
            return (ans);
        }
    }
    return (0);
}
