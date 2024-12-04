/*
** EPITECH PROJECT, 2024
** my putchar
** File description:
** 1.
*/

#include "../include/my_hunter.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
