#include "include/my.h"

char *parse(char *str1, char *str2, char *str3)
{
    switch (str2[0]) {
    case '+' :
        return (infin_add(str1, str3));
    case '-' :
        return (infin_sub(str1, str3));
    case '*':
        return (infin_mult(str1, str3));
    case '/':
        return (infin_div(str1, str3));
    case '%':
        return (infin_mod(str1, str3));
    }
    return str1;
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
}

void display_array(char **array)
{
    for(int i = 0; array[i] != NULL; i++)
        printf("%s", array[i]);
    printf("\n");
}

char **calc_priority(char **tmp, int count)
{
    char **new_array;
    int i;
    int y;

    for (i = 0; tmp[i] != NULL; i++);
    new_array = malloc(sizeof(char *) * (i - 1));
    for (y = 0; y < count - 1; y++)
        new_array[y] = tmp[y];
    new_array[count - 1] = parse(tmp[count - 1], tmp[count], tmp[count + 1]);
    for (count += 2; count < i; count++, y++)
        new_array[y + 1] = tmp[count];
    new_array[y + 1] = NULL;
    return new_array;
}

char **basic_op(char **tmp)
{
    int count;

    for (count = 0; tmp[count] != NULL; count++) {
        switch (tmp[count][0]) {
        case '-' :
            if (tmp[count][1] == '\0') {
                tmp = calc_priority(tmp, count);
                if (tmp[count] == NULL)
                    return tmp;
                count = 0;
            }
            continue;
        case '+' :
            if (tmp[count][1] == '\0') {
                tmp = calc_priority(tmp, count);
                if (tmp[count] == NULL)
                    return tmp;
                count = 0;
            }
            continue;
        }
    }
    return tmp;
}

char **priority_loop(char **tmp)
{
    int count;

    for (count = 0; tmp[count] != NULL; count++) {
        switch (tmp[count][0]) {
        case '*' :
            tmp = calc_priority(tmp, count);
            count = 0;
            continue;
        case '/' :
            tmp = calc_priority(tmp, count);
            count = 0;
            continue;
        case '%':
            tmp = calc_priority(tmp, count);
            count = 0;
            continue;
        }
    }
    return tmp;
}

char *eval_expr(char *init)
{
    int i;
    char **tmp = my_str_to_word_array(init);
    char *result;

    for (i = 0; tmp[i] != NULL; i++);
    if ( i == 3)
        return parse(tmp[0], tmp[1], tmp[2]);
    tmp = priority_loop(tmp);
    tmp = basic_op(tmp);
    result = malloc(strlen(tmp[0]) + 1);
    result = strcpy(result, tmp[0]);
    free_array(tmp);
    return result;
}
