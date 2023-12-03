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

Test(my_printf, print_flag_e, .init = redirect_all_std)
{
    my_printf("%e", 123470.1030);
    cr_assert_stdout_eq_str("1.234701e+05");
}

Test(my_printf2, print_flag_e2, .init = redirect_all_std)
{
    double i = 3;

    my_printf("%e", i);
    cr_assert_stdout_eq_str("3.000000e+00");
}

Test(my_printf3, print_flag_e_inf, .init = redirect_all_std)
{
    my_printf("%e", 1.0 / 0.0);
    cr_assert_stdout_eq_str("inf");
}

Test(my_printf4, print_flag_e_inf, .init = redirect_all_std)
{
    my_printf("%e", -1.0 / 0.0);
    cr_assert_stdout_eq_str("-inf");
}

Test(my_printf5, print_flag_e_inf, .init = redirect_all_std)
{
    my_printf("%e", 0.0 / 0.0);
    cr_assert_stdout_eq_str("-nan");
}

Test(my_printf6, print_flag_e_inf, .init = redirect_all_std)
{
    my_printf("%e", 0.0);
    cr_assert_stdout_eq_str("0.000000e+00");
}

