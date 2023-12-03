/*
** EPITECH PROJECT, 2023
** rush3.c
** File description:
** rush3
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int num)
{
    if (num < 0) {
        my_putchar('-');
        num = -num;
    }
    if (num >= 10)
        my_put_nbr(num / 10);
    my_putchar('0' + num % 10);
}

int my_strlen(char *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++);
    return i;
}

void my_put_str(char *str)
{
    write(1, str, my_strlen(str));
}

static int get_length(char *square)
{
    int length = 0;

    for (int i = 0; square[i] != '\n'; i++)
        length++;
    return length;
}

static int get_height(char *square)
{
    int height = 0;
    int length = get_length(square);

    for (height; square[height] != '\0' ; height++);
    if (length == 1)
        return height / 2;
    height = ((height - 1) / length);
    return height;
}

static int get_assignement(char *square)
{
    int height = get_height(square);
    int length = get_length(square);

    if (square[0] == 'o')
        return 1;
    if (square[0] == '/' || square[0] == '*')
        return 2;
    if (square[length - 1] == 'A')
        return 3;
    if (square[(length * height) + height - 2] == 'C')
        return 4;
    if (square[(length * height) + height - 2] == 'A')
        return 5;
    return 0;
}

static void size_one(int height, int length)
{
    my_put_str("[rush1-3] ");
    my_put_nbr(length);
    my_putchar(' ');
    my_put_nbr(height);
    my_put_str(" || [rush1-4] ");
    my_put_nbr(length);
    my_putchar(' ');
    my_put_nbr(height);
    my_put_str(" || [rush1-5] ");
    my_put_nbr(length);
    my_putchar(' ');
    my_put_nbr(height);
    my_putchar('\n');
}

static void rush3(char *square)
{
    int height = get_height(square);
    int length = get_length(square);
    int assignement = get_assignement(square);

    if ((length == 1 || height == 1) && assignement == 0) {
        size_one(height, length);
        return;
    }
    if (assignement == 0) {
        my_put_str("none\n");
        return;
    }
    my_put_str("[rush1-");
    my_put_nbr(assignement);
    my_put_str("] ");
    my_put_nbr(length);
    my_putchar(' ');
    my_put_nbr(height);
    my_putchar('\n');
}

int main(void)
{
    char buf[32000];
    int off = 0;
    int len = 1;
    char error;

    while (len > 0) {
        len = read(0, buf + off, sizeof(buf) - off);
        off += len;
    }
    if (buf[0] == '\0')
        return 84;
    buf[off] = '\0';
    rush3(buf);
    return 0;
}
