/*
** EPITECH PROJECT, 2020
** tree
** File description:
** tree
*/

int taille(int size)
{
    int width = -4;
    int hauteur = 0;
    int switcha = 3;
    int sus = 0;

    for (int q = 0; q <= size; q++) {
        hauteur = 3 + q;
        switcha--;
        if (switcha == 0) {
            sus = sus - 2;
            switcha = 2;
        }
        width = width - 2 + sus;
        width = width + (hauteur * 2);
        }
    printf("%i\n", width);
return (width);
}

void star (int k, int end)
{
    int p;
    p = 0;
    int space = 0;

    while (space < end) {
        my_putchar(' ');
        space++;
    }
    while (p < k) {
        my_putchar('*');
        p++;
    }
    my_putchar('\n');
}

void leaves(int layer, int val_maxx)
{
    int layermax = layer;
    int i = 0;
    int m = 0;
    int f = 1;
    int add = 0;
    int switcheroo = 3;

    layer = 1;

    int height = layer + 3;

    while (layer <= layermax){
        while (m < height) {
            star(1 + 2 * i, val_maxx / 2 - i);
            i++;
            m++;
        }
        switcheroo--;
        if (switcheroo == 0) {
            add = add - 1;
            switcheroo = 2;
        }
        i = i - 2 + add;
        layer++;
        height = layer + 3;
        m = 0;
    }
}

void trunk(int htrunk, int valmaxxx)
{
    int ltrunk = htrunk;
    int ltrunkmax;
    int z = 0;
    
    if (htrunk % 2 == 0) 
        ltrunk = (ltrunk + 1);
    ltrunkmax = ltrunk;
    while (htrunk != 0) {
        while(z < valmaxxx / 2 - (ltrunkmax / 2)) {
            my_putchar(' ');
            z++;
        }
        while(ltrunk != 0) {
            my_putchar('|');
            ltrunk--;
        }    
    htrunk--;
    ltrunk = ltrunkmax;
    z = 0;
    my_putchar('\n');
    }   
}

void tree(int size)
{
    if (size < 1)
        return;
    int val_max =  taille(size);
    leaves(size, val_max);
    trunk(size, val_max);
}
