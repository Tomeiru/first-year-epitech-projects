/*
** EPITECH PROJECT, 2020
** rush1-3
** File description:
**
*/

void top_line(int l1)
{
  int l1Max = l1;
  while (l1 != 0) {
    if (l1 == l1Max || l1 == 1) {
        my_putchar('A');
				--l1;}
    if (l1 < l1Max && l1 > 1){
        my_putchar('B');
				--l1;}
  }
  my_putchar('\n');
}

void between_lines(int l2, int h)
{
    h = h - 2;
    int l2Max = l2;

    while (h > 0) {
        if (l2 == l2Max)
            my_putchar('B');
        while (l2 != 2 && l2 > 0) {
            my_putchar(' ');
            l2--;
        }
        l2--;
        if (l2 == 1)
            my_putchar('B');
        h--;
        l2 = l2Max;
        my_putchar('\n');
    }
}

void bot_line(int l1)
{
  int l1Max = l1;

  while (l1 != 0) {
    if (l1 == l1Max || l1 == 1) {
        my_putchar('C');
        --l1;
    }
    if (l1 < l1Max && l1 > 1){
        my_putchar('B');
        --l1;
      }
    }
  my_putchar('\n');
}

void exeption(int l1, int l2)
{
  int l1Max = l1;

  if (l1 == 1){
  	while (l2 != 0) {
    	if (l2 <= l1Max || l2 >= 1) {
        	my_putchar('B');
        	--l2;}
				my_putchar('\n');}
			}
		if (l2 == 1) {
			while (l1 != 0) {
						my_putchar('B');
						--l1;
					}
					my_putchar('\n');}
}

void rush(int x, int y)
{
		if(x > 2147483647 || y > 2147483647 || x < 1 || y < 1) {
			write(2,"Invalid size\n", 13);
			return;
		}
    if (x == 1 && y == 1)
		{
      my_putchar('B');
      my_putchar('\n');
    }else {
      if (y == 1 || x == 1){
        exeption(x, y);
      }else{
      top_line(x);
      between_lines(x, y);
      bot_line(x);
    }
  }
}
