/*
** EPITECH PROJECT, 2020
** paralax part1
** File description:
** firt functions of the paralax
*/

#include "include/my.h"

background_t *paralax_t4(background_t *back)
{
    sfVector2f vect;
    sfVector2f vect2;
    float x = sfSprite_getPosition(back->sprite10).x;

    vect2.y = 0.0;
    vect2.x = 1920.0;
    if (x <= -1920)
        sfSprite_setPosition(back->sprite10, vect2);
    vect.y = 0.0;
    vect.x = -7.0;
    sfSprite_move(back->sprite10, vect);
    back = paralax_t5(back);
    return (back);
}

background_t *paralax_t3(background_t *back)
{
    sfVector2f vect;
    sfVector2f vect2;
    float x = sfSprite_getPosition(back->sprite3).x;

    vect2.y = 0.0;
    vect2.x = 1920.0;
    if (x <= -1920)
        sfSprite_setPosition(back->sprite3, vect2);
    vect.y = 0.0;
    vect.x = -7.0;
    sfSprite_move(back->sprite3, vect);
    back = paralax_t4(back);
    return (back);
}

background_t *paralax_t2(background_t *back)
{
    sfVector2f vect;
    sfVector2f vect2;
    float x = sfSprite_getPosition(back->sprite9).x;

    vect2.y = 0.0;
    vect2.x = 1920.0;
    if (x <= -1920)
        sfSprite_setPosition(back->sprite9, vect2);
    vect.y = 0.0;
    vect.x = -5.0;
    sfSprite_move(back->sprite9, vect);
    back = paralax_t3(back);
    return (back);
}

background_t *paralax_t1(background_t *back)
{
    sfVector2f vect;
    sfVector2f vect2;
    float x = sfSprite_getPosition(back->sprite2).x;

    vect2.y = 0.0;
    vect2.x = 1920.0;
    if (x <= -1920.0) {
        sfSprite_setPosition(back->sprite2, vect2);
        back = paralax_t2(back);
        return (back);
    }
    vect.y = 0.0;
    vect.x = -5.0;
    sfSprite_move(back->sprite2, vect);
    back = paralax_t2(back);
    return (back);
}