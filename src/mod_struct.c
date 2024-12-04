/*
** EPITECH PROJECT, 2024
** struct
** File description:
** of printf
*/

#include "../include/my_hunter.h"

static int end_letter_and_dot(char c)
{
    const char *valid_let = "diuoxXfFeEgGaAcspn.";

    while (*valid_let) {
        if (*valid_let == c) {
            return 1;
        }
        *valid_let++;
    }
    return 0;
}

static int str_into_num(char *str, int *cur)
{
    int i = *cur;
    int re = 0;

    while (end_letter_and_dot(str[i]) == 0) {
        re *= 10;
        re += str[i] - '0';
        i++;
        *cur = *cur + 1;
    }
    *cur = *cur - 1;
    return re;
}

static int is_num(char c)
{
    const char *valid_let = "1234567890";

    while (*valid_let) {
        if (*valid_let == c) {
            return 1;
        }
    *valid_let++;
    }
    return 0;
}

static int is_flag(char c)
{
    const char *valid_let = "+ #";

    while (*valid_let) {
        if (*valid_let == c) {
            return 1;
        }
        *valid_let++;
    }
    return 0;
}

mod_t *default_mod(void)
{
    mod_t *default_mod = malloc(sizeof(mod_t));

    default_mod->width = 0;
    default_mod->precision = 0;
    default_mod->flags = '?';
    default_mod->specifier = '?';
    return default_mod;
}

static void makeneg(mod_t *mods, char *str)
{
    int neg = 0;

    while (*str) {
    if (*str == '-') {
        neg = 1;
    }
    str++;
    }
    if (neg == 1) {
        mods->width = mods->width * -1;
    }
}

mod_t *create_mod(char *flags)
{
    mod_t *temp_mods = default_mod();
    int i;
    int found_dot = 0;

    for (i = 0; flags[i] != '\0'; i++) {
        if (flags[i] == '.')
            found_dot = 1;
        if (is_flag(flags[i]) == 1)
            temp_mods->flags = flags[i];
        if (is_num(flags[i]) == 1 && found_dot == 0)
            temp_mods->width = str_into_num(flags, &i);
        if (is_num(flags[i]) == 1 && found_dot == 1)
            temp_mods->precision = str_into_num(flags, &i);
    }
    temp_mods->specifier = flags[i - 1];
    makeneg(temp_mods, flags);
    return temp_mods;
}
