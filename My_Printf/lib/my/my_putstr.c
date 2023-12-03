/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** my_putstr
*/

#include "../../include/flag.h"

int my_strlen(char *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++);
    return i;
}

void my_putstr(char *str, int *count)
{
    *count = *count + write(1, str, my_strlen(str));
}
