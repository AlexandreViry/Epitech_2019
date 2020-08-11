/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** macro with all prototypes
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Music.h>
#include "struct1.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int printguide(char **str);
int move_rect(sfIntRect *rect, int offset, int max_value);
sprite_t jump(sprite_t *background, float x);
sfIntRect rect_jump();
sfIntRect rect_down();
sprite_t down(sprite_t *background);
sfRenderWindow* the_window(int width, int height, int bitsPerPixel);
background_t *paralax_t1(background_t *back);
background_t *paralax_t5(background_t *back);
background_t *paralax_t9(background_t *back);
background_t *set_texture(background_t *back, obs_t *obstacle);
background_t *initialisation2(background_t *back, obs_t *obstacle);
background_t *initialisation(background_t *back, obs_t *obstacle);
background_t *initialisation3(background_t *back, obs_t *obstacle);
int launch_menu(sfEvent event, sfRenderWindow *window, mus_t *music);
sprite_t *set_sprite(sprite_t *masterchief, char *filepath);
sprite_t texture_rect(sprite_t masterchief);
void  masterchief_sets(sprite_t *masterchief);
sprite_t *set_position(sprite_t *masterchief, float y, float x);
sfIntRect my_rect1(void);
sfVector2f vect_set(sfVector2f vect, float x, float y);
int my_strcmp2(char *str, char *str2);
obs_t *read_map(int ac, char **av, obs_t *obstacle, sprite_t *masterchief);
void end_game(sfRenderWindow *window, sfEvent event);
int main(int ac, char **av);
sfIntRect my_rect1(void);
mus_t *music_play(mus_t *music);
int error(int ac, char **av, sfRenderWindow *window);
void destroy(obs_t *obstacle, sprite_t *masterchief, background_t *background);
void destroy_music(mus_t *music);
int usage(int ac, char **av);
void add_on(mus_t *music, sfRenderWindow *window, sfEvent event);