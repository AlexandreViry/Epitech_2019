/*
** EPITECH PROJECT, 2019
** graphical test1
** File description:
** disaplay things through a window
*/

#include "./include/my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Music.h>

int move_rect(sfIntRect *rect, int offset, int max_value, int i)
{
    sfClock *clock;
    
    clock = sfClock_create();
    while(1) {
        if(sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > i) {
            sfClock_restart(clock);
            if (rect->left < max_value)
                rect->left = rect->left + offset;
            else
                rect->left = 1;
            return (i);
        }
    }
}

void display_it(sfRenderWindow *window, sfSprite *sprite, sfSprite *sprite2)
{
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, sprite2, NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

int move_sprite(sfSprite* sprite, int max_size)
{
    sfVector2f offset;
    offset.x = 50.5000;
    offset.y = 0.1000;
    sfClock *clock;
    clock = sfClock_create();
    int i = sfSprite_getPosition(sprite).x;
    while(1) {        
        if(sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 10.5) {
            sfClock_restart(clock);
            sfSprite_move(sprite, offset);
            if (i > 1980) {
                offset.x = 0.00000;
                offset.y = rand () % 900;
                sfSprite_setPosition(sprite, offset);
            }
            return(0);
        } 
    }
}

sfMusic *music_set()
{
    sfMusic *music = sfMusic_createFromFile("./music8bit.ogg");
    sfMusic_play(music);
    return(music);
}

int main (int ac, char **str)
{
    if (ac == 2) {
        printguide(str);
        return (0);
    }
    else if (ac == 1) {
        int width = 1920;
        int height = 1080;
        int speed = 170;
        int bitsPerPixel = 32;                               
        sfRenderWindow *window = my_window(width, height, bitsPerPixel);
        sfEvent event;
        sfTexture *texture = sfTexture_createFromFile("./fond mignon.jpg", NULL);
        sfTexture *texture2 = sfTexture_createFromFile("./nyancat.png", NULL);
        sfTexture *texture3 = sfTexture_createFromFile("./sang1.PNG", NULL);
        sfIntRect rect = my_rectrect();
        sfSprite *sprite = sfSprite_create();
        sfSprite *sprite2 = sfSprite_create();
        sfSprite *sprite3 = sfSprite_create();
        sfSoundBuffer *soundbuffer2 = sfSoundBuffer_createFromFile("killer-queen.ogg");
        sfSound *sound2 = sfSound_create();
        sfSound_setBuffer(sound2, soundbuffer2);
        sfMusic *music = music_set();
        sfMusic_setVolume(music, 70.00);
        sfSprite_setTexture (sprite, texture, sfTrue);
        sfSprite_setTexture (sprite2, texture2, sfTrue);
        sfSprite_setTexture (sprite3, texture3, sfTrue);
        while (sfRenderWindow_isOpen(window)) {
            move_sprite(sprite2, 1920);
            sfSprite_setTextureRect(sprite2, rect);
            display_it(window, sprite, sprite2);
            speed = move_rect(&rect, 206, 580, speed);
            while (sfRenderWindow_pollEvent(window, &event)) {
                int i = analyse_events(window, event, sprite2, music);
                if (i == 118) {
                    sfSound_play(sound2);
                    print_blood(window, sprite, sprite3);
                    speed = speed - 15;
                }
            }
        }
        close_sound(sound2, soundbuffer2);
        sfMusic_destroy(music);
        sfRenderWindow_destroy(window);
        return(0);
    }
    else
        exit;
}
