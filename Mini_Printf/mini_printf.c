/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** miniprintf
*/

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

static int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

static void my_put_nbr(int nb, int *count)
{
    long temp = 0;

    if (nb < 0) {
        my_putchar('-');
        *count = *count + 1;
        temp = nb;
        temp = temp * -1;
    } else {
        temp = nb;
    }
    if (temp > 9) {
        my_put_nbr(temp / 10, count);
    }
    my_putchar(temp % 10 + 48);
    *count = *count + 1;
}

static int flag_c(va_list list)
{
    char c = va_arg(list, int);

    write(1, &c, 1);
    return (1);
}

static int flag_d_i(va_list list)
{
    int nb = va_arg(list, int);
    int count = 0;

    my_put_nbr(nb, &count);
    return (count);
}

static int flag_s(va_list list)
{
    char *str = va_arg(list, char *);
    int len = 0;

    if (str == NULL)
        str = "(null)";
    while (str[len] != '\0') {
        write(1, &str[len], 1);
        len++;
    }
    return (len);
}

static int flag_unknown(va_list list, char c)
{
    my_putchar('%');
    my_putchar(c);
    return (2);
}

int *get_function(char c)
{
    char flag[4] = {'c', 'd', 's', 'i'};
    int (*functions[4])(va_list) = {&flag_c, &flag_d_i, &flag_s, &flag_d_i};

    for (int j = 0; j < 4; j++) {
        if (c != flag[j])
            continue;
        return functions[j];
    }
    return (&flag_unknown);
}

int mini_printf(char *s, ...)
{
    int count = 0;
    va_list list;
    int (*function)(va_list);

    va_start(list, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%' && s[i + 1] != '%') {
            function = get_function(s[i + 1]);
            count += function(list);
            i++;
            continue;
        }
        if (s[i] == '%' && s[i + 1] == '%')
            i++;
        count++;
        my_putchar(s[i]);
    }
    va_end(list);
    return (count);
}

int main(void)
{
    return mini_printf("ceci est %d %s\n", 1, "test");
}
