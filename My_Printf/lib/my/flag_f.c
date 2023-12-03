/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_f
*/

#include "../../include/flag.h"

void put_float(long double nb, int *count)
{
    long long integer = nb * 1000000;
    long long decimal = integer % 1000000;

    if (nb == 0.0) {
        my_putstr("0.000000", count);
        return;
    }
    if (nb < 0 && (integer / 1000000) == 0)
        (*count) += my_putchar('-');
    my_put_nbr(integer / 1000000, count);
    (*count) += my_putchar('.');
    if (decimal == 0)
        my_putstr("00000", count);
    if (decimal > 0)
        my_put_nbr(decimal, count);
    else
        my_put_nbr(-decimal, count);
}

int tests(long double nb, int *count)
{
    double test_inf = 1.0 / 0.0;
    double test_inf_neg = -1.0 / 0.0;
    int result = 0;

    if (nb != nb) {
        result = 1;
        if (nb > 0)
            my_putstr("nan", count);
        else
            my_putstr("-nan", count);
    }
    if (nb == test_inf || nb == test_inf_neg) {
        result = 1;
        if (nb > 0)
            my_putstr("inf", count);
        else
            my_putstr("-inf", count);
    }
    return result;
}

int flag_f(va_list list, struct sub_flags *sub_flags)
{
    float nb = va_arg(list, double);
    int count = 0;

    sub_flag_f(sub_flags, &count, nb);
    if (tests(nb, &count) == 1)
        return count;
    else
        put_float(nb, &count);
    return count;
}

int flag_lf(va_list list, struct sub_flags *sub_flags)
{
    double nb = va_arg(list, double);
    int count = 0;

    for (int i = 0; i < (sub_flags->spaces - sub_flags->sign -
    my_strlen(int_to_str((int)nb)) - 7); i++)
        count += my_putchar(' ');
    if (sub_flags->sign == 1 && nb > 0) {
        count += my_putchar('+');
        sub_flags->sign = 0;
    }
    if (tests(nb, &count) == 1)
        return count;
    else
        put_float(nb, &count);
    return count;
}

int flag_llf(va_list list, struct sub_flags *sub_flags)
{
    int count = 0;
    void *arg = va_arg(list, void *);

    for (int i = 0; i < (sub_flags->spaces - 3); i++)
        count += my_putchar(' ');
    my_putstr("nan", &count);
    return count;
}
