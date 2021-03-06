/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** macro with all prototypes of libmy.a
*/

#include<unistd.h>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>

#define ATN(c) (c - '0')
#define NTA(n) (n + '0')

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *last_carry(char *result, int carry, int count);
char *calculator(char *str, char *str2, char *result);
char *double_negative(char *str, char *str2, char *result);
char *infin_add(char *str, char *str2);
char *infin_mult(char *str, char *str2);
char *infin_sub(char *str, char *str2);
char *infin_div(char *str, char *str2);
char *subtractor(char *str, char *str2, char *result);
char *change_sign(char *result);
int compare_size(char *str, char *str2);
char *negative(char *str, char *str2, char *result);
char *power_of_ten(int i);
char *div_loop(char *str, char *str2);
char *sub_loop(char *str, char *str2);
char *sub_loop2(char *str, char *str2);
char *recup_string(char *str, char *str2);
char *divide_string(char *str, char *str2);
char *negative_to_positive2(char *str);
char *infin_mod(char *str, char *str2);
char *if_zero(char *result, char *str, char *str2, char *init);
char *negativity(char *str, char *str2);
char *parentheses(char *str);
char *eval_expr(char *init);
char **my_str_to_word_array(char *init);
char *my_strcat(char *dest, char const *src);
char *clear_string(char *str);
int is_valid_string(char *str);
char *concat_strings(int ac, char **av);
void malloc_error_message(char *function);
char **delete_useless_zero(char **str);
char *search_two_signs(char *str);
