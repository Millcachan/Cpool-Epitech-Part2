/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "../../include/flag.h"

void sub_flag_d(struct sub_flags *sub_flags, int *count, long long nb)
{
    if (sub_flags->spaces > sub_flags->zeros_left) {
        for (int i = 0; i < (sub_flags->spaces - sub_flags->sign -
        my_strlen(int_to_str(nb))); i++)
            count += my_putchar(' ');
        if (sub_flags->sign == 1 && nb > 0)
        count += my_putchar('+');
    } else {
        if (sub_flags->spaces == 1 && sub_flags->sign == 0)
            count += my_putchar(' ');
        if (sub_flags->sign == 1 && nb > 0)
            count += my_putchar('+');
        for (int i = 0; i < (sub_flags->zeros_left -
        my_strlen(int_to_str(nb))); i++)
            count += my_putchar('0');
    }
}

int flag_d(va_list list, struct sub_flags *sub_flags)
{
    int nb = va_arg(list, int);
    int count = 0;

    if (nb == 0) {
        my_putchar('0');
        return 1;
    }
    sub_flag_d(sub_flags, &count, nb);
    my_put_nbr(nb, &count);
    return count;
}

int flag_ld(va_list list, struct sub_flags *sub_flags)
{
    long nb = va_arg(list, long);
    int count = 0;

    sub_flag_d(sub_flags, &count, nb);
    my_put_nbr(nb, &count);
    return count;
}

int flag_lld(va_list list, struct sub_flags *sub_flags)
{
    long long nb = va_arg(list, long long);
    int count = 0;

    sub_flag_d(sub_flags, &count, nb);
    my_put_nbr(nb, &count);
    return count;
}
