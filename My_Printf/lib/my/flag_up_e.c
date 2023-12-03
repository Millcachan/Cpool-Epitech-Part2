/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_e
*/

#include "../../include/flag.h"

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

int flag_up_e(va_list list, struct sub_flags *sub_flags)
{
    int e = 0;
    int count = 0;
    double nb = va_arg(list, double);
    double test_inf = 1.0 / 0.0;

    sub_flag_e(sub_flags, &count, nb);
    if (tests_up(nb, &count) == 1)
        return count;
    else if (nb < 0)
        e = choice_neg(&nb);
    else
        e = choice_pos(&nb);
    put_float(nb, &count);
    count += my_putchar('E');
    put_e(e, &count);
    return count;
}

int flag_up_le(va_list list, struct sub_flags *sub_flags)
{
    int e = 0;
    int count = 0;
    double nb = va_arg(list, double);
    double test_inf = 1.0 / 0.0;

    sub_flag_e(sub_flags, &count, nb);
    if (tests_up(nb, &count) == 1)
        return count;
    else if (nb < 0)
        e = choice_neg(&nb);
    else
        e = choice_pos(&nb);
    put_float(nb, &count);
    count += my_putchar('E');
    put_e(e, &count);
    return count;
}
