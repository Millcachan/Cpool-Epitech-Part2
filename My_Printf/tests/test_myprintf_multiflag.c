/*
** EPITECH PROJECT, 2023
** ù
** File description:
** test_myprintf_multiflag
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/flag.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, print_flag_p, .init = redirect_all_std)
{
    int i = 8;
    char *str = strdup("Hello");

    my_printf("%d %s", i, str);
    cr_assert_stdout_eq_str("8 Hello");
}

Test(my_printf2, print_flag_p, .init = redirect_all_std)
{
    int i = 8;
    char *str = strdup("Hello");

    my_printf("%d %s %x", i, str, 123);
    cr_assert_stdout_eq_str("8 Hello 7b");
}

Test(my_printf3, print_flag_p, .init = redirect_all_std)
{
    int i = 8;
    char *str = strdup("Hello");

    my_printf("%x %X %g %G", 123, 123, 1.110, 1.0 / 0.0);
    cr_assert_stdout_eq_str("7b 7B 1.11 INF");
}
