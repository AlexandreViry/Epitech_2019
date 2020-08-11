/*
** EPITECH PROJECT, 2020
** masterchief2
** File description:
** other functions of masterchief initialisation
*/

#include "include/my.h"

void  masterchief_sets(sprite_t *masterchief)
{
    masterchief = set_sprite(masterchief, "sources/masterchief");
    masterchief = set_position(masterchief, 800.0, 300.0);
    masterchief->rect = my_rect1();
    masterchief->pos = 0;
}

sprite_t *set_position(sprite_t *masterchief, float y, float x)
{
    sfVector2f position;
    position.y = y;
    position.x = x;
    sfSprite_setPosition(masterchief->sprite, position);
    return (masterchief);
}

sfVector2f vect_set(sfVector2f vect, float x, float y)
{
    vect.x = x;
    vect.y = y;
    return (vect);
}

sfIntRect my_rect1(void)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 360;
    rect.width = 155;
    rect.height = 280;
    return (rect);
}