/*
** EPITECH PROJECT, 2024
** printf
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "../include/my_hunter.h"

const flags_t print[] = {
    {'d', &print_d},
    {'f', &print_f},
    {'F', &print_f},
    {'c', &print_c},
    {'s', &print_s},
};

int end_letter(char c)
{
    const char *valid_let = "diuoxXfFeEgGaAcspn?";
    int i = 0;

    while (valid_let[i] != '?') {
        if (valid_let[i] == c) {
            return 1;
        }
    i++;
    }
    return 0;
}

int str_into_num(char *str, char *cur)
{
    int i = 0;
    int re = 0;

    while ((str[i] != '.') || (end_letter(str[i]) != 1)) {
        *cur = *cur + 1;
        re *= 10;
        re += str[i] + '0';
        i++;
    }
    return re;
}

char *flag_array(int *start, const char *str)
{
    int len = 0;
    char *flag = NULL;
    int curr = *start;
    int i = 0;

    while (end_letter(str[curr + len]) == 0) {
        len++;
    }
    flag = malloc(sizeof(char) * (len + 2));
    for (i = 0; i <= len; i++) {
        flag[i] = str[curr + i];
        *start = *start + 1;
    }
    flag[len + 1] = '\0';
    return flag;
}

static int flag_print(char *flag, va_list *main_args, int *count)
{
    int i = 0;
    mod_t *cur_mods = create_mod(flag);

    while (print[i].flag != cur_mods->specifier) {
        i++;
    }
    print[i].function(main_args, cur_mods, count);
    free(cur_mods);
    free(flag);
}

int main_print(const char *main_str, int *count, va_list *main_args)
{
    int cur_pos = 0;
    char *flag = NULL;

    while (main_str[cur_pos] != '\0') {
        if (main_str[cur_pos] != '%') {
            my_putchar(main_str[cur_pos]);
            *count = *count + 1;
            cur_pos++;
            continue;
        }
        if (main_str[cur_pos] == '%' && main_str[cur_pos + 1] == '%') {
            print_perc(count);
            continue;
        }
        if (main_str[cur_pos] == '%') {
            flag = flag_array(&cur_pos, main_str);
            flag_print(flag, main_args, count);
        }
    }
}

int my_printf(const char *main_str, ...)
{
    int count = 0;
    va_list main_args;

    va_start(main_args, main_str);
    main_print(main_str, &count, &main_args);
    va_end(main_args);
    return count;
}
