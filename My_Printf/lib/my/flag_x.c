/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_x
*/

#include "../../include/flag.h"

void put_hexa(long long nb, int *count)
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
    }
}

void sub_flag_x(struct sub_flags *sub_flags, int *count, double nb)
{
    if (sub_flags->spaces > sub_flags->zeros_left) {
        for (int i = 0; i < (sub_flags->spaces + 1 -
        (sub_flags->hashtag * 2) - my_strlen(int_to_str(nb))); i++)
            count += my_putchar(' ');
        if (sub_flags->hashtag == 1)
            my_putstr("0x", count);
    } else {
    if (sub_flags->hashtag == 1)
        my_putstr("0x", count);
    for (int i = 0; i < (sub_flags->zeros_left + 1 -
    (sub_flags->hashtag * 2) - my_strlen(int_to_str(nb))); i++)
        count += my_putchar('0');
    }
}

int flag_x(va_list list, struct sub_flags *sub_flags)
{
    int count = 0;
    unsigned int nb = va_arg(list, unsigned int);

    sub_flag_x(sub_flags, &count, nb);
    put_hexa(nb, &count);
    return count;
}

int flag_lx(va_list list, struct sub_flags *sub_flags)
{
    int count = 0;
    unsigned long nb = va_arg(list, unsigned long);

    sub_flag_x(sub_flags, &count, nb);
    put_hexa(nb, &count);
    return count;
}

int flag_llx(va_list list, struct sub_flags *sub_flags)
{
    int count = 0;
    unsigned long long nb = va_arg(list, unsigned long long);

    sub_flag_x(sub_flags, &count, nb);
    put_hexa(nb, &count);
    return count;
}
