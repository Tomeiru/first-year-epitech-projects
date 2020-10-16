/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** infinadd
*/

#ifndef INFINADD_H_
#define INFINADD_H_

#include <stdlib.h>
char *absol(char *num, int sign, int length);
int biggest_number (char *fst_num, char *sec_num, int fst_sign, int sec_sign);
int error (int ac, char **av);
int infinadd(char *fst_num, char *sec_num);
int is_valid_num(char const *str);
int longest_string(int first, int second, int fst_sign, int sec_sign);
int main(int argc, char **argv);
int my_sign(char *num);
void same_tenth(char *fst_num, char *sec_num, int fst_sign, int sec_sign);
char *stenth_dsign(char *fst_num, char *sec_num, int retenue, int number);
char *stenth_ssign(char *fst_num, char *sec_num, int retenue, int number);
char *zero(char *str, int dif, int len);
void first_longest(char *fst_num, char *sec_num, int fst_sign, int sec_sign);
void second_longest(char *fst_num, char *sec_num, int fst_sign, int sec_sign);

#endif /* !INFINADD_H_ */
