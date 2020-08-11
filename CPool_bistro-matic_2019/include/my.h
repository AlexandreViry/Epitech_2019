/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** we contain functions
*/

void my_sort_int_array(int *tab, int size);
void my_swap(int *a, int *b);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_putnstr(char const *str, int nb);
int my_find_char(char *str, char c);
int my_find_prime_sup(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const*s2, int n);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const*str);
int my_showmem(char const *str, int size);
int which_is_longer(int nb, int nb1);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *str, char *dest);
char *my_copy_strn(char *str, int n);
char *my_copy_str_skip(char *str, int n);
char *my_skip_char(char *str, char c);
char *my_replace_char(char *str, char a, char b);
char *my_int_to_str(char *str, int nb);
char *my_copy_segment(char *str, char *dest, int a, int b);
char *my_put_in_seg(char *str, char *seg, int a, int b);
char *my_memset(char *str, char c, int nb);
