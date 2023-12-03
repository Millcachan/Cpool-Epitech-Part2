/*
** EPITECH PROJECT, 2023
** B-CPE-100-STG-1-1-cpoolday08-lois.hattenberger
** File description:
** my_strdup
*/

#include "../../include/flag.h"

char *my_strdup(char *str)
{
    char *dup = malloc(sizeof(char) * my_strlen(str) + 1);

    dup = my_strcpy(dup, str);
    return dup;
}
