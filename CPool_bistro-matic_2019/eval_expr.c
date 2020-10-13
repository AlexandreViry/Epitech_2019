#include "include/my.h"

/* This is the function which will call the functions specific to each type of
   operation according to the operators given as parameters in str2. */

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

/* This function will return the array with a new string when there is a
   priority operation */

char **calc_priority(char **tmp, int count)
{
    char **new_array;
    int i;
    int y;

    for (i = 0; tmp[i] != NULL; i++);
    if ((new_array = malloc(sizeof(char *) * (i - 1))) == NULL)
        malloc_error_message("calc_priority");
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

/* This loop will check if there are priority operations and send them to the calculator first */

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

char **new_negative_array(char **tmp)
{
    char **new;
    int len;
    int nb = 0;
    int y = 0;

    for (len = 0; tmp[len] != NULL; len++);
    if ((new = malloc(sizeof(char *) * (len + 1))) == NULL)
        malloc_error_message("new_negative_array");
    for (int i = 0; i < len; i++, nb++)
        if ((new[nb] = malloc(strlen(tmp[i]) + 2)) == NULL)
            malloc_error_message("new_negative_array");
    for (int i = 0; i < len; i++) {
        strcpy(new[i], tmp[i]);
        if ((tmp[i][0] > '9' || tmp[i][0] < '0') &&
            tmp[i][1] == '-' && tmp[i + 1] != NULL) {
            new[i][1] = '\0';
            new[i + 1][0] = '-';
            for (y = 0; tmp[i + 1][y] != '\0'; y++)
                new[i + 1][y + 1] = tmp[i + 1][y];
            new[i + 1][y + 1] = '\0';
            i++;
        }
    }
    new[len] = NULL;
    return new;
}

char **negative_string(char **tmp, int i)
{
    char **res;

    for (int count = 0; count < i - 1; count++) {
        if ((tmp[count][0] > '9' || tmp[count][0] < '0') &&
            tmp[count][1] == '-') {
            res = new_negative_array(tmp);
            free_array(tmp);
            return res;
        }
    }
    return tmp;
}

/* This function checks if the first character is a '-', and if so, it concats
   the first two strings to get a negative number and return the new array. */

char **first_char_is_negative(char **tmp, int len)
{
    char **result;
    int nb = 1;

    if (tmp[0][0] != '-')
        return tmp;
    if ((result = malloc(sizeof(char *) * (len))) == NULL)
        malloc_error_message("first_char_is_negative");
    if ((result[0] = malloc(strlen(tmp[0]) + strlen(tmp[1]) + 1)) == NULL)
        malloc_error_message("first_char_is_negative");
    for (int i = 2; i < len && tmp[i] != NULL; i++, nb++)
        if ((result[nb] = malloc(strlen(tmp[i]) + 1)) == NULL)
            malloc_error_message("first_char_is_negative");
    nb = 1;
    result[0] = my_strcat(tmp[0], tmp[1]);
    for (int i = 2; i < len; i++, nb++)
        strcpy(result[nb], tmp[i]);
    result[len - 1] = NULL;
    free(tmp);
    return result;
}

/* This function is the one that will call all the operating functions. */

char *eval_expr(char *init)
{
    int i;
    char **tmp;
    char *result;

    init = parentheses(init);
    tmp = my_str_to_word_array(init);
    tmp = delete_useless_zero(tmp);
    for (i = 0; tmp[i] != NULL; i++);
    tmp = first_char_is_negative(tmp, i);
    tmp = negative_string(tmp, i);
    if (i == 3)
        return parse(tmp[0], tmp[1], tmp[2]);
    tmp = priority_loop(tmp);
    tmp = basic_op(tmp);
    if ((result = malloc(strlen(tmp[0]) + 1)) == NULL)
        malloc_error_message("eval_expr");
    result = strcpy(result, tmp[0]);
    free_array(tmp);
    return result;
}
