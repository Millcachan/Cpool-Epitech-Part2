/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_x
*/

#include "../../include/flag.h"

void put_up_hexa(long long nb, int *count)
{
    int mod = 0;
    const char hexa[] = "0123456789ABCDEF";

    if (nb >= 0) {
        if (nb >= 16){
            mod = (nb % 16);
            nb = (nb - mod) / 16;
            put_up_hexa(nb, count);
            my_putchar(hexa[mod]);
        } else
            my_putchar(hexa[nb % 16]);
        *count = *count + 1;
    } else
        put_up_hexa(2147483648 + nb, count);
}

void sub_flag_up_x(struct sub_flags *sub_flags, int *count, double nb)
{
    if (sub_flags->spaces > sub_flags->zeros_left) {
        for (int i = 0; i < (sub_flags->spaces + 1 -
        (sub_flags->hashtag * 2) - my_strlen(int_to_str(nb))); i++)
            count += my_putchar(' ');
        if (sub_flags->hashtag == 1)
            my_putstr("0X", count);
    } else {
    if (sub_flags->hashtag == 1)
        my_putstr("0X", count);
        for (int i = 0; i < (sub_flags->zeros_left + 2 -
        (sub_flags->hashtag * 2) - my_strlen(int_to_str(nb))); i++)
            count += my_putchar('0');
    }
}

int flag_up_x(va_list list, struct sub_flags *sub_flags)
{
    int count = 0;
    long long nb = va_arg(list, long long);

    sub_flag_up_x(sub_flags, &count, nb);
    put_up_hexa(nb, &count);
    return count;
}

int flag_up_lx(va_list list, struct sub_flags *sub_flags)
{
    int count = 0;
    unsigned long nb = va_arg(list, unsigned long);

    sub_flag_up_x(sub_flags, &count, nb);
    put_up_hexa(nb, &count);
    return count;
}

int flag_up_llx(va_list list, struct sub_flags *sub_flags)
{
    int count = 0;
    unsigned long long nb = va_arg(list, unsigned long long);

    sub_flag_up_x(sub_flags, &count, nb);
    put_up_hexa(nb, &count);
    return count;
}
