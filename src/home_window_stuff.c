/*
** EPITECH PROJECT, 2024
** B-MUL-100-BAR-1-1-myhunter-victoria.gonzalez-malave
** File description:
** home_window_stuff
*/

#include "../include/my_hunter.h"

void key_handle(scene_t *stuff, sfEvent event)
{
    if (event.key.code == sfKeyEscape)
        stuff->close = 1;
}

bool play_pressed(sfSprite *sprite, sfEvent event)
{
    sfFloatRect rectfloat = sfSprite_getGlobalBounds(sprite);
    int mou_x = event.mouseButton.x;
    int mou_y = event.mouseButton.y;

    if (event.type == sfEvtMouseButtonPressed){
        if (sfFloatRect_contains(&rectfloat, mou_x, mou_y))
            return true;
    }
    return false;
}

void event_close(scene_t *stuff, sfSprite *but, coin_prin_t *spr_stuff)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(stuff->window_t, &event)){
        if (event.type == sfEvtClosed)
            stuff->close = 1;
        if (event.type == sfEvtKeyPressed)
            key_handle(stuff, event);
        if (play_pressed(but, event)){
            stuff->scene = 1;
            play_page(stuff, spr_stuff);
        }
    }
}

int home_page(scene_t *stuff, coin_prin_t *spr_stuff)
{
    sfTexture *texture;
    sfSprite *home_sprite;
    sfSprite *button_sprite;
    sfVideoMode v_m = {950, 950, 950};

    stuff->window_t = sfRenderWindow_create(v_m, "VGM", sfClose, NULL);
    create_home(&home_sprite, &texture);
    create_button(&button_sprite, &texture);
    while (stuff->scene == 0 && stuff->close == 0){
        event_close(stuff, button_sprite, spr_stuff);
        sfRenderWindow_clear(stuff->window_t, sfBlack);
        create_home_button(stuff->window_t, home_sprite, button_sprite);
        sfRenderWindow_display(stuff->window_t);
    }
    sfSprite_destroy(home_sprite);
    sfSprite_destroy(button_sprite);
    sfTexture_destroy(texture);
}
