/*
** EPITECH PROJECT, 2024
** B-MUL-100-BAR-1-1-myhunter-victoria.gonzalez-malave
** File description:
** my_hunter
*/

#include "../include/my_hunter.h"

scene_t *default_scene(void)
{
    scene_t *default_scene = malloc(sizeof(scene_t));

    default_scene->scene = 0;
    default_scene->close = 0;
    default_scene->window_t;
    default_scene->music_t;
    default_scene->kill = 0;
    return default_scene;
}

coin_prin_t *default_spr(void)
{
    coin_prin_t *default_spr = malloc(sizeof(coin_prin_t));

    return default_spr;
}

static void destroy_scene(scene_t *stuff)
{
    sfMusic_destroy(stuff->music_t);
    sfRenderWindow_close(stuff->window_t);
    sfRenderWindow_destroy(stuff->window_t);
    free(stuff);
}

static void destroy_spr(coin_prin_t *stuff)
{
    sfSprite_destroy(stuff->principe_s);
    sfSprite_destroy(stuff->coin_s);
    sfMusic_destroy(stuff->music_2);
    sfMusic_destroy(stuff->music_3);
    sfSprite_destroy(stuff->game_s);
    free(stuff);
}

coin_t *go_head(coin_t *coins)
{
    while (coins && coins->prev != NULL){
        coins = coins->prev;
    }
    
    return coins;
}

coin_t *coins_l(void)
{
    coin_t *coins = malloc(sizeof(coin_t));
    int value = (rand() % 750) + 50;
    coins->prev = NULL;
    coins->next = NULL;
    coins->texture = sfTexture_createFromFile("coin.png", NULL);
    coins->coin_sprite = sfSprite_create();
    coins->rect = ma
    coins->rect->height = 0;
    coins->rect->left = 0;
    coins->rect->top = 84;
    coins->rect->width = 84;
    coins->position.x = 0;
    coins->position.y = value;
    sfSprite_setPosition(coins->coin_sprite, coins->position);


    // for (int i = 0; i < 3; i++) {
    //     coins->next = malloc(sizeof(coin_t));
    //     coins->next->prev = coins;
    //     coins = coins->next;
    //     coins->texture = sfTexture_createFromFile("coin.png", NULL);
    //     coins->coin_sprite = sfSprite_create();
    //     coins->rect->height = 0;
    //     coins->rect->left = 0;
    //     coins->rect->top = 84;
    //     coins->rect->width = 84;
    //     value = (rand() % 750) + 50;
    //     coins->position.x = 0;
    //     coins->position.y = value;
    //     sfSprite_setPosition(coins->coin_sprite, coins->position);
    //     coins->next = NULL;
    // }
    // coins = go_head(coins);
    return (coins);
}

int main(int argc, char **argv)
{
    scene_t *stuff = default_scene();
    coin_prin_t *spr_stuff = default_spr();
    //coin_t *spawn = default_spwn();

    if (argc == 2 && argv[1][1] == 'h') {
        flag_hunt();
        return 0;
    }
    theme_music(stuff);
    srand(time(NULL));
    home_page(stuff, spr_stuff);
    destroy_scene(stuff);
    destroy_spr(spr_stuff);
    return 0;
}
