/*
** EPITECH PROJECT, 2024
** B-MUL-100-BAR-1-1-myhunter-victoria.gonzalez-malave
** File description:
** tema_music
*/

#include "../include/my_hunter.h"

int theme_music(scene_t *stuff)
{
    stuff->music_t = sfMusic_createFromFile("sound_track.ogg");
    sfMusic_setVolume(stuff->music_t, 20);
    sfMusic_play(stuff->music_t);
    if (!stuff->music_t) {
        return 0;
    } else
        return 1;
}

void music_insert(coin_prin_t *spr_stuff)
{
    spr_stuff->music_2 = sfMusic_createFromFile("sound.wav");
    spr_stuff->music_3 = sfMusic_createFromFile("mariodie.wav");
}

void make_sound(sfMusic *music_2)
{
    sfMusic_setVolume(music_2, 100);
    sfMusic_stop(music_2);
    sfMusic_play(music_2);
}

void make_sound_3(sfMusic *music_3)
{
    sfMusic_setVolume(music_3, 100);
    sfMusic_stop(music_3);
    sfMusic_play(music_3);
}
