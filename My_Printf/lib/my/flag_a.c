/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_a
*/

#include "../../include/flag.h"

void put_a_hexa(long long nb, int *count)
{
    int mod = 0;
    const char hexa[] = "0123456789abcdef";

    if (nb >= 0) {
        if (nb >= 16){
            mod = (nb % 16);
            nb = (nb - mod) / 16;
            put_hexa(nb, count);
            my_putchar(hexa[mod]);
        } else
            my_putchar(hexa[nb % 16]);
        *count = *count + 1;
    } else
        put_hexa(2147483648 + nb, count);
}

int put_a_float(double nb, int *count)
{
    int integer = nb * 1000000;
    int decimal = integer % 1000000;

    my_put_nbr(integer / 1000000, count);
    *count = *count + my_putchar('.');
    if (decimal == 0)
        my_putstr("00000", count);
    for (int i = 0; decimal < 100000 && decimal != 0; i++) {
        decimal = decimal * 10;
        *count = *count + my_putchar('0');
    }
    my_put_nbr(integer % 1000000, count);
}

int flag_a(va_list list, struct sub_flags *sub_flags)
{
    double nb = va_arg(list, double);
    int count = 0;

    put_a_float(nb, &count);
    return count;
}
