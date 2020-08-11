/*
** EPITECH PROJECT, 2020
** animation caracter
** File description:
** functions for carater's animations
*/

#include "./include/my.h"

int move_rect(sfIntRect *rect, int offset, int max_value)
{
    sfClock *clock;

    clock = sfClock_create();
    while (1) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) >= 100.5) {
            sfClock_restart(clock);
            if (rect->left <= max_value)
                rect->left = rect->left + offset;
            else
                rect->left = 360;
            return (0);
        }
    }
}

sfIntRect rect_jump(void)
{
    sfIntRect rect;

    rect.width = 155;
    rect.height = 280;
    rect.top = 280;
    rect.left = 8;
    return (rect);
}

sfIntRect rect_down(void)
{
    sfIntRect rect;

    rect.width = 135;
    rect.height = 190;
    rect.top = 350;
    rect.left = 750;
    return (rect);
}

sprite_t down(sprite_t *background)
{
    float y = sfSprite_getPosition(background->sprite).y;
    sfVector2f position;

    position.x = 300.0;
    position.y = 870.0;
    if (y < 800)
        return (*background);
    if (y >= 800) {
        (*background).pos = 4;
        (*background).rect = rect_down();
        sfSprite_setPosition(background->sprite, position);
        return (*background);
    }
}

sprite_t jump(sprite_t *background, float x)
{
    sfVector2f vect;
    vect.y = x;
    float y = sfSprite_getPosition(background->sprite).y;

    if (y == 800.0) {
        (*background).rect = rect_jump();
        sfSprite_move(background->sprite, vect);
    }
    return (*background);
}