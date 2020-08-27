#include "include/my.h"

char *div_loop(char *str, char *str2)
{
    char *result = "0";
    char *tmp = "0";

    while (who_is_bigger(tmp, str) == 2) {
        tmp = infin_add(tmp, str2);
        result = infin_add(result, "1");
    }
    if (strcmp(infin_sub(tmp, str), "0") != 0)
        result = infin_sub(result, "1");
    free(tmp);
    return result;
}

char *divide_string(char *str, unsigned int len)
{
    char *new_string;

    if (str == NULL)
        return NULL;
    if (strlen(str) < len)
        return str;
    new_string = malloc(len + 2);
    for (unsigned int i = 0; i < len; i++)
        new_string[i] = str[i];
    new_string[len] = '\0';
    return new_string;
}

char *recup_string(char *str, unsigned int len)
{
    char *new_string;
    int i;

    if (strlen(str) < len)
        return "0";
    new_string = malloc(strlen(str) + 1);
    for (i = 0; str[len] != '\0'; i++, len++) {
        new_string[i] = str[len];
    }
    new_string[i] = '\0';
    return new_string;
}

char *sub_loop(char *str, char *str2)
{
    char *count;

    for (count = "0"; who_is_bigger(str, str2) != 2; count =
             infin_add(count, "1"))
        str = infin_sub(str, str2);
    return count;
}

char *sub_loop2(char *str, char *str2)
{
    char *count;

    for (count = "0"; who_is_bigger(str, str2) != 2; count =
             infin_add(count, "1"))
        str = infin_sub(str, str2);
    return str;
}

char *big_numbers(char *str, char *str2, char *result)
{
    char *tmp;
    char *rest = str;
    int diff = strlen(str) - strlen(str2);

    printf("%d\n", diff);
    if (diff < 4)
        return(div_loop(str, str2));
    while (strcmp(recup_string(str, strlen(str2)), "0") != 0) {
        if (who_is_bigger(divide_string(str, strlen(str2)), str2) == 2) {
            tmp = divide_string(str, strlen(str2) + 1);
            rest = recup_string(str, strlen(str2) + 1);
            str = infin_add(rest, infin_mult(sub_loop2(tmp, str2),
                                             power_of_ten(strlen(rest) + 1)));
        } else {
            tmp = divide_string(str, strlen(str2));
            rest = recup_string(str, strlen(str2));
            str = infin_add(rest, infin_mult(sub_loop2(tmp, str2),
                                            power_of_ten(strlen(rest) + 1)));
        }
        result = infin_add(infin_mult(result, "10"), sub_loop(tmp, str2));
    }
    result[strlen(result) - 1] = '\0';
    if (strcmp(rest, "0") != 0)
        result = infin_sub(result, "1");
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
    if (str[0] == '-' && str2[0] == '-')
        return big_numbers(negative_to_positive2(str),
                           negative_to_positive2(str2), "0");
    if (str[0] == '-' && str2[0] != '-')
        return change_sign(big_numbers(negative_to_positive2(str), str2, "0"));
    if (str[0] != '-' && str2[0] == '-')
        return change_sign(big_numbers(str, negative_to_positive2(str2), "0"));
    return str;
}

char *infin_div(char *str, char *str2)
{
    char *result;

    if (strcmp(str, "0") == 0)
        return "0";
    if (strcmp(str2, "0") == 0) {
        printf("Error: divisions by 0 are prohibited.\n");
        exit(84);
    }
    if (strcmp(str, str2) == 0)
        return "1";
    if (str[0] == '-' || str2[0] == '-')
        return negativity(str, str2);
    if (strlen(str2) > strlen(str))
        return "0";
    result = big_numbers(str, str2, "0");
    return result;
}
