/*
** EPITECH PROJECT, 2024
** B-MUL-100-BAR-1-1-myhunter-victoria.gonzalez-malave
** File description:
** add_sprites
*/

#include "../include/my_hunter.h"

void create_home_button(sfRenderWindow *window, sfSprite *home, sfSprite *butt)
{
    sfRenderWindow_drawSprite(window, home, NULL);
    sfRenderWindow_drawSprite(window, butt, NULL);
}

void draw_prin_coin(coin_prin_t *spr_stuff, scene_t *stuff)
{
    sfRenderWindow_drawSprite(stuff->window_t, spr_stuff->principe_s, NULL);
    sfRenderWindow_drawSprite(stuff->window_t, spr_stuff->coin_s, NULL);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= max_value)
        rect->left = 0;
    else
        rect->left += 84;
}

void lit_move_coin(sfClock *clo, coin_t *coins, sfTime t)
{
    float seconds;

    t = sfClock_getElapsedTime(clo);
    seconds = sfTime_asSeconds(t);
        if (seconds > 0.09){
            move_rect(coins->rect, 84, 420);
            sfSprite_setTextureRect(coins->, *rect);
            sfClock_restart(clo);
        }
}
