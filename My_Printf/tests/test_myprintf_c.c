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

Test(my_printf, print_flag_c, .init = redirect_all_std)
{
    my_printf("%c", 'c');
    cr_assert_stdout_eq_str("c");
}

Test(my_printf2, print_flag_c, .init = redirect_all_std)
{
    my_printf("%c", 'a');
    cr_assert_stdout_eq_str("a");
}

Test(my_printf3, print_flag_c, .init = redirect_all_std)
{
    my_printf("%c", 'z');
    cr_assert_stdout_eq_str("z");
}

Test(my_printf4, print_flag_c, .init = redirect_all_std)
{
    my_printf("%c", 'C');
    cr_assert_stdout_eq_str("C");
}
