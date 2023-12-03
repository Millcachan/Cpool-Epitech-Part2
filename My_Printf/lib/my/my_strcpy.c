/*
** EPITECH PROJECT, 2023
** B-CPE-100-STG-1-1-cpoolday06-lois.hattenberger
** File description:
** my_strcpy
*/

#include "../../include/flag.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    for (i; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i + '\0'] = '\0';
    return dest;
}
