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

Test(my_printf, print_flag_d, .init = redirect_all_std)
{
    my_printf("%d", 189);
    cr_assert_stdout_eq_str("189");
}

Test(my_printf2, print_flag_d, .init = redirect_all_std)
{
    my_printf("%d", 18978);
    cr_assert_stdout_eq_str("18978");
}

Test(my_printf3, print_flag_d, .init = redirect_all_std)
{
    my_printf("%d", -189);
    cr_assert_stdout_eq_str("-189");
}

Test(my_printf4, print_flag_d, .init = redirect_all_std)
{
    my_printf("%d", 0);
    cr_assert_stdout_eq_str("0");
}
