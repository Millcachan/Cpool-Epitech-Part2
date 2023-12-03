/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** my_putchar
*/

#include <unistd.h>

int my_putchar(char c)
{
    return write(1, &c, 1);
}
