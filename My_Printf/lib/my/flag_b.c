/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_o
*/

#include "../../include/flag.h"

void my_put_b(long nb, int *count)
{
    if (nb > 2)
        my_put_b(nb / 2, count);
    if ((nb % 2) == 0)
        my_putchar('0');
    if ((nb % 2) == 1)
        my_putchar('1');
}

int flag_b(va_list list, struct sub_flags *sub_flags)
{
    long nb = va_arg(list, int);
    int count = 0;

    for (int i = 0; i < (sub_flags->spaces - sub_flags->hashtag); i++)
        count += my_putchar(' ');
    if (sub_flags->hashtag == 1)
        my_putstr("0b", &count);
    my_put_b(nb, &count);
    return count;
}
