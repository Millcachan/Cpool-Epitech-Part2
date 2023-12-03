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

Test(my_printf, print_flag_s, .init = redirect_all_std)
{
    char *str = strdup("ouiiiiii");

    my_printf("%s", str);
    cr_assert_stdout_eq_str("ouiiiiii");
}

Test(my_printf2, printf_flag_s, .init = redirect_all_std)
{
    char *str = strdup("Aled");

    my_printf("%s", str);
    cr_assert_stdout_eq_str("Aled");
}
