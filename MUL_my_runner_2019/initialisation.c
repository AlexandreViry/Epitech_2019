/*
** EPITECH PROJECT, 2020
** initialisation
** File description:
** texture initalisation
*/

#include "include/my.h"

background_t *set_texture(background_t *back, obs_t *obstacle)
{
    sfSprite_setTexture (obstacle->sprite1, obstacle->texture1, sfTrue);
    sfSprite_setTexture (back->sprite1, back->texture1, sfTrue);
    sfSprite_setTexture (back->sprite2, back->texture2, sfTrue);
    sfSprite_setTexture (back->sprite3, back->texture3, sfTrue);
    sfSprite_setTexture (back->sprite4, back->texture4, sfTrue);
    sfSprite_setTexture (back->sprite5, back->texture5, sfTrue);
    sfSprite_setTexture (back->sprite6, back->texture6, sfTrue);
    sfSprite_setTexture (back->sprite7, back->texture7, sfTrue);
    sfSprite_setTexture (back->sprite10, back->texture10, sfTrue);
    sfSprite_setTexture (back->sprite11, back->texture11, sfTrue);
    sfSprite_setTexture (back->sprite12, back->texture12, sfTrue);
    sfSprite_setTexture (back->sprite13, back->texture13, sfTrue);
    sfSprite_setTexture (back->sprite14, back->texture14, sfTrue);
    sfSprite_setTexture (back->sprite9, back->texture9, sfTrue);
    return (back);
}

background_t *initialisation2(background_t *back, obs_t *obstacle)
{
    obstacle->sprite1 = sfSprite_create();
    obstacle->texture1 = sfTexture_createFromFile("./sources/hole.png", NULL);
    back->texture9 = sfTexture_createFromFile("./sources/houses4.png", NULL);
    back->texture10 = sfTexture_createFromFile("./sources/houses3.png", NULL);
    back->texture11 = sfTexture_createFromFile("./sources/houses2.png", NULL);
    back->texture12 = sfTexture_createFromFile("./sources/houses1.png", NULL);
    back->texture13 = sfTexture_createFromFile("./sources/wall.png", NULL);
    back->texture14 = sfTexture_createFromFile("./sources/road.png", NULL);
    back->sprite9 = sfSprite_create();
    back->sprite10 = sfSprite_create();
    back->sprite11 = sfSprite_create();
    back->sprite12 = sfSprite_create();
    back->sprite13 = sfSprite_create();
    back->sprite14 = sfSprite_create();
    back = initialisation3(back, obstacle);
    return (back);
}

background_t *initialisation(background_t *back, obs_t *obstacle)
{
    back->texture1 = sfTexture_createFromFile("./sources/sky.png", NULL);
    back->texture2 = sfTexture_createFromFile("./sources/houses4.png", NULL);
    back->texture3 = sfTexture_createFromFile("./sources/houses3.png", NULL);
    back->texture4 = sfTexture_createFromFile("./sources/houses2.png", NULL);
    back->texture5 = sfTexture_createFromFile("./sources/houses1.png", NULL);
    back->texture6 = sfTexture_createFromFile("./sources/wall.png", NULL);
    back->texture7 = sfTexture_createFromFile("./sources/road.png", NULL);
    back->sprite1 = sfSprite_create();
    back->sprite2 = sfSprite_create();
    back->sprite3 = sfSprite_create();
    back->sprite4 = sfSprite_create();
    back->sprite5 = sfSprite_create();
    back->sprite6 = sfSprite_create();
    back->sprite7 = sfSprite_create();
    back = initialisation2(back, obstacle);
    back = set_texture(back, obstacle);
}

background_t *initialisation3(background_t *back, obs_t *obs)
{
    sfVector2f vect;
    sfVector2f vect2;

    vect.y = 0.0;
    vect.x = 1920.0;
    vect2.y = 930.0;
    vect2.x = 1920.0;
    sfSprite_setPosition(obs->sprite1, vect2);
    sfSprite_setPosition(back->sprite9, vect);
    sfSprite_setPosition(back->sprite10, vect);
    sfSprite_setPosition(back->sprite11, vect);
    sfSprite_setPosition(back->sprite12, vect);
    sfSprite_setPosition(back->sprite13, vect);
    sfSprite_setPosition(back->sprite14, vect);
    return (back);
}
