#include "include/my.h"

char *divide_string(char *str, char *str2)
{
    char *new_string;
    unsigned int len = strlen(str2);
    char *tmp;

    if ((tmp = malloc(2)) == NULL)
        malloc_error_message("divide_string");
    if (compare_size(str, str2) == 2) {
        tmp[0] = '0';
        tmp[1] = '\0';
        return tmp;
    }
    if ((new_string = malloc(len + 2)) == NULL)
        malloc_error_message("divide_string");
    for (unsigned int i = 0; i < len; i++)
        if (str[i] < str2[i]) {
            len++;
            break;
        }
    for (unsigned int i = 0; i < len; i++)
        new_string[i] = str[i];
    new_string[len] = '\0';
    return new_string;
}

char *recup_string(char *str, char *str2)
{
    char *new_string;
    int i;
    unsigned int len = strlen(str2);

    if (compare_size(str, str2) == 2)
        return NULL;
    for (unsigned int i = 0; i < len; i++)
        if (str[i] < str2[i] && len < strlen(str)) {
            len++;
            break;
        }
    if ((new_string = malloc(strlen(str) + 1)) == NULL)
        malloc_error_message("recup_string");
    for (i = 0; str[len] != '\0'; i++, len++) {
        new_string[i] = str[len];
    }
    new_string[i] = '\0';
    return new_string;
}

char *sub_loop2(char *str, char *str2)
{
    while (strcmp(str, "0") != 0 && compare_size(str, str2) == 1)
        str = infin_sub(str, str2);
    return str;
}

char *sub_loop(char *str, char *str2)
{
    char *count;

    for (count = "0"; strcmp(str, "0") != 0 && compare_size(str, str2) == 1;
         count = infin_add(count, "1")) {
        str = infin_sub(str, str2);
    }
    return count;
}

char *if_zero(char *result, char *str, char *str2, char *init)
{
    int i;
    char *mult;

    if (str[0] == '0' && strcmp(init, infin_mult(result, str2)) != 0)
        for (i = 0; str[i] == '0'; i++);
    else
        return result;
    mult = power_of_ten(i);
    result = infin_mult(result, mult);
    free(mult);
    return result;
}

char *big_numbers(char *nb1, char *nb2, char *result)
{
    char *init = nb1;
    char *rest;
    char *tmp;

    while (strcmp(nb1, "0") != 0 && compare_size(nb1, nb2) == 1 && strcmp
           (infin_mult(result, nb2), init) != 0)
    {
        tmp = divide_string(nb1, nb2);
        result = infin_add(infin_mult(result, "10"), sub_loop(tmp, nb2));
        rest = sub_loop2(tmp, nb2);
        nb1 = recup_string(nb1, nb2);
        if (nb1[0] != '0' || nb1[1] == '\0') {
            rest = infin_mult(rest, power_of_ten(strlen(nb1)));
            nb1 = infin_add(nb1, rest);
        }
        result = if_zero(result, nb1, nb2, init);
    }
    return result;
}

char *negative_to_positive2(char *str)
{
    str = my_revstr(str);
    str[strlen(str) - 1] = '\0';
    str = my_revstr(str);
    return str;
}

char *negativity(char *str, char *str2)
{
    char *tmp;

    if ((tmp = malloc(2)) == NULL)
        malloc_error_message("negativity");
    tmp[0] = '0';
    tmp[1] = '\0';
    if (str[0] == '-' && str2[0] == '-')
        return big_numbers(negative_to_positive2(str),
                           negative_to_positive2(str2), tmp);
    if (str[0] == '-' && str2[0] != '-')
        return change_sign(big_numbers(negative_to_positive2(str), str2, tmp));
    if (str[0] != '-' && str2[0] == '-')
        return change_sign(big_numbers(str, negative_to_positive2(str2), tmp));
    free(tmp);
    return str;
}

char *infin_div(char *str, char *str2)
{
    char *result;
    char *tmp;

    if ((tmp = malloc(2)) == NULL)
        malloc_error_message("infin_div");
    tmp[0] = '0';
    tmp[1] = '\0';
    if (strcmp(str, "0") == 0)
        return tmp;
    if (strcmp(str2, "0") == 0) {
        printf("Error: divisions by 0 are prohibited.\n");
        exit(84);
    }
    if (strcmp(str, str2) == 0) {
        tmp[0] = '1';
        return tmp;
    }
    if (str[0] == '-' || str2[0] == '-')
        return negativity(str, str2);
    if (strlen(str2) > strlen(str))
        return tmp;
    result = big_numbers(str, str2, tmp);
    return result;
}
