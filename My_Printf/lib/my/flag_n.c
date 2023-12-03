/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag_n
*/

#include "../../include/flag.h"

int flag_n(va_list list, int *count)
{
    int *stock = 0;

    stock = va_arg(list, int *);
    *stock = *count;
    return 0;
}
