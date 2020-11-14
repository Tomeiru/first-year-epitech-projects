/*
** EPITECH PROJECT, 2020
** sources
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

void my_printf(char *format, ...);
int det_len_signed(long long nb);
int det_len_unsigned_dec(unsigned long long nb);
int det_len_unsigned_oct(unsigned long long nb);
int det_len_unsigned_hexa(unsigned long long nb);
int det_len_unsigned_bin(unsigned long long nb);
char *print_di(long long nb);
char *print_o(unsigned long long decimal);
char *print_u(unsigned long long nb);
char which_letter_min(unsigned long long decimal);
char *print_x(unsigned long long decimal);
char which_letter_maj(unsigned long long decimal);
char *print_xmaj(unsigned long long decimal);
char *print_b(unsigned long long decimal);
void print_alt_string(char *str, char *flag);
void print_str(char *str, char *flag);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_revstr(char *str);
void my_putchar(char c);
void my_putstr(char const *str);
void string(char *str);
void alt_string(char *str);
void nint(long long number, char *flag);
void hint(long long number, char *flag);
void hhint(long long number, char *flag);
void llint(long long number, char *flag);
void arg_oct(unsigned long long number, char *flag);
void arg_hexa(unsigned long long number, char *flag);
void arg_hexamaj(unsigned long long number, char *flag);
void arg_uns(unsigned long long number, char *flag);
void arg_bin(unsigned long long number, char *flag);
void noct(unsigned long long number, char *flag);
void hoct(unsigned long long number, char *flag);
void hhoct(unsigned long long number, char *flag);
void lloct(unsigned long long number, char *flag);
void nhexa(unsigned long long number, char *flag);
void hhexa(unsigned long long number, char *flag);
void hhhexa(unsigned long long number, char *flag);
void llhexa(unsigned long long number, char *flag);
void nhexamaj(unsigned long long number, char *flag);
void hhexamaj(unsigned long long number, char *flag);
void hhhexamaj(unsigned long long number, char *flag);
void llhexamaj(unsigned long long number, char *flag);
void nuns(unsigned long long number, char *flag);
void huns(unsigned long long number, char *flag);
void hhuns(unsigned long long number, char *flag);
void lluns(unsigned long long number, char *flag);
void nbin(unsigned long long number, char *flag);
void hbin(unsigned long long number, char *flag);
void hhbin(unsigned long long number, char *flag);
void llbin(unsigned long long number, char *flag);
int which_len_mod(char *flag);
char *flag_finder(char *format);
char *width_check(char *flag);
void print_width(char *width_mod, int length, char *print, char *flag);
void char_print(char number, char *flag);
void type_sort(char *flag, va_list list);
char *neg_int(char *print, int *nb);
int my_getnbr(char const *str);
void arg_int(char *flag, long long number);
void arg_uns_int(char *flag, unsigned long long number);
void arg_str(char *flag, char *str);
int which_type(char c);


#endif /* !MY_PRINTF_H_ */
