/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** my_putstr
*/

#include "../../include/flag.h"

void sub_flag_s(struct sub_flags *sub_flags, int *count, char *str)
{
    if (sub_flags->spaces > sub_flags->zeros_left) {
        for (int i = 0; i < (sub_flags->spaces - my_strlen(str)); i++)
            count += my_putchar(' ');
    } else {
        for (int i = 0; i < (sub_flags->zeros_left - my_strlen(str) + 1); i++)
            count += my_putchar(' ');
    }
}

int flag_s(va_list list, struct sub_flags *sub_flags)
{
    char *str = va_arg(list, char *);
    int len = 0;
    int count = 0;

    if (str == NULL)
        str = "(null)";
    sub_flag_s(sub_flags, &count, str);
    while (str[len] != '\0') {
        write(1, &str[len], 1);
        len++;
    }
    return count + len;
}
