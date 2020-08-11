/*
** EPITECH PROJECT, 2020
** main_menu
** File description:
** started when the game is launched
*/

#include "include/my.h"

int is_enter(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtKeyPressed)
        if (event.key.code == sfKeyEnter)
            return (1);
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return (48);
    }
    return (0);
}

int launch_menu(sfEvent event, sfRenderWindow *window, mus_t *music)
{
    sfSprite *sprite1 = sfSprite_create();
    sfTexture *texture1 = sfTexture_createFromFile("sources/fond.jpg", NULL);

    sfSprite_setTexture (sprite1, texture1, sfTrue);
    while (sfRenderWindow_pollEvent(window, &event)) {
        sfRenderWindow_drawSprite(window, sprite1, NULL);
        sfRenderWindow_display(window);
        if (is_enter(event, window) == 1)
            return (0);
        if (is_enter(event, window) == 48) {
            destroy_music(music);
            return (1);
        }
    }
    return (2);
}
