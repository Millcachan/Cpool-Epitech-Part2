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

Test(my_printf, printf_flag_x, .init = redirect_all_std)
{
    my_printf("%x", 1);
    cr_assert_stdout_eq_str("1");
}

Test(my_printf2, printf_flag_x, .init = redirect_all_std)
{
    my_printf("%x", 12);
    cr_assert_stdout_eq_str("c");
}

Test(my_printf3, printf_flag_up_x, .init = redirect_all_std)
{
    my_printf("%X", 12);
    cr_assert_stdout_eq_str("C");
}

Test(my_printf4, printf_flag_x, .init = redirect_all_std)
{
    my_printf("%x", 123);
    cr_assert_stdout_eq_str("7b");
}

Test(my_printf5, printf_flag_x, .init = redirect_all_std)
{
    my_printf("%X", 123);
    cr_assert_stdout_eq_str("7B");
}

Test(my_printf6, printf_flag_x, .init = redirect_all_std)
{
    my_printf("%x", 1234);
    cr_assert_stdout_eq_str("4d2");
}

Test(my_printf7, printf_flag_x, .init = redirect_all_std)
{
    my_printf("%X", 1234);
    cr_assert_stdout_eq_str("4D2");
}

Test(my_printf8, printf_flag_x, .init = redirect_all_std)
{
    my_printf("%x", 12345);
    cr_assert_stdout_eq_str("3039");
}

Test(my_printf9, printf_flag_x, .init = redirect_all_std)
{
    my_printf("%X", 12345);
    cr_assert_stdout_eq_str("3039");
}