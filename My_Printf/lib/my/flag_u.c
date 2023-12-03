/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_u
*/

#include "../../include/flag.h"

void sub_flag_u(struct sub_flags *sub_flags, int *count, unsigned long long nb)
{
    if (sub_flags->spaces > sub_flags->zeros_left) {
        for (int i = 0; i < (sub_flags->spaces -
        my_strlen(int_to_str(nb))); i++)
            count += my_putchar(' ');
    } else {
        if (sub_flags->spaces == 1)
            count += my_putchar(' ');
        for (int i = 0; i < (sub_flags->zeros_left -
        my_strlen(int_to_str(nb))); i++)
            count += my_putchar('0');
    }
}

int flag_u(va_list list, struct sub_flags *sub_flags)
{
    unsigned int nb = va_arg(list, unsigned int);
    int count = 0;

    sub_flag_u(sub_flags, &count, nb);
    my_put_nbr(nb, &count);
    return count;
}

int flag_lu(va_list list, struct sub_flags *sub_flags)
{
    unsigned long nb = va_arg(list, unsigned long);
    int count = 0;

    sub_flag_u(sub_flags, &count, nb);
    my_put_nbr(nb, &count);
    return count;
}

int flag_llu(va_list list, struct sub_flags *sub_flags)
{
    unsigned long long nb = va_arg(list, unsigned long long);
    int count = 0;

    sub_flag_u(sub_flags, &count, nb);
    my_put_nbr(nb, &count);
    return count;
}
