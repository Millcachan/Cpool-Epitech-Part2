/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_o
*/

#include "../../include/flag.h"

void my_put_o(unsigned long long nb, int *count)
{
    int mod = 0;

    if (nb >= 0) {
        if (nb >= 8) {
            mod = (nb % 8);
            nb = (nb - mod) / 8;
            my_put_o(nb, count);
            my_putchar(48 + mod);
        } else
            my_putchar(48 + nb % 8);
        *count = *count + 1;
    }
}

void sub_flag_o(struct sub_flags *sub_flags, int *count, long long nb)
{
    if (sub_flags->spaces > sub_flags->zeros_left) {
        for (int i = 0; i < (sub_flags->spaces - sub_flags->hashtag -
        my_strlen(int_to_str(nb))); i++)
            count += my_putchar(' ');
    } else {
        for (int i = 0; i < (sub_flags->zeros_left + 1 - sub_flags->hashtag -
        my_strlen(int_to_str(nb))); i++)
            count += my_putchar('0');
    }
    if (sub_flags->hashtag == 1)
        count += my_putchar('0');
}

int flag_o(va_list list, struct sub_flags *sub_flags)
{
    unsigned int nb = va_arg(list, unsigned int);
    int count = 0;

    if (nb == 0) {
        my_putchar('0');
        return 1;
    }
    sub_flag_o(sub_flags, &count, nb);
    my_put_o(nb, &count);
    return count;
}

int flag_lo(va_list list, struct sub_flags *sub_flags)
{
    unsigned long nb = va_arg(list, unsigned long);
    int count = 0;

    sub_flag_o(sub_flags, &count, nb);
    my_put_o(nb, &count);
    return count;
}

int flag_llo(va_list list, struct sub_flags *sub_flags)
{
    unsigned long long nb = va_arg(list, unsigned long long);
    int count = 0;

    sub_flag_o(sub_flags, &count, nb);
    my_put_o(nb, &count);
    return count;
}
