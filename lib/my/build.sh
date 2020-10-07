#! /bin/sh
gcc -Wall -c *.c
ar rc libmy.a *.o
mv libmy.a ..
