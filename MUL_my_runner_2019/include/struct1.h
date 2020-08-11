/*
** EPITECH PROJECT, 2019
** first structure
** File description:
** Structure file
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Music.h>

typedef struct Sprite
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int pos;
    int pos2;
    float posx;
    float posx_end;
    float posy;
}sprite_t;

typedef struct obstacle
{
    sfTexture *texture1;
    sfSprite *sprite1;
    float posx;
    float posx_end;
    float posy;
    int end;
}obs_t;

typedef struct Music
{
    sfMusic *music;
    sfMusic *music2;
}mus_t;

typedef struct Background
{
    sfTexture *texture1;
    sfTexture *texture2;
    sfTexture *texture3;
    sfTexture *texture4;
    sfTexture *texture5;
    sfTexture *texture6;
    sfTexture *texture7;
    sfSprite *sprite1;
    sfSprite *sprite2;
    sfSprite *sprite3;
    sfSprite *sprite4;
    sfSprite *sprite5;
    sfSprite *sprite6;
    sfSprite *sprite7;
    sfTexture *texture8;
    sfTexture *texture9;
    sfTexture *texture10;
    sfTexture *texture11;
    sfTexture *texture12;
    sfTexture *texture13;
    sfTexture *texture14;
    sfSprite *sprite8;
    sfSprite *sprite9;
    sfSprite *sprite10;
    sfSprite *sprite11;
    sfSprite *sprite12;
    sfSprite *sprite13;
    sfSprite *sprite14;
}background_t;