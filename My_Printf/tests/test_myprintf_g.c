/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** test_myprintf_c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/flag.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, print_flag_g_inf, .init = redirect_all_std)
{
    my_printf("%g", 1.0 / 0.0);
    cr_assert_stdout_eq_str("inf");
}

Test(my_printf2, print_flag_g_min_inf, .init = redirect_all_std)
{
    my_printf("%g", -1.0 / 0.0);
    cr_assert_stdout_eq_str("-inf");
}

Test(my_printf3, print_flag_g, .init = redirect_all_std)
{
    my_printf("%g", 12345.7);
    cr_assert_stdout_eq_str("12345.7");
}

Test(my_printf800, print_flag_up_g, .init = redirect_all_std)
{
    my_printf("%G", 12345.7346);
    cr_assert_stdout_eq_str("12345.7");
}

Test(my_printf4, print_flag_g, .init = redirect_all_std)
{
    my_printf("%g", 1234.7346);
    cr_assert_stdout_eq_str("1234.73");
}

Test(my_printf5, print_flag_g, .init = redirect_all_std)
{
    my_printf("%g", 123.7346);
    cr_assert_stdout_eq_str("123.734");
}

Test(my_printf6, print_flag_g, .init = redirect_all_std)
{
    my_printf("%g", 12.7346);
    cr_assert_stdout_eq_str("12.7346");
}

Test(my_printf7, print_flag_g, .init = redirect_all_std)
{
    my_printf("%g", 1.7346);
    cr_assert_stdout_eq_str("1.7346");
}

Test(my_printf8, print_flag_g, .init = redirect_all_std)
{
    my_printf("%g", 1.73467);
    cr_assert_stdout_eq_str("1.73467");
}

Test(my_printf9, print_flag_g, .init = redirect_all_std)
{
    my_printf("%g", 111111.10000);
    cr_assert_stdout_eq_str("111111");
}

Test(my_printf10, print_flag_g, .init = redirect_all_std)
{
    my_printf("%g", 1.10000);
    cr_assert_stdout_eq_str("1.1");
}

Test(my_printf11, print_flag_g, .init = redirect_all_std)
{
    my_printf("%g", 177576463.7885);
    cr_assert_stdout_eq_str("1.77576e+08");
}

Test(my_printf12, printf_flag_up_g_inf, .init = redirect_all_std)
{
    my_printf("%G", 1.0 /0.0);
    cr_assert_stdout_eq_str("INF");
}

Test(my_printf13, printf_flag_up_g_inf_min, .init = redirect_all_std)
{
    my_printf("%G", -1.0 /0.0);
    cr_assert_stdout_eq_str("-INF");
}

Test(my_printf14, printf_flag_up_g_nan, .init = redirect_all_std)
{
    my_printf("%G", 0.0 /0.0);
    cr_assert_stdout_eq_str("-NAN");
}