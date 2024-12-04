/*
** EPITECH PROJECT, 2024
** specifier functioins
** File description:
** Keep it simple
*/

#include "../include/my_hunter.h"

void print_d(va_list *d, mod_t *curr_mod, int *count)
{
    int x = va_arg(*d, int);

    my_putnbr(x);
    *count = *count + my_numlen(x);
}

void print_f(va_list *f, mod_t *curr_mod, int *count)
{
    double x = va_arg(*f, double);

    put_float(x, count);
}

void print_perc(int *count)
{
    my_putchar('%');
    (*count) = (*count) + 1;
}

void print_c(va_list *c, mod_t *curr_mod, int *count)
{
    char x = va_arg(*c, int);

    my_putchar(x);
    (*count)++;
}

void print_s(va_list *s, mod_t *curr_mod, int *count)
{
    char *str = va_arg(*s, char *);
    int i = 0;

    my_putstr(str);
    while (str[i] != '\0') {
        i++;
    }
    (*count) = (*count) + i;
}
