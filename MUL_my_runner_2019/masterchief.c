/*
** EPITECH PROJECT, 2020
** masterchief
** File description:
** initialisation of the main caracter
*/

#include "include/my.h"

sprite_t *set_sprite(sprite_t *masterchief, char *filepath)
{
    masterchief->texture = sfTexture_createFromFile(filepath, NULL);
    masterchief->sprite = sfSprite_create();
    sfSprite_setTexture (masterchief->sprite, masterchief->texture, sfTrue);
    return (masterchief);
}

sprite_t texture_rect2(sprite_t masterchief, sfVector2f vect,
sfVector2f position, float y)
{
    sfSprite_setPosition(masterchief.sprite, position);
    if (masterchief.pos == 3)
        masterchief.rect = my_rect1();
    masterchief.pos = 0;
    sfSprite_setTextureRect(masterchief.sprite, masterchief.rect);
    return (masterchief);
}

sprite_t texture_rect3(sprite_t masterchief, sfVector2f vect,
sfVector2f position, float y)
{
    masterchief.rect = rect_jump();
    sfSprite_setTextureRect(masterchief.sprite, masterchief.rect);
    sfSprite_move(masterchief.sprite, vect);
    masterchief.pos = 1;
    if (y <= 700.0)
        masterchief.pos = 2;
    return (masterchief);
}

sprite_t texture_rect4(sprite_t masterchief, sfVector2f vect2,
sfVector2f position, float y)
{
    masterchief.rect = rect_jump();
    sfSprite_setTextureRect(masterchief.sprite, masterchief.rect);
    sfSprite_move(masterchief.sprite, vect2);
    if (y >= 700 && masterchief.pos == 2)
        masterchief.pos = 3;
    return (masterchief);
}

sprite_t texture_rect(sprite_t masterchief)
{
    sfVector2f vect = vect_set(vect, vect.x, -20.0);
    sfVector2f vect2 = vect_set(vect2, vect2.x, 20);
    sfVector2f position = vect_set(position, 300, 800);
    float y = sfSprite_getPosition(masterchief.sprite).y;

    if (masterchief.pos == 4)
        sfSprite_setTextureRect(masterchief.sprite, masterchief.rect);
    if (y >= 800.0 && masterchief.pos != 4) {
        masterchief = texture_rect2(masterchief, vect, position, y);
        return (masterchief);
    }
    else if (masterchief.pos == 0 || masterchief.pos == 1 && y < 800.0) {
        masterchief = texture_rect3(masterchief, vect, position, y);
        return (masterchief);
    }
    else if (masterchief.pos == 2 || masterchief.pos == 3) {
        masterchief = texture_rect4(masterchief, vect2, position, y);
        return (masterchief);
    }
}
