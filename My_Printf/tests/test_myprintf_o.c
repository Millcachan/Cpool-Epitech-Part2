/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** test_myprintf_o
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/flag.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, print_flag_o, .init = redirect_all_std)
{
    my_printf("%o", 49);
    cr_assert_stdout_eq_str("61");
}

Test(my_printf2, print_flag_o, .init = redirect_all_std)
{
    my_printf("%o", 1);
    cr_assert_stdout_eq_str("1");
}

Test(my_printf3, print_flag_o, .init = redirect_all_std)
{
    my_printf("%o", 132);
    cr_assert_stdout_eq_str("204");
}

Test(my_printf4, print_flag_o, .init = redirect_all_std)
{
    my_printf("%o", 1677864);
    cr_assert_stdout_eq_str("6315050");
}

Test(my_printf5, print_flag_o, .init = redirect_all_std)
{
    my_printf("%o", 0);
    cr_assert_stdout_eq_str("0");
}