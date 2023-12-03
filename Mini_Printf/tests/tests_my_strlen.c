/*
** EPITECH PROJECT, 2023
** tests_my_strlen.c
** File description:
** testsmystrlen
*/

#include <criterion/criterion.h>

char *my_strlen(char *str);

Test(test_my_strlen, test_len_str)
{
    char *str = strdup("World");
    
    cr_assert_eq(my_strlen(str), 5);
}
