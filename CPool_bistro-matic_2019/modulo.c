#include "include/my.h"

char *modulo_loop(char *str, char *str2)
{
    char *result = "0";
    char *tmp = "0";

    while (who_is_bigger(tmp, str) == 2) {
        tmp = infin_add(tmp, str2);
        result = infin_add(result, "1");
    }
    if (strcmp(infin_sub(str, tmp), "0") != 0)
        tmp = infin_sub(tmp, str2);
    free(result);
    return infin_sub(str, tmp);
}

char *big_numbers_modulo(char *str, char *str2, char *result)
{
    char *mod = str;
    char *tmp;
    char *rest = str;
    int diff = strlen(str) - strlen(str2);

    if (diff < 4)
        return(modulo_loop(str, str2));
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
    puts(result);
    puts(infin_mult(result, str2));
    return infin_sub(mod, infin_mult(str2, result));
}

char *modulo_negativity(char *str, char *str2)
{
    if (str[0] == '-' && str2[0] == '-')
        return big_numbers_modulo(negative_to_positive2(str),
                           negative_to_positive2(str2), "0");
    if (str[0] == '-' && str2[0] != '-')
        return change_sign(big_numbers_modulo(negative_to_positive2(str),
                                              str2, "0"));
    if (str[0] != '-' && str2[0] == '-')
        return change_sign(big_numbers_modulo(str, negative_to_positive2(str2),
                                              "0"));
    return str;
}

char *infin_mod(char *str, char *str2)
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
        return modulo_negativity(str, str2);
    if (strlen(str2) > strlen(str))
        return "0";
    result = big_numbers_modulo(str, str2, "0");
    return result;
}
