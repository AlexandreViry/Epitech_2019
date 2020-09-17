/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** macro with all prototypes
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

typedef struct map {
    char *map;
    int **map_int;
    int size_height;
    int size_length;
    int greatest_value;
} map_t;

char *my_revstr(char *str);
char **my_str_to_word_array(char *str, char c);
void init_map(char **filepath, map_t *map);
