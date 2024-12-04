/*
** EPITECH PROJECT, 2024
** strlen
** File description:
** 6
*/

#include "../include/my_hunter.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return (i);
}
