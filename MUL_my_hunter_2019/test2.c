/*
** EPITECH PROJECT, 2019
** test2
** File description:
** second part of the code
*/

#include "./include/my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Music.h>

sfRenderWindow* my_window(int width, int height, int bitsPerPixel)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bitsPerPixel;

    window = sfRenderWindow_create(video_mode,
                                   "nyan_cat",
                                   sfDefaultStyle,
                                   NULL);
    return(window);
}

int print_blood(sfRenderWindow *window, sfSprite *sprite, sfSprite *sprite3)
{
    sfClock *clock;
    clock = sfClock_create();

    while(1) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite3, NULL);
        sfRenderWindow_display(window);

        if(sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 250) {
            sfClock_restart(clock);
            sfRenderWindow_clear(window, sfBlack);
            sfClock_destroy(clock);
            return (0);
        }
    }
}

void close_sound(sfSound *sound, sfSoundBuffer *soundbuffer)
{
    sfSound_destroy(sound);
    sfSoundBuffer_destroy(soundbuffer);
}
int  sound_set(int i)
{
    sfSoundBuffer *soundbuffer = sfSoundBuffer_createFromFile("click.wav");
    sfSound *sound = sfSound_create();
    sfClock *clock;
    sfSound_play(sound);
    sfSound_setBuffer(sound, soundbuffer);
    sfSound_play(sound);
    clock = sfClock_create();
    if (i == 118) {
        close_sound(sound, soundbuffer);
        return (0);
    }
    while(1) {
        if(sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 150) {
            close_sound(sound, soundbuffer);
            sfClock_destroy(clock);
            return (0);
        }
    }
    close_sound(sound, soundbuffer);
}
  
