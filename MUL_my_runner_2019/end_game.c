/*
** EPITECH PROJECT, 2020
** end game
** File description:
** end game screen
*/

#include "include/my.h"

mus_t *music_play(mus_t *music)
{
    music->music2 = sfMusic_createFromFile("sources/music.ogg");
    music->music = sfMusic_createFromFile("sources/scream.ogg");
    sfMusic_play(music->music2);
    return (music);
}

int error(int ac, char **av, sfRenderWindow *window)
{
    if (ac < 2) {
        sfRenderWindow_close(window);
        return (0);
    }
    if (ac > 2) {
        sfRenderWindow_close(window);
        return (84);
    }
    return (-1);
}

void destroy(obs_t *obs, sprite_t *masterchief, background_t *back)
{
    sfSprite_destroy(obs->sprite1);
    sfSprite_destroy(masterchief->sprite);
    sfSprite_destroy(back->sprite1);
    sfSprite_destroy(back->sprite2);
    sfSprite_destroy(back->sprite3);
    sfSprite_destroy(back->sprite4);
    sfSprite_destroy(back->sprite5);
    sfSprite_destroy(back->sprite6);
    sfSprite_destroy(back->sprite7);
    sfSprite_destroy(back->sprite9);
    sfSprite_destroy(back->sprite10);
    sfSprite_destroy(back->sprite11);
    sfSprite_destroy(back->sprite12);
    sfSprite_destroy(back->sprite13);
    sfSprite_destroy(back->sprite14);
}

int is_esc(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtKeyPressed)
        if (event.key.code == sfKeyEscape)
            return (1);
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return (48);
    }
    return (0);
}

void end_game(sfRenderWindow *window, sfEvent event)
{
    sfSprite *sprite1 = sfSprite_create();
    sfTexture *texture1 = sfTexture_createFromFile
    ("sources/game_over.jpg", NULL);

    sfSprite_setTexture (sprite1, texture1, sfTrue);
    sfRenderWindow_drawSprite(window, sprite1, NULL);
    sfRenderWindow_display(window);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (is_esc(event, window) == 1) {
            sfRenderWindow_close(window);
            break;
        }
        if (is_esc(event, window) == 48)
            break;
    }
}
