/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** my_get_nbr
*/

#include "../../include/flag.h"

void my_put_nbr(long long nb, int *count)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        *count = *count + 1;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10, count);
    my_putchar('0' + nb % 10);
    *count = *count + 1;
}
