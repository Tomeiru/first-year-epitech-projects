int *square_size(char *buff)
{
    int *size = malloc(sizeof(int) * 2);

    for (size[0] = 0; buff[size[0]] != '\n'; ++size[0]);
    for (int i = 0; buff[i]; ++i)
        if (buff[i] == '\n')
            ++size[1];
    return (size);
}
int print(char *str, int *tab)
{
    my_putstr(str);
    my_putchar(' ');
    my_putnbr(tab[0]);
    my_putchar(' ');
    my_putnbr(tab[1]);

}
void display(int *tab, int *res, int i, int j)
{
    switch (i){
    case 0:
	print("[rush1-1]", tab);
    case 1:
        print("[rush1-2]", tab);
    case 2:
        print("[rush1-3]", tab);
    case 3:
        print("[rush1-4]", tab);
    case 4:
        print("[rush1-5]", tab);
    }
    if(j < 1)
	my_putstr(" || ");
    if(j == 1)
	my_putchar('\n'); 
}

int rush3(char *sqr)
{
    int *tab = square_size(sqr);
    int *res = malloc(sizeof(int) * 5);
    int j = 0;
    
    res[0] = sqcmp(sqr, rush1(tab[], tab[]));
    res[1] = sqcmp(sqr, rush2(tab[], tab[]));
    res[2] = sqcmp(sqr, rush3(tab[], tab[]));
    res[3] = sqcmp(sqr, rush4(tab[], tab[]));
    res[4] = sqcmp(sqr, rush5(tab[], tab[]));
    for(int i = 0; res[i]; i++)
	if(res[i] == 1)
	    j++;
    for(i = 0; res[i]; i++)
	if(res[i] == 1) {
	    display(tab, res, i, j);
	    j--;
	}
}
