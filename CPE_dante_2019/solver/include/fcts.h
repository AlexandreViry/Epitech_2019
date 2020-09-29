/*
** EPITECH PROJECT, 2020
** dante_solver
** File description:
** include of functions
*/

#ifndef FCTS_H_
#define FCTS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct c_s {
    int line;
    int col;
} c_t;

int up(int **array, int i, int j);
int down(int **array, int line, int i, int j);
int left(int **array, int i, int j);
int right(int **array, int col, int i, int j);

int my_strlen(char *str);
int my_tablen(char **array);
char **sgl_to_dbl(char *path);
int **word_to_int_array(char **words);
int create_path(int **array, int col, int line);
int populate_cell(int **array, c_t coords, int i, int j);

void solve(int **array, c_t coords);

#endif
