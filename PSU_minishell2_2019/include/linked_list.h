/*
** EPITECH PROJECT, 2020
** linked list
** File description:
** linked list structure
*/

typedef struct Linked_list Linked_list;
struct Linked_list
{
    char *string;
    Linked_list *next;
};

typedef struct my_struct
{
    char **env;
    char **tmp;
}my_struct_t;