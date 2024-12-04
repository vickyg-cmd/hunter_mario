/*
** EPITECH PROJECT, 2024
** putnbr
** File description:
** lib
*/

#include "../include/my_hunter.h"

int my_putnbr(int nb)
{
    int aux = 0;

    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 9){
        my_putnbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}
