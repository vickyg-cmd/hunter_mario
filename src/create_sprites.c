/*
** EPITECH PROJECT, 2024
** B-MUL-100-BAR-1-1-myhunter-victoria.gonzalez-malave
** File description:
** create_sprites
*/

#include "../include/my_hunter.h"

void create_home(sfSprite **home_sprite, sfTexture **texture)
{
    *home_sprite = sfSprite_create();
    *texture = sfTexture_createFromFile("home.png", NULL);
    sfSprite_setTexture(*home_sprite, *texture, sfTrue);
}

void create_button(sfSprite **button_sprite, sfTexture **texture)
{
    sfVector2f position = {220, 550};

    *texture = sfTexture_createFromFile("button_play.png", NULL);
    *button_sprite = sfSprite_create();
    sfSprite_setTexture(*button_sprite, *texture, sfTrue);
    sfSprite_setPosition(*button_sprite, position);
}

void create_game(sfTexture *texture, coin_prin_t *spr_stuff)
{
    sfSprite *game_sprite;

    game_sprite = sfSprite_create();
    texture = sfTexture_createFromFile("game_page.png", NULL);
    sfSprite_setTexture(game_sprite, texture, sfTrue);
    spr_stuff->game_s = game_sprite;
}

static void create_principe(sfTexture *texture, coin_prin_t *spr_stuff)
{
    int value = 0;
    sfSprite *principe_sprite;
    sfVector2f position = {220, 550};

    texture = sfTexture_createFromFile("principe_florian.png", NULL);
    principe_sprite = sfSprite_create();
    sfSprite_setTexture(principe_sprite, texture, sfTrue);
    sfSprite_setPosition(principe_sprite, position);
    spr_stuff->principe_s = principe_sprite;
    value = (rand() % 850) + 50;
    sfSprite_setPosition(principe_sprite, (sfVector2f){0, value});
    music_insert(spr_stuff);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= max_value)
        rect->left = 0;
    else
        rect->left += 84;
}


void move_coin(coin_t *coins)
{
    
    while (coins != NULL) {
        coins->rect->left = 0;
        coins->rect->top = 0;
        coins->rect->width = 84;
        coins->rect->height = 84;
        sfSprite_setTextureRect(coins->coin_sprite, *(coins->rect));
        if (coins->next != NULL)
            coins = coins->next;
        else
            break;
    }
    // coins = go_head(coins);
}

void create_coin(sfTexture *texture, coin_prin_t *spr_stuff, coin_t *coins)
{
    /*sfSprite *coin_sprite;
    sfVector2f position = {205, 545};

    texture = sfTexture_createFromFile("coin.png", NULL);
    coin_sprite = sfSprite_create();
    sfSprite_setTexture(coin_sprite, texture, sfTrue);
    sfSprite_setPosition(coin_sprite, position);
    spr_stuff->coin_s = coin_sprite;*/
    move_coin(coins);
    create_principe(texture, spr_stuff);
    create_game(texture, spr_stuff);
}
