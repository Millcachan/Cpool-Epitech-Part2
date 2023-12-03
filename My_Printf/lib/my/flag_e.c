/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_e
*/

#include "../../include/flag.h"

void sub_flag_e(struct sub_flags *sub_flags, int *count, double nb)
{
    if (sub_flags->spaces > sub_flags->zeros_left) {
        for (int i = 0; i < (sub_flags->spaces - sub_flags->sign - 12); i++)
            count += my_putchar(' ');
        if (sub_flags->sign == 1 && nb > 0)
        count += my_putchar('+');
    } else {
        if (sub_flags->spaces == 1 && sub_flags->sign == 0)
            count += my_putchar(' ');
        if (sub_flags->sign == 1 && nb > 0)
            count += my_putchar('+');
        for (int i = 0; i < (sub_flags->zeros_left - 12); i++)
            count += my_putchar('0');
    }
}

void put_e(int e, int *count)
{
    int counter = 0;

    if (e < 10 && e >= 0) {
        *count += my_putchar('+');
        my_put_nbr(0, &counter);
        my_put_nbr(e, &counter);
    }
    if (e > -10 && e < 0) {
        *count += my_putchar('-');
        my_put_nbr(0, &counter);
        my_put_nbr(-e, &counter);
    }
    if (e >= 10) {
        *count += my_putchar('+');
        my_put_nbr(e, &counter);
    }
    if (e <= -10)
        my_put_nbr(e, &counter);
    *count += counter;
}

static int choice_neg(double *nb)
{
    int e = 0;

    if (*nb == 0.)
        return 0;
    for (e; *nb < -10; e++)
        *nb = *nb / 10;
    for (e; *nb > -1; e--)
        *nb = *nb * 10;
    return e;
}

static int choice_pos(double *nb)
{
    int e = 0;

    if (*nb == 0.)
        return 0;
    for (e; *nb > 10; e++)
        *nb = *nb / 10;
    for (e; *nb < 1; e--)
        *nb = *nb * 10;
    return e;
}

int flag_e(va_list list, struct sub_flags *sub_flags)
{
    int e = 0;
    int count = 0;
    double nb = va_arg(list, double);
    double test_inf = 1.0 / 0.0;

    sub_flag_e(sub_flags, &count, nb);
    if (tests(nb, &count) == 1)
        return count;
    else if (nb < 0)
        e = choice_neg(&nb);
    else
        e = choice_pos(&nb);
    put_float(nb, &count);
    count += my_putchar('e');
    put_e(e, &count);
    return count;
}

int flag_le(va_list list, struct sub_flags *sub_flags)
{
    int e = 0;
    int count = 0;
    double nb = va_arg(list, double);
    double test_inf = 1.0 / 0.0;

    sub_flag_e(sub_flags, &count, nb);
    if (tests(nb, &count) == 1)
        return count;
    else {
        for (e; nb > 10; e++)
            nb = nb / 10;
        for (e; nb < 1; e--)
            nb = nb * 10;
        put_float(nb, &count);
        count += my_putchar('e');
        put_e(e, &count);
    }
    return count;
}
