/*
** EPITECH PROJECT, 2024
** B-MUL-100-BAR-1-1-myhunter-victoria.gonzalez-malave
** File description:
** hunt_principe
*/

#include "../include/my_hunter.h"

void check_inside(sfSprite *principe_sprite)
{
    int pos_x_princ = 1;
    int value = 0;

    pos_x_princ = sfSprite_getPosition(principe_sprite).x;
    if (pos_x_princ < 0 || pos_x_princ > 950){
        value = (rand() % 750) + 50;
        sfSprite_setPosition(principe_sprite, (sfVector2f){0, value});
    }
}

void move_principe(sfSprite *principe_sprite, scene_t *stuff, sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = sfTime_asSeconds(time);
    if (seconds > 0.009){
        sfSprite_move(principe_sprite, (sfVector2f){1, 0});
        sfClock_restart(clock);
    }
}

void kill_principe(sfSprite *principe_sprite)
{
    int value = 0;

    value = (rand() % 750) + 50;
    sfSprite_setPosition(principe_sprite, (sfVector2f){0, value});
}

/*void more_coins(coin_prin_t *sprt_stuff)
{
    coins->next = malloc(sizeof(coin_t));
    coins->nezt->prev = coins;
}*/
