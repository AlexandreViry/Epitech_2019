/*
** EPITECH PROJECT, 2019
** main
** File description:
** call the other functions
*/

#include "./include/my.h"

sprite_t *analyze_events(sfRenderWindow *window, sfEvent event,
sprite_t *masterchief)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeySpace)
            (*masterchief) = jump(masterchief, -20.0);
        else if (event.key.code == sfKeyS)
            (*masterchief) = down(masterchief);
        return (masterchief);
    }
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void display_it(sfRenderWindow *window, background_t *back,
sprite_t *masterchief, obs_t *obs)
{
    sfRenderWindow_drawSprite(window, back->sprite1, NULL);
    sfRenderWindow_drawSprite(window, back->sprite2, NULL);
    sfRenderWindow_drawSprite(window, back->sprite9, NULL);
    sfRenderWindow_drawSprite(window, back->sprite3, NULL);
    sfRenderWindow_drawSprite(window, back->sprite10, NULL);
    sfRenderWindow_drawSprite(window, back->sprite4, NULL);
    sfRenderWindow_drawSprite(window, back->sprite11, NULL);
    sfRenderWindow_drawSprite(window, back->sprite5, NULL);
    sfRenderWindow_drawSprite(window, back->sprite12, NULL);
    sfRenderWindow_drawSprite(window, back->sprite6, NULL);
    sfRenderWindow_drawSprite(window, back->sprite13, NULL);
    sfRenderWindow_drawSprite(window, back->sprite7, NULL);
    sfRenderWindow_drawSprite(window, back->sprite14, NULL);
    sfRenderWindow_drawSprite(window, obs->sprite1, NULL);
    sfRenderWindow_drawSprite(window, masterchief->sprite, NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

sprite_t utilitary(sfRenderWindow *window, sprite_t *masterchief,
background_t *back, obs_t *obs)
{
    display_it(window, back, masterchief, obs);
    paralax_t1(back);
    move_rect(&masterchief->rect, 155, 1280);
}

int main_function(int ac, char **av, sfRenderWindow *window,
sfMusic *music2)
{
    sfEvent event;
    obs_t obstacle;
    sprite_t masterchief;
    background_t back;

    initialisation(&back, &obstacle);
    masterchief_sets(&masterchief);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyze_events(window, event, &masterchief);
        masterchief = texture_rect(masterchief);
        utilitary(window, &masterchief, &back, &obstacle);
        read_map(ac, av, &obstacle, &masterchief);
        if (obstacle.end == 1) {
            destroy(&obstacle, &masterchief, &back);
            return (obstacle.end);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    sfEvent event;
    mus_t music;
    sfRenderWindow *window = the_window(1920, 1080, 64);
    int menu = 2;

    if (error(ac, av, window) >= 0)
        return (error(ac, av, window));
    if (usage(ac, av) == 1)
        return (0);
    music_play(&music);
    while (menu == 2)
        menu = launch_menu(event, window, &music);
    if (menu == 1)
        return (0);
    if (main_function(ac, av, window, music.music2) == 0) {
        destroy_music(&music);
        return (0);
    }
    add_on(&music, window, event);
    return (0);
}
