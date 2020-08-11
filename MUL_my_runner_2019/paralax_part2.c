/*
** EPITECH PROJECT, 2020
** paralax2
** File description:
** rest of the paralax functions
*/

#include "include/my.h"

background_t *paralax_t8(background_t *back)
{
    sfVector2f vect;
    sfVector2f vect2;
    float x = sfSprite_getPosition(back->sprite12).x;

    vect2.y = 0.0;
    vect2.x = 1920.0;
    if (x <= -1920)
        sfSprite_setPosition(back->sprite12, vect2);
    vect.y = 0.0;
    vect.x = -15.0;
    sfSprite_move(back->sprite12, vect);
    back = paralax_t9(back);
    return (back);
}

background_t *paralax_t7(background_t *back)
{
    sfVector2f vect;
    sfVector2f vect2;
    float x = sfSprite_getPosition(back->sprite5).x;

    vect2.y = 0.0;
    vect2.x = 1920.0;
    if (x <= -1920)
        sfSprite_setPosition(back->sprite5, vect2);
    vect.y = 0.0;
    vect.x = -15.0;
    sfSprite_move(back->sprite5, vect);
    back = paralax_t8(back);
    return (back);
}

background_t *paralax_t6(background_t *back)
{
    sfVector2f vect;
    sfVector2f vect2;
    float x = sfSprite_getPosition(back->sprite11).x;

    vect2.y = 0.0;
    vect2.x = 1920.0;
    if (x <= -1920)
        sfSprite_setPosition(back->sprite11, vect2);
    vect.y = 0.0;
    vect.x = -11.0;
    sfSprite_move(back->sprite11, vect);
    back = paralax_t7(back);
    return (back);
}

background_t *paralax_t5(background_t *back)
{
    sfVector2f vect;
    sfVector2f vect2;
    float x = sfSprite_getPosition(back->sprite4).x;

    vect2.y = 0.0;
    vect2.x = 1920.0;
    if (x <= -1920)
        sfSprite_setPosition(back->sprite4, vect2);
    vect.y = 0.0;
    vect.x = -11.0;
    sfSprite_move(back->sprite4, vect);
    back = paralax_t6(back);
    return (back);
}
