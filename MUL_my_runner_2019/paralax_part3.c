/*
** EPITECH PROJECT, 2020
** paralax_t3
** File description:
** part3 of the paralax
*/

#include "include/my.h"

background_t *paralax_t12(background_t *back)
{
    sfVector2f vect;
    sfVector2f vect2;
    float x = sfSprite_getPosition(back->sprite14).x;

    vect2.y = 0.0;
    vect2.x = 1920.0;
    if (x <= -1920)
        sfSprite_setPosition(back->sprite14, vect2);
    vect.y = 0.0;
    vect.x = -20.0;
    sfSprite_move(back->sprite14, vect);
    return (back);
}

background_t *paralax_t11(background_t *back)
{
    sfVector2f vect;
    sfVector2f vect2;
    float x = sfSprite_getPosition(back->sprite7).x;

    vect2.x = 1920.0;
    vect2.y = 0.0;
    if (x <= -1920)
        sfSprite_setPosition(back->sprite7, vect2);
    vect.y = 0.0;
    vect.x = -20.0;
    sfSprite_move(back->sprite7, vect);
    back = paralax_t12(back);
    return (back);
}

background_t *paralax_t10(background_t *back)
{
    sfVector2f vect;
    sfVector2f vect2;
    float x = sfSprite_getPosition(back->sprite13).x;

    vect2.y = 0.0;
    vect2.x = 1920.0;
    if (x <= -1920)
        sfSprite_setPosition(back->sprite13, vect2);
    vect.y = 0.0;
    vect.x = -17.0;
    sfSprite_move(back->sprite13, vect);
    back = paralax_t11(back);
    return (back);
}

background_t *paralax_t9(background_t *back)
{
    sfVector2f vect;
    sfVector2f vect2;
    float x = sfSprite_getPosition(back->sprite6).x;

    vect2.y = 0.0;
    vect2.x = 1920.0;
    if (x <= -1920)
        sfSprite_setPosition(back->sprite6, vect2);
    vect.x = -17.0;
    vect.y = 0.0;
    sfSprite_move(back->sprite6, vect);
    back = paralax_t10(back);
    return (back);
}