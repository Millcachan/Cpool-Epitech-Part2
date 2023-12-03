/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-camille.billard
** File description:
** flag
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>

#ifndef FLAG_H_
    #define FLAG_H_

struct sub_flags {
    int spaces;
    int hashtag;
    int zeros_left;
    int zeros_right;
    int sign;
};

struct flag_function {
    char flag;
    int (*function)(va_list, struct sub_flags *);
};

struct flag2_function {
    char *flag2;
    int (*function)(va_list, struct sub_flags *);
};

struct flag3_function {
    char *flag3;
    int (*function)(va_list, struct sub_flags *);
};

int my_putchar(char c);
int my_getnbr(char *str);
int my_strlen(char *str);
char *my_strdup(char *str);
int my_printf(char *s, ...);
void put_e(int e, int *count);
char *int_to_str(long long nb);
void my_put_b(long nb, int *count);
int tests_up(double nb, int *count);
int flag_n(va_list list, int *count);
int tests(long double nb, int *count);
void my_putstr(char *str, int *count);
int put_float_g(double nb, int *count);
char *my_strcpy(char *dest, char *src);
void put_hexa(long long nb, int *count);
void put_float(long double nb, int *count);
void my_put_nbr(long long nb, int *count);
void put_up_hexa(long long nb, int *count);
void my_put_o(unsigned long long nb, int *count);
int my_strncmp(char const *s1, char const *s2, int n);
int flag_e(va_list list, struct sub_flags *sub_flags);
int flag_o(va_list list, struct sub_flags *sub_flags);
int flag_x(va_list list, struct sub_flags *sub_flags);
int flag_c(va_list list, struct sub_flags *sub_flags);
int flag_s(va_list list, struct sub_flags *sub_flags);
int flag_u(va_list list, struct sub_flags *sub_flags);
int flag_d(va_list list, struct sub_flags *sub_flags);
int flag_f(va_list list, struct sub_flags *sub_flags);
int flag_p(va_list list, struct sub_flags *sub_flags);
int flag_a(va_list list, struct sub_flags *sub_flags);
int flag_b(va_list list, struct sub_flags *sub_flags);
int flag_g(va_list list, struct sub_flags *sub_flags);
int flag_lf(va_list list, struct sub_flags *sub_flags);
int flag_lu(va_list list, struct sub_flags *sub_flags);
int flag_lo(va_list list, struct sub_flags *sub_flags);
int flag_lx(va_list list, struct sub_flags *sub_flags);
int flag_ld(va_list list, struct sub_flags *sub_flags);
int flag_le(va_list list, struct sub_flags *sub_flags);
int flag_lg(va_list list, struct sub_flags *sub_flags);
int flag_llu(va_list list, struct sub_flags *sub_flags);
int flag_llo(va_list list, struct sub_flags *sub_flags);
int flag_llx(va_list list, struct sub_flags *sub_flags);
int flag_lld(va_list list, struct sub_flags *sub_flags);
int flag_llf(va_list list, struct sub_flags *sub_flags);
int flag_up_e(va_list list, struct sub_flags *sub_flags);
int flag_up_f(va_list list, struct sub_flags *sub_flags);
int flag_up_x(va_list list, struct sub_flags *sub_flags);
int flag_up_g(va_list list, struct sub_flags *sub_flags);
int flag_up_lf(va_list list, struct sub_flags *sub_flags);
int flag_up_lx(va_list list, struct sub_flags *sub_flags);
int flag_up_le(va_list list, struct sub_flags *sub_flags);
int flag_up_lg(va_list list, struct sub_flags *sub_flags);
int flag_up_llx(va_list list, struct sub_flags *sub_flags);
int flag_up_llf(va_list list, struct sub_flags *sub_flags);
int flag_percent(va_list list, struct sub_flags *sub_flags);
int sub_flag(char *s, int *count, struct sub_flags *sub_flags);
void sub_flag_g(struct sub_flags *sub_flags, int *count, double nb);
void sub_flag_e(struct sub_flags *sub_flags, int *count, double nb);
void sub_flag_f(struct sub_flags *sub_flags, int *count, double nb);
int get_func(char *s, va_list list, int *index, struct sub_flags *sub_flags);

static const struct flag_function flag_func[] = {
    {'c', flag_c},
    {'d', flag_d},
    {'s', flag_s},
    {'i', flag_d},
    {'u', flag_u},
    {'o', flag_o},
    {'p', flag_p},
    {'x', flag_x},
    {'f', flag_f},
    {'b', flag_b},
    {'g', flag_g},
    {'e', flag_e},
    {'G', flag_up_g},
    {'X', flag_up_x},
    {'F', flag_up_f},
    {'E', flag_up_e},
    {'%', flag_percent},
    {'\0', NULL}
};

static const struct flag2_function flag2_func[] = {
    {"lf", flag_lf},
    {"le", flag_le},
    {"lg", flag_lg},
    {"lu", flag_lu},
    {"lo", flag_lo},
    {"lx", flag_lx},
    {"ld", flag_ld},
    {"li", flag_ld},
    {"lF", flag_up_lf},
    {"lX", flag_up_lx},
    {"l%", flag_percent},
    {NULL, NULL}
};

static const struct flag3_function flag3_func[] = {
    {"llf", flag_llf},
    {"lle", flag_llf},
    {"llg", flag_llf},
    {"llu", flag_llu},
    {"llo", flag_llo},
    {"llx", flag_llx},
    {"lld", flag_lld},
    {"lli", flag_lld},
    {"llF", flag_up_llf},
    {"llE", flag_up_llf},
    {"llG", flag_up_llf},
    {"llX", flag_up_llx},
    {"ll%", flag_percent},
    {NULL, NULL}
};

#endif /* !FLAG_H_ */
