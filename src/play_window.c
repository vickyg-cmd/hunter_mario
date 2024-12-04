/*
** EPITECH PROJECT, 2024
** B-MUL-100-BAR-1-1-myhunter-victoria.gonzalez-malave
** File description:
** page_window
*/

#include "../include/my_hunter.h"

bool principe_pressed(sfSprite *principe_sprite, sfEvent event)
{
    sfFloatRect rectfloat = sfSprite_getGlobalBounds(principe_sprite);
    int mou_x = event.mouseButton.x;
    int mou_y = event.mouseButton.y;

    if (event.type == sfEvtMouseButtonPressed){
        if (sfFloatRect_contains(&rectfloat, mou_x, mou_y))
            return 1;
    }
    return 0;
}

bool coin_pressed(sfSprite *coin_sprite, sfEvent event)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(coin_sprite);
    int mou_x = event.mouseButton.x;
    int mou_y = event.mouseButton.y;

    if (event.type == sfEvtMouseButtonPressed){
        if (sfFloatRect_contains(&rect, mou_x, mou_y))
            return 1;
    }
    return 0;
}

void event_close_2(scene_t *stuff, coin_prin_t *stuff_spr)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(stuff->window_t, &event)){
        if (event.type == sfEvtClosed)
            stuff->close = 1;
        if (event.type == sfEvtKeyPressed)
            key_handle(stuff, event);
        if (principe_pressed(stuff_spr->principe_s, event)){
            kill_principe(stuff_spr->principe_s);
            make_sound(stuff_spr->music_2);
        }
        if (coin_pressed(stuff_spr->coin_s, event)){
            stuff->scene = 0;
            make_sound_3(stuff_spr->music_3);
        }
    }
}

void play_page(scene_t *stuff, coin_prin_t *spr_stuff)
{
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock1;
    sfClock *clock3;
    sfTime time;
    coin_t *coins = coins_l();

    clock1 = sfClock_create();
    clock3 = sfClock_create();
    create_coin(texture, spr_stuff, coins);
    while (stuff->scene == 1 && stuff->close == 0){
        event_close_2(stuff, spr_stuff);
        sfRenderWindow_clear(stuff->window_t, sfBlack);
        sfRenderWindow_drawSprite(stuff->window_t, spr_stuff->game_s, NULL);
        draw_prin_coin(spr_stuff, stuff);
        move_principe(spr_stuff->principe_s, stuff, clock1);
        check_inside(spr_stuff->principe_s);
        lit_move_coin(clock3, coins, time);
        sfRenderWindow_display(stuff->window_t);
    }
}
