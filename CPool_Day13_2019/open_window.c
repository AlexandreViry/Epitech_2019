/*
** EPITECH PROJECT, 2019
** open_window
** File description:
** open a window and keep it open
*/

#include <SFML/Graphics/RenderWindow.h>

int main ()
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    
    video_mode.width = 800;
    video_mode.height = 600;
    video_mode.bitsPerPixel = 32;
    
    window = sfRenderWindow_create(video_mode,
                                   "MyWindow",
                                   sfDefaultStyle,
                                   NULL);
    while (sfRenderWindow_isOpen(window))
    {
        sfRenderWindow_display(window);
    }
    return(0);
}
