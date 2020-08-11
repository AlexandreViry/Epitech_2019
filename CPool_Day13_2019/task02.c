/*
** EPITECH PROJECT, 2019
** display_pixel
** File description:
** display_pixel
*/

#include <stdlib.h>
#include <SFML/Config.h>
#include "display_framebuffer.h"



framebuffer_t *framebuffer_create(unsigned  int width , unsigned  int height)
{
    framebuffer_t *fb;

    *fb.bitsPerPixel = 32;
    *fb.width = width;
    *fb.height = height;
    pixels = malloc(width * height * bitsPerPixel / 8);
    return (fb);
}


int pixels_array (void)
{
    int width;
    int height;
    int bitsPerPixel = 32;

    sfUint8 *pixels;
    
    pixels = malloc(width * height * bitsPerPixel / 8);
}

void  put_pixel(t_framebuffer *framebuffer , unsigned  int x, unsigned  int y, sfColorcolor)
{
