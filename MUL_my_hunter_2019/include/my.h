/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** macro with all prototypes
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Music.h>

sfRenderWindow* my_window(int width, int height, int bitsPerPixel);
int print_blood(sfRenderWindow *window, sfSprite *sprite, sfSprite *sprite3);
void close_sound(sfSound *sound, sfSoundBuffer *soundbuffer);
int  sound_set(int i);
int  killer_queen(int y1, int y2, sfEvent event, sfSprite *sprite, sfRenderWindow *window);
int analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite, sfMusic *music);
sfIntRect my_rect();
sfIntRect my_rectrect();
int move_rect(sfIntRect *rect, int offset, int max_value, int i);
void display_it(sfRenderWindow *window, sfSprite *sprite, sfSprite *sprite2);
int move_sprite(sfSprite* sprite, int max_size);
sfMusic *music_set();
void my_putstr(char *str);
int printguide(char **str);
