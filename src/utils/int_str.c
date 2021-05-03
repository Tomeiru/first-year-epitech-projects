/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** int and str
*/

void int_to_str(int value, char *buff, int buff_len)
{
    int pos = 0;
    char c;

    if (value == 0)
        *buff = '0';
    while (value > 0 && pos < buff_len) {
        c = value % 10 + '0';
        for (int i = pos; i >= 0; i--)
            buff[i + 1] = buff[i];
        buff[0] = c;
        pos++;
        value /= 10;
    }
}

int str_to_int(char *str)
{
    int value = 0;
    char neg = 0;

    if (*str == '-') {
        neg = 1;
        str++;
    }
    for (; *str; str++)
        value = value * 10 + (*str - '0');
    if (neg)
        value *= -1;
    return (value);
}

float str_to_float(char *str)
{
    char *cpy = str;
    float value = 0;

    for (; *cpy && *cpy != '.'; cpy++);
    if (!*cpy)
        return (str_to_int(str));
    *cpy = 0;
    value = str_to_int(str);
    cpy++;
    for (float fact = 0.1; *cpy; cpy++, fact *= 0.1)
        value += (*cpy - '0') * fact;
    return (value);
}