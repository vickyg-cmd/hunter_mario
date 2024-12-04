/*
** EPITECH PROJECT, 2024
** B-CPE-110-BAR-1-1-settingup-victoria.gonzalez-malave
** File description:
** my_getnb
*/

#include "../include/pong.h"

int my_getnbr(char const *str)
{
    long int i = 0;
    int res = 0;
    int neg = -1;
    int ressimb = 1;

    while (str[i] == '+' || str[i] == '-'){
        if (str[i] == '+')
            neg = 1;
        ressimb = ressimb * neg;
        i++;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9'){
        res = res * 10;
        res = res + (str[i] - 48);
        i++;
    }
    if (i > 2147483647 || i < -2147483647)
        return (0);
    res = res * ressimb;
    return res;
}
