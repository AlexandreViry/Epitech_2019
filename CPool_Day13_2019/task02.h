/*
** EPITECH PROJECT, 2019
** frame_buffer_structure
** File description:
** make the structure for framebuffer
*/

typedef struct framebuffer framebuffer_t

struct framebuffer
{
    int width;
    int height;
    int bitsPerPixel;
    sfUint8 *pixels;
};
