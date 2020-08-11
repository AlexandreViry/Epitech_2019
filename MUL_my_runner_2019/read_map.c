/*
** EPITECH PROJECT, 2020
** read map
** File description:
** read the map
*/

#include "include/my.h"

obs_t *collision(obs_t *obs, sprite_t *master, int ac, char **av)
{
    obs->posx = sfSprite_getPosition(obs->sprite1).x - 14.0;
    obs->posy = sfSprite_getPosition(obs->sprite1).y;
    obs->posx_end = obs->posx + 110.0;
    master->posx = sfSprite_getPosition(master->sprite).x;
    master->posy = sfSprite_getPosition(master->sprite).y;

    if (master->posx >= obs->posx && master->posx <= obs->posx_end)
        if (master->posy >= 790.0)
            obs->end = 1;
    return (obs);
}

obs_t *infinite_mod(obs_t *obs)
{
    sfVector2f vect;
    sfVector2f vect2;
    float x = sfSprite_getPosition(obs->sprite1).x;

    vect2.y = 930.0;
    vect2.x = 1920.0;
    if (x <= -200.0)
        sfSprite_setPosition(obs->sprite1, vect2);
    vect.y = 0.0;
    vect.x = -20.0;
    sfSprite_move(obs->sprite1, vect);
    return (obs);
}

obs_t *read_map(int ac, char **av, obs_t *obs, sprite_t *masterchief)
{
    obs = collision(obs, masterchief, ac, av);
    if (av[1][0] == '-' && av[1][1] == 'i' || ac == 2) {
        infinite_mod(obs);
        return (obs);
    }
    return (obs);
}
