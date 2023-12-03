/*
** EPITECH PROJECT, 2023
** tests_my_strcpy.c
** File description:
** testsmystrcpy
*/

#include <criterion/criterion.h>

char *my_strcpy(char *dest, char const *src);

Test(test_my_strcpy, copy_five_characters_in_empty_array)
{
    char dest[6] = {0};

    my_strcpy(dest, "HelloWorld") ;
    cr_assert_str_eq(dest, "HelloWorld") ;
}
