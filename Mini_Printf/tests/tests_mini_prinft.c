/*
** EPITECH PROJECT, 2023
** tests_mini_prinft.c
** File description:
** testsminiprintf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(mini_printf, simple_string, .init = redirect_all_std)
{
    mini_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(mini_printf, unknown_flag, .init = redirect_all_std)
{
    mini_printf("hello world %v");
    cr_assert_stdout_eq_str("hello world %v");
}

Test(mini_printf, flag_d_s_i_c, .init = redirect_all_std)
{
    mini_printf("%d %c %s %i", 69, 'H', "hello", -69);
    cr_assert_stdout_eq_str("69 H hello -69");
}

Test(mini_printf, string_null, .init = redirect_all_std)
{
    mini_printf("hello world %s", NULL);
    cr_assert_stdout_eq_str("hello world (null)");
}

Test(mini_printf, print_percent, .init = redirect_all_std)
{
    mini_printf("hello %s world %%%%", "test");
    cr_assert_stdout_eq_str("hello test world %%");
}
