/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_f
*/

#include "../../include/flag.h"

int tests_up(double nb, int *count)
{
    double test_inf = 1.0 / 0.0;
    double test_inf_neg = -1.0 / 0.0;
    int result = 0;

    if (nb != nb) {
        result = 1;
        if (nb > 0)
            my_putstr("NAN", count);
        else
            my_putstr("-NAN", count);
    }
    if (nb == test_inf || nb == test_inf_neg) {
        result = 1;
        if (nb > 0)
            my_putstr("INF", count);
        else
            my_putstr("-INF", count);
    }
    return result;
}

void sub_flag_f(struct sub_flags *sub_flags, int *count, double nb)
{
    if (sub_flags->spaces > sub_flags->zeros_left) {
        for (int i = 0; i < (sub_flags->spaces - sub_flags->sign -
        my_strlen(int_to_str((int)nb)) - 7); i++)
            count += my_putchar(' ');
        if (sub_flags->sign == 1 && nb > 0)
        count += my_putchar('+');
    } else {
        if (sub_flags->spaces == 1 && sub_flags->sign == 0)
            count += my_putchar(' ');
        if (sub_flags->sign == 1 && nb > 0)
            count += my_putchar('+');
        for (int i = 0; i < (sub_flags->zeros_left -
        my_strlen(int_to_str((int)nb)) - 7); i++)
            count += my_putchar('0');
    }
}

int flag_up_f(va_list list, struct sub_flags *sub_flags)
{
    float nb = va_arg(list, double);
    double test_inf = 1.0 / 0.0;
    int count = 0;

    sub_flag_f(sub_flags, &count, nb);
    if (tests_up(nb, &count) == 1)
        return count;
    else
        put_float(nb, &count);
    return count;
}

int flag_up_lf(va_list list, struct sub_flags *sub_flags)
{
    double nb = va_arg(list, double);
    double test_inf = 1.0 / 0.0;
    int count = 0;

    sub_flag_f(sub_flags, &count, nb);
    if (tests_up(nb, &count) == 1)
        return count;
    else
        put_float(nb, &count);
    return count;
}

int flag_up_llf(va_list list, struct sub_flags *sub_flags)
{
    int count = 0;
    void *arg = va_arg(list, void *);

    for (int i = 0; i < (sub_flags->spaces - 3); i++)
        count += my_putchar(' ');
    my_putstr("nan", &count);
    return count;
}
