/*
** EPITECH PROJECT, 2020
** tree
** File description:
** tree
*/

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

void leaves(int layer)
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
            star(1 + 2 * i, layermax * 3 - i);
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

void trunk(int htrunk)
{
    int ltrunk = htrunk;
    int ltrunkmax;
    int a = 3;

    while (a > 0) {
        my_putchar(' ');
        a--;
    }
    if (htrunk % 2 == 0)
        ltrunk = (ltrunk + 1);
    ltrunkmax = ltrunk;
    while (htrunk != 0) {
        while(ltrunk != 0) {
            my_putchar('|');
            ltrunk--;
        }    
    htrunk--;
    ltrunk = ltrunkmax;
    my_putchar('\n');
    }   
}

void tree(int size)
{
    if (size < 1)
        return;
    leaves(size);
    trunk(size);
}
