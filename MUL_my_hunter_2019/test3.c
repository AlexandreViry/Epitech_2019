/*
** EPITECH PROJECT, 2019
** test 3
** File description:
** part 3 of the code
*/

#include "./include/my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Music.h>

int  killer_queen(int y1, int y2, sfEvent event, sfSprite *sprite, sfRenderWindow *window)
{
    sfVector2f offset;
    offset.x = 1930.09;
    offset.y = 0.005;
    if (y1 > y2 && y1 < y2 + 80) {
        sfSprite_setPosition(sprite, offset);
        return (118);
    }
    return(0);
}

int analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite, sfMusic *music)
{
    int x1 = sfMouse_getPositionRenderWindow(window).x;
    int y1 = sfMouse_getPositionRenderWindow(window).y;
    int x2 = sfSprite_getPosition(sprite).x;
    int y2 = sfSprite_getPosition(sprite).y;

    if (event.type == sfEvtMouseButtonPressed) {
        sfMusic_pause(music);
        if (x1 > x2 && x1 < x2 + 176) {
            sfMusic_pause(music);
           int i = killer_queen(y1, y2, event, sprite, window);
           sound_set(i);
           sfMusic_play(music);
           return(i);
        }
        sound_set(0);
        sfMusic_play(music);
    }
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    return(0);
}

sfIntRect my_rect()
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 1920;
    rect.height = 1080;
    return (rect);
}

sfIntRect my_rectrect()
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 176;
    rect.height = 80;
    return (rect);
}

int printguide(char **str)
{
    if (str[1][0] == '-' && str[1][1] == 'h'){
        my_putstr("Nyan-cats invade the world.\n");
        my_putstr("Eliminate them by using the power of ");
        my_putstr("Killer Queen, clicking on all the cats you will see.\n");
        my_putstr("Every click will destroy the time for less than one second ");
        my_putstr("so use this power if the cat goes too fast.\n");
        my_putstr("Good Luck\n");
        return (0);
    }
}
