/*
** EPITECH PROJECT, 2023
** tests
** File description:
** sub_flag_type
*/

#include "../../include/flag.h"

static void reset_struct(struct sub_flags *sub_flags)
{
    sub_flags->sign = 0;
    sub_flags->spaces = 0;
    sub_flags->hashtag = 0;
    sub_flags->zeros_left = 0;
    sub_flags->zeros_right = 0;
}

static int spaces(struct sub_flags *sub_flags, char *s, int *index)
{
    int i = 0;
    int count = 0;

    for (i; s[i] != '\0' && ((s[i] < '0' || s[i] > '9' && s[i] < 'A' ||
    s[i] > 'Z' && s[i] < 'a' || s[i] > 'z')); i++)
        if (s[i] == ' ') {
            count = 1;
            (*index)++;
        }
    if (s[i] == '0')
        return count;
    if (my_getnbr(&s[i]) != 0) {
        count = my_getnbr(&s[i]);
        (*index) += my_strlen(int_to_str(count));
    }
    return count;
}

static int zeros_left(struct sub_flags *sub_flags, char *s, int *index)
{
    int i = 0;
    int count = 0;

    for (i; s[i] != '\0' && ((s[i] < '0' || s[i] > '9' && s[i] < 'A' ||
    s[i] > 'Z' && s[i] < 'a' || s[i] > 'z')); i++);
    if (s[i] == '0') {
        (*index)++;
        if (my_getnbr(&s[i]) != 0) {
            count = my_getnbr(&s[i]);
            (*index) += my_strlen(int_to_str(count));
        }
    }
    return count;
}

static int hashtag(struct sub_flags *sub_flags, char *s, int *index)
{
    for (int i = 0; s[i] != '\0' && ((s[i] < 'A' ||
    s[i] > 'Z' && s[i] < 'a' || s[i] > 'z')); i++)
        if (s[i] == '#') {
            (*index)++;
            return 1;
        }
    return 0;
}

static int zeros_right(struct sub_flags *sub_flags, char *s, int *index)
{
    for (int i = 0; s[i] != '\0' && ((s[i] < 'A' ||
    s[i] > 'Z' && s[i] < 'a' || s[i] > 'z')); i++)
        if (s[i] == '-') {
            (*index)++;
        sub_flags->spaces = 0;
        sub_flags->zeros_left = 0;
            return 1;
        }
    return 0;
}

static int sign(struct sub_flags *sub_flags, char *s, int *index)
{
    for (int i = 0; s[i] != '\0' && ((s[i] < 'A' ||
    s[i] > 'Z' && s[i] < 'a' || s[i] > 'z')); i++)
        if (s[i] == '+') {
            (*index)++;
            return 1;
        }
    return 0;
}

int sub_flag(char *s, int *count, struct sub_flags *sub_flags)
{
    int index = 0;

    reset_struct(sub_flags);
    sub_flags->sign = sign(sub_flags, s, &index);
    sub_flags->spaces = spaces(sub_flags, s, &index);
    sub_flags->hashtag = hashtag(sub_flags, s, &index);
    sub_flags->zeros_left = zeros_left(sub_flags, s, &index);
    sub_flags->zeros_left = sub_flags->zeros_left - sub_flags->spaces;
    sub_flags->zeros_right = zeros_right(sub_flags, s, &index);
    return index;
}
