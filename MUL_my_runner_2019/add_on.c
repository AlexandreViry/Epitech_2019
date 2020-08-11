/*
** EPITECH PROJECT, 2020
** add_on
** File description:
** other functions
*/

#include "include/my.h"

void destroy_music(mus_t *music)
{
    sfMusic_destroy(music->music);
    sfMusic_destroy(music->music2);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}

int usage(int ac, char **av)
{
    if (ac ==  1)
        return (0);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("\nYou just have to run and jump");
        my_putstr(" because roads in Paris are in a");
        my_putstr(" poor condition.\n\n\n");
        my_putstr("USAGE:\n\n./my_runner -i\n\n");
        my_putstr("OPTIONS:\n\n-i: mode infinite\n\n");
        my_putstr("-h: print usage\n\nCONTROLS\n\n");
        my_putstr("space\tjump");
        my_putstr("\ns\tsquat (useless)\n");
        return (1);
    }
    return (0);
}

void add_on(mus_t *music, sfRenderWindow *window, sfEvent event)
{
    sfClock *clock;

    sfMusic_destroy(music->music2);
    sfMusic_play(music->music);
    clock = sfClock_create();
    while (1) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) >= 1500.0) {
            sfMusic_destroy(music->music);
            break;
        }
    }
    while (sfRenderWindow_isOpen(window))
        end_game(window, event);
}
