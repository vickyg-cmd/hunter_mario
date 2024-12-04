/*
** EPITECH PROJECT, 2024
** put_float;
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "../include/my_hunter.h"

static int pow_10(int num)
{
    int return10 = 1;

    for (int i = 0; i < num; i++) {
        return10 *= 10;
    }
    return return10;
}

static int num_len(int num)
{
    int len = 0;

    while (num != 0) {
        num /= 10;
        len++;
    }
    return len;
}

void put_float(double num, int *count)
{
    int left_of_dot = (int) num;
    double right_of_dot = num - left_of_dot;
    int temp;
    int left_dig = num_len(left_of_dot);
    int right_dig = 6;

    for (int i = left_dig; i > 0; i--) {
        temp = (left_of_dot / pow_10(i - 1)) % 10;
        my_putchar(temp + '0');
        *count = *count + 1;
    }
        my_putchar('.');
        *count = *count + 1;
    for (int j = 1; j <= right_dig; j++) {
        temp = (right_of_dot * pow_10(j));
        temp = temp % 10;
        my_putchar((int) temp + '0');
        *count = *count + 1;
    }
}
