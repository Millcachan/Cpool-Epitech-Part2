/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_c
*/

#include "../../include/flag.h"

int flag_c(va_list list, struct sub_flags *sub_flags)
{
    int count = 1;
    char c = va_arg(list, int);

    if (sub_flags->spaces > sub_flags->zeros_left) {
        for (int i = 0; i < (sub_flags->spaces - 1); i++)
            count += my_putchar(' ');
    } else {
        for (int i = 0; i < (sub_flags->zeros_left - 1 + 1); i++)
            count += my_putchar(' ');
    }
    write(1, &c, 1);
    return count;
}
