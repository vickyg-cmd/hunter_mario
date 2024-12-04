/*
** EPITECH PROJECT, 2024
** B-CPE-110-BAR-1-1-settingup-victoria.gonzalez-malave
** File description:
** my_hunter
*/

#ifndef INCLUDED_MY_HUNTER_H
    #define INCLUDED_MY_HUNTER_H
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/sysmacros.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <stdbool.h>
    #include <event.h>
    #include <math.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/PrimitiveType.h>
    #include <SFML/Graphics/RenderStates.h>
    #include <SFML/Graphics/Vertex.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Window/VideoMode.h>
    #include <SFML/Window/WindowHandle.h>
    #include <SFML/Window/Window.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
//printf:
typedef struct my_mods {
    int width;
    int precision;
    char flags;
    char specifier;
}mod_t;
typedef struct my_flags {
    char flag;
    void (*function)(va_list *, mod_t *, int *);
} flags_t;
//pasarle la window y lescena
typedef struct scene_saver {
    int scene;
    int close;
    sfRenderWindow *window_t;
    sfMusic *music_t;
    int kill;
}scene_t;
typedef struct coin_principe_saver {
    sfSprite *principe_s;
    sfSprite *coin_s;
    sfSprite *game_s;
    sfMusic *music_2;
    sfMusic *music_3;
}coin_prin_t;
typedef struct coin_s {
        sfSprite *coin_sprite;
        sfTexture *texture;
        sfIntRect *rect;
        sfVector2f position;
        struct coin_s *prev;
        struct coin_s *next;
} coin_t;

//printf
void my_putchar(char);
int my_putnbr(int);
int my_putstr(char *);
int my_numlen(int num);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char const *str);
int my_printf(const char *main_str, ...);
void print_d(va_list *d, mod_t *curr_mod, int *count);
void print_f(va_list *f, mod_t *curr_mod, int *count);
void print_c(va_list *c, mod_t *curr_mod, int *count);
void print_s(va_list *s, mod_t *curr_mod, int *count);
void print_perc(int *count);
mod_t *create_mod(char *flags);
void put_float(double num, int *count);
//flag_hunter.c
void flag_hunt(void);
//home_window_stuff.c
int home_page(scene_t *stuff, coin_prin_t *spr_stuff);
void key_handle(scene_t *stuff, sfEvent event);
//tema_music.c
int theme_music(scene_t *stuff);
void music_insert(coin_prin_t *spr_stuff);
void make_sound(sfMusic *music_2);
void make_sound_3(sfMusic *music_3);
//hunt_principe.c
void move_principe(sfSprite *sprite, scene_t *stuff, sfClock *clock);
void check_inside(sfSprite *principe_sprite);
void kill_principe(sfSprite *principe_sprite);
void more_coins(coin_prin_t *stuff_sprt);
//play_window.c
void play_page(scene_t *stuff, coin_prin_t *spr_stuff);
//create_sprites.c
void create_button(sfSprite **button_sprite, sfTexture **texture);
void create_home(sfSprite **home_sprite, sfTexture **texture);
void create_coin(sfTexture *texture, coin_prin_t *spr_stuff, coin_t *lala);
//add_sprites.c
void create_home_button(sfRenderWindow *win, sfSprite *hom, sfSprite *but);
void draw_prin_coin(coin_prin_t *spr_stuff, scene_t *stuff);
void lit_move_coin(sfClock *clo, sfIntRect *re, coin_prin_t *spr, sfTime time);
//my_hunter.c
coin_t *go_head(coin_t *coins);
coin_t *coins_l(void);
#endif
