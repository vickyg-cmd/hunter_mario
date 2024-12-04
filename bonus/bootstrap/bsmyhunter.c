/*
** EPITECH PROJECT, 2024
** B-MUL-100-BAR-1-1-myhunter-victoria.gonzalez-malave
** File description:
** bsmyhunter
*/

#include "../../include/bsmy_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void manage_mouse_click(sfMouseButtonEvent event)
{
    //my_printf("Mouse x=%d y=%d\n", event.x, event.y);
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event))
    {
        if (event.type == sfEvtClosed)
            close_window(window);
        if (event.type == sfEvtKeyPressed)
            close_window(window);
        //my_printf("key pressed");
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(event.mouseButton);
    }
}

/*void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= max_value)
        rect->left = 0;
    else
        rect->left += 110;
}*/

void move_rect(sfIntRect *rect, int offset, int max_value, sfVector2f *position)
{
    rect->left = (rect->left + offset) % (max_value + offset);
    position->x = position->x + 30;
    position->y = position->y - 10;
}

int main()
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {800, 800, 32};
    sfEvent event;
    sfSprite *sprite;
    sfTexture *texture;
    sfBool resetRect;
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;
    int offset = 110;
    int max_value = 220;
    sfClock *clock;
    sfTime time;
    float seconds;

    clock = sfClock_create();
    window = sfRenderWindow_create(video_mode, "my_window", sfClose, NULL);
    texture = sfTexture_createFromFile("pajaro.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfVector2f position = {50, 400};
    while (sfRenderWindow_isOpen(window))
    {
        analyse_events(window, event);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        time = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(time);
        if (seconds > 0.2)
        {
            //move_rect(&rect, offset, max_value);
            move_rect(&rect, offset, max_value, &position);
            sfSprite_setTextureRect(sprite, rect);
            sfClock_restart(clock);
        }
        sfSprite_setPosition(sprite, position);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
