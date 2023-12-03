/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_p
*/

#include "../../include/flag.h"

void put_p_hexa(unsigned long long ptr, int *count)
{
    unsigned long long mod = 0;
    const char hexa[] = "0123456789abcdef";

    if (ptr >= 0) {
        if (ptr >= 16){
            mod = (ptr % 16);
            ptr = (ptr - mod) / 16;
            put_p_hexa(ptr, count);
            my_putchar(hexa[mod]);
        } else
            my_putchar(hexa[ptr % 16]);
        *count = *count + 1;
    }
}

int flag_p(va_list list, struct sub_flags *sub_flags)
{
    unsigned long long ptr = va_arg(list, unsigned long long);
    int count = 0;

    my_putstr("0x", &count);
    put_p_hexa(ptr, &count);
    return count;
}
