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

Test(my_printf, print_flag_f, .init = redirect_all_std)
{
    my_printf("%f", 1.86);
    cr_assert_stdout_eq_str("1.860000");
}

Test (my_printf2, print_flag_f_inf, .init = redirect_all_std)
{
    my_printf("%f", 1.0/0.0);
    cr_assert_stdout_eq_str("inf");
}

Test (my_printf3, print_flag_f_min_inf, .init = redirect_all_std)
{
    my_printf("%f", -1.0 / 0.0);
    cr_assert_stdout_eq_str("-inf");
}

Test (my_printf4, print_flag_f, .init = redirect_all_std)
{
    my_printf("%f", 1.10101);
    cr_assert_stdout_eq_str("1.101009");
}

Test (my_printf5, print_flag_up_f_inf, .init = redirect_all_std)
{
    my_printf("%F", 1.0 / 0.0);
    cr_assert_stdout_eq_str("INF");
}

Test (my_printf6, print_flag_up_f_min_inf, .init = redirect_all_std)
{
    my_printf("%F", -1.0 / 0.0);
    cr_assert_stdout_eq_str("-INF");
}
