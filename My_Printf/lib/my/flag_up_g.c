/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_g
*/

#include "../../include/flag.h"

static char *erase_zero(char *str)
{
    int i = my_strlen(str);

    while (i > 0 && str[i - 1] == '0') {
        str[i - 1] = '\0';
        i--;
    }
    return str;
}

static void display_n_char(char *str, int i, int count, int decimal)
{
    int lim = 6;

    if (i > lim)
        return;
    if (i < lim)
        my_putchar('.');
    i = lim - i;
    for (int n = 0; n < i && str[n] != '\0'; n++)
            my_putchar(str[n]);
}

static int choice_neg(double *nb)
{
    int e = 0;
    int test = 0;

    if (*nb == 0.)
        return 0;
    for (e; *nb < -10; e++)
        *nb = *nb / 10;
    for (e; *nb > -1; e--)
        *nb = *nb * 10;
    test = e;
    for (e; e > 0; e--)
        *nb = *nb * 10;
    for (e; e < 0; e++)
        *nb = *nb / 10;
    return test;
}

static int choice_pos(double *nb)
{
    int e = 0;
    int test = 0;

    if (*nb == 0.)
        return 0;
    for (e; *nb > 10; e++)
        *nb = *nb / 10;
    for (e; *nb < 1; e--)
        *nb = *nb * 10;
    test = e;
    for (e; e > 0; e--)
        *nb = *nb * 10;
    for (e; e < 0; e++)
        *nb = *nb / 10;
    return test;
}

static double reset(double nb, int e)
{
    if (nb < 0) {
        for (e; e > 0; e--)
            nb = nb / 10;
        for (e; e < 0; e++)
            nb = nb * 10;
    } else {
        for (e; e > 0; e--)
            nb = nb / 10;
        for (e; e < 0; e++)
            nb = nb * 10;
    }
    return nb;
}

static void put_up_g_e(double nb, int *count,
    struct sub_flags *sub_flags, int e)
{
    sub_flag_g(sub_flags, count, nb);
    put_float_g(reset(nb, e), count);
    count += my_putchar('e');
    put_e(e, count);
}

int flag_up_g(va_list list, struct sub_flags *sub_flags)
{
    double nb = va_arg(list, double);
    int count = 0;
    int e = 0;

    if (tests_up(nb, &count) == 1)
        return count;
    if (nb < 0)
        e = choice_neg(&nb);
    else
        e = choice_pos(&nb);
    if (e <= -5 || e >= 6) {
        put_up_g_e(nb, &count, sub_flags, e);
        return count;
    }
    put_float_g(nb, &count);
    return count;
}

int flag_up_lg(va_list list, struct sub_flags *sub_flags)
{
    double nb = va_arg(list, double);
    int count = 0;
    int e = 0;

    if (tests_up(nb, &count) == 1)
        return count;
    if (nb > 0)
        e = choice_neg(&nb);
    else
        e = choice_pos(&nb);
    if (e <= -5 || e >= 6) {
        put_up_g_e(nb, &count, sub_flags, e);
        return count;
    }
    put_float_g(nb, &count);
    return count;
}
