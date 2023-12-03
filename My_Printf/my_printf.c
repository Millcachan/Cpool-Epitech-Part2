/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** myprintf
*/

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "include/flag.h"

int get_func(char *s, va_list list, int *index, struct sub_flags *sub_flags)
{
    for (int i = 0; flag3_func[i].flag3 != NULL; i++)
        if (my_strncmp(s, flag3_func[i].flag3, 3) == 0) {
            *index = *index + 2;
            return flag3_func[i].function(list, sub_flags);
        }
    for (int i = 0; flag2_func[i].flag2 != NULL; i++)
        if (my_strncmp(s, flag2_func[i].flag2, 2) == 0) {
            (*index)++;
            return flag2_func[i].function(list, sub_flags);
        }
    for (int i = 0; flag_func[i].flag != '\0'; i++)
        if (s[0] == flag_func[i].flag)
            return flag_func[i].function(list, sub_flags);
    my_putchar('%');
    my_putchar(s[0]);
    return 2;
}

int my_printf(char *s, ...)
{
    int count = 0;
    va_list list;
    struct sub_flags sub_flags;

    va_start(list, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%' && s[i + 1] != 'n' && s[i + 1] != '\0') {
            i += sub_flag(&s[i + 1], &count, &sub_flags);
            count += get_func(&s[++i], list, &i, &sub_flags);
            continue;
        }
        if (s[i] == '%' && s[i + 1] == 'n' && s[i + 1] != '\0') {
            flag_n(list, &count);
            i++;
            continue;
        }
        count += my_putchar(s[i]);
    }
    va_end(list);
    return count;
}
