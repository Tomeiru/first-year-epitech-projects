/*
** EPITECH PROJECT, 2020
** rush
** File description:
** rush
*/

int *square_size(char *buff)
{
    int *size = malloc(sizeof(int) * 2);

    for (size[0] = 0; buff[size[0]] != '\n'; ++size[0]);
    for (int i = 0; buff[i]; ++i)
        if (buff[i] == '\n')
            ++size[1];
    return (size);
}
void print(char *str, int *tab)
{
    my_putstr(str);
    my_putchar(' ');
    my_put_nbr(tab[0]);
    my_putchar(' ');
    my_put_nbr(tab[1]);

}
void display(int *tab, int *res, int i, int j)
{
    switch (i) {
    case 0 :
	    print("[rush1-1]", tab);
        break;
    case 1 :
        print("[rush1-2]", tab);
        break;
    case 2 :
        print("[rush1-3]", tab);
        break;
    case 3 :
        print("[rush1-4]", tab);
        break;
    case 4 :
        print("[rush1-5]", tab);
        break;
    }
    if(j > 1)
	my_putstr(" || ");
    if(j == 1)
	my_putchar('\n'); 
}

int rush(char *sqr)
{
    int *tab = square_size(sqr);
    int *res = malloc(sizeof(int) * 6);
    int j = 0;
    
    res[0] = sqcmp(sqr, rush_one(tab[0], tab[1]));
    res[1] = sqcmp(sqr, rush_two(tab[0], tab[1]));
    res[2] = sqcmp(sqr, rush_three(tab[0], tab[1]));
    res[3] = sqcmp(sqr, rush_four(tab[0], tab[1]));
    res[4] = sqcmp(sqr, rush_five(tab[0], tab[1]));
    res[5] = -1;
    if (error(res) == 84) {
        my_putstr("none\n");
        return (84);
    }
    for (int i = 0; res[i] != -1; i++)
	    if(res[i] == 1)
	        j++;
    for(int i = 0; res[i] != -1; i++)
	    if(res[i] == 1) {
	        display(tab, res, i, j);
	        j--;
	    }
}
