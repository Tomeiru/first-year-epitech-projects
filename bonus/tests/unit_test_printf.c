#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include "../includes/my_printf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(my_printf, simple_strings, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, simple_strings_with_newlines, .init = redirect_all_std)
{
    my_printf("première ligne\net boom seconde ligne\ntroisième ehe");
    cr_assert_stdout_eq_str("première ligne\net boom seconde ligne\ntroisième ehe");
}

Test(my_printf, simple_int_i, .init = redirect_all_std)
{
    my_printf("%i", 17);
    cr_assert_stdout_eq_str("17");
}

Test(my_printf, simple_int_d, .init = redirect_all_std)
{
    my_printf("%d", 17);
    cr_assert_stdout_eq_str("17");
}

Test(my_printf, simple_ints_i, .init = redirect_all_std)
{
    my_printf("this is number %i and i'm %i", 94, 21);
    cr_assert_stdout_eq_str("this is number 94 and i'm 21");
}

Test(my_printf, simple_ints_d, .init = redirect_all_std)
{
    my_printf("this is number %d and i'm %d", 94, 21);
    cr_assert_stdout_eq_str("this is number 94 and i'm 21");
}

Test(my_printf, simple_ints_i_and_d, .init = redirect_all_std)
{
    my_printf("this is number %i and i'm %d", 94, -21);
    cr_assert_stdout_eq_str("this is number 94 and i'm -21");
}

Test(my_printf, simple_ints_d_and_i, .init = redirect_all_std)
{
    my_printf("this is number %d and i'm %i", 94, 21);
    cr_assert_stdout_eq_str("this is number 94 and i'm 21");
}

Test(my_printf, simple_int_u, .init = redirect_all_std)
{
    my_printf("%u", 17);
    cr_assert_stdout_eq_str("17");
}

Test(my_printf, simple_ints_u, .init = redirect_all_std)
{
    my_printf("this is number %u and i'm %u", 94, -21);
    cr_assert_stdout_eq_str("this is number 94 and i'm 4294967275");
}

Test(my_printf, simple_int_x, .init = redirect_all_std)
{
    my_printf("%x", 17);
    cr_assert_stdout_eq_str("11");
}

Test(my_printf, simple_ints_x, .init = redirect_all_std)
{
    my_printf("this is number %x and i'm %x", 94, -21);
    cr_assert_stdout_eq_str("this is number 5e and i'm ffffffeb");
}

Test(my_printf, simple_int_X, .init = redirect_all_std)
{
    my_printf("%X", 17);
    cr_assert_stdout_eq_str("11");
}

Test(my_printf, simple_ints_X, .init = redirect_all_std)
{
    my_printf("this is number %X and i'm %X", 94, -21);
    cr_assert_stdout_eq_str("this is number 5E and i'm FFFFFFEB");
}

Test(my_printf, simple_int_o, .init = redirect_all_std)
{
    my_printf("%o", 17);
    cr_assert_stdout_eq_str("21");
}

Test(my_printf, simple_ints_o, .init = redirect_all_std)
{
    my_printf("this is number %o and i'm %o", 94, -21);
    cr_assert_stdout_eq_str("this is number 136 and i'm 37777777753");
}

Test(my_printf, simple_int_b, .init = redirect_all_std)
{
    my_printf("%b", 17);
    cr_assert_stdout_eq_str("10001");
}

Test(my_printf, simple_ints_b, .init = redirect_all_std)
{
    my_printf("this is number %b and i'm %b", 94, -21);
    cr_assert_stdout_eq_str("this is number 1011110 and i'm 11111111111111111111111111101011");
}

Test(my_printf, simple_str_s, .init = redirect_all_std)
{
    my_printf("%s", "woah\n");
    cr_assert_stdout_eq_str("woah\n");
}

Test(my_printf, simple_strs_s, .init = redirect_all_std)
{
    my_printf("%s%s", "woah", "\nwoah part 2");
    cr_assert_stdout_eq_str("woah\nwoah part 2");
}

Test(my_printf, simple_str_S, .init = redirect_all_std)
{
    my_printf("%S", "woah\n");
    cr_assert_stdout_eq_str("woah\\012");
}

Test(my_printf, simple_strs_S, .init = redirect_all_std)
{
    my_printf("%S%S", "woah", "\nwoah part 2");
    cr_assert_stdout_eq_str("woah\\012woah part 2");
}

Test(my_printf, simple_char_c, .init = redirect_all_std)
{
    my_printf("%c", 'u');
    cr_assert_stdout_eq_str("u");
}

Test(my_printf, simple_chars_c, .init = redirect_all_std)
{
    my_printf("%c%c", 'u', 'p');
    cr_assert_stdout_eq_str("up");
}

Test(my_printf, simple_prcent, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, simple_prcents, .init = redirect_all_std)
{
    my_printf("%%%%%%%%%");
    cr_assert_stdout_eq_str("%%%%%");
}

Test(my_printf, simple_char_width_c, .init = redirect_all_std)
{
    my_printf("%-9cm", 'X');
    cr_assert_stdout_eq_str("X        m");
}

Test(my_printf, simple_str_width_s, .init = redirect_all_std)
{
    my_printf("%-28sP", "koko");
    cr_assert_stdout_eq_str("koko                        P");
}

Test(my_printf, simple_nbr_width_x, .init = redirect_all_std)
{
    my_printf("%-4xP", 0x24322424);
    cr_assert_stdout_eq_str("24322424P");
}

Test(my_printf, simple_str_width_precision_s, .init = redirect_all_std)
{
    my_printf("%-28.2sP", "koko");
    cr_assert_stdout_eq_str("ko                          P");
}

Test(my_printf, simple_str_width_precision_high_s, .init = redirect_all_std)
{
    my_printf("%-28.9sP", "koko");
    cr_assert_stdout_eq_str("koko                        P");
}