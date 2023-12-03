/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** int_to_str
*/

#include "../../include/flag.h"

char *int_to_str2(int i, int position, char *str, int *digits)
{
    for (i; i >= 0; i--) {
        str[position] = (digits[i] + '0');
        position ++;
    }
    str[position] = '\0';
    return str;
}

char *int_to_str(long long nb)
{
    int i = 0;
    int ndigits = 0;
    int position = 0;
    int digits[100];
    char *str = malloc(sizeof(char) * 500);

    if (nb == 0)
        return "0";
    if (nb < 0) {
        nb = -nb;
    }
    for (i; nb != 0; i++) {
        digits[i] = nb % 10;
        nb = nb / 10;
    }
    ndigits = i;
    i--;
    return int_to_str2(i, position, str, digits);
}
