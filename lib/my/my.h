/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** contains all protos of functions in lib/my/
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int	my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
int my_putnbr_err(int nb);
void my_putchar(char c);
void my_putchar_err(char c);
void my_putstr(char const *str);
void my_putstr_err(char const *str);
char *my_revstr(char *str);
void my_swap_letter(char *a, char *b);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
int my_str_isalpha(char *str);
int my_str_islower(char *str);
int my_str_isnum(char *str);
int my_str_isprintable(char *str);
int my_str_isupper(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);

#endif /* !MY_H_ */