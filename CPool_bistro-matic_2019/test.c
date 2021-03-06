#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define ATN(c) (c - '0')
#define NTA(n) (n + '0')

char *eval_expr(char *init);
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

void malloc_error_message(char *function)
{
    printf("Error: memory allocation failed in function: %s.\n", function);
    exit(-1);
}

char *power_of_ten(int i)
{
    char *res;
    int y;

    if ((res = malloc(i + 2)) == NULL)
        malloc_error_message("power_of_ten");
    for (y = 0; y < i; y++)
        res[y] = '0';
    res[y] = '1';
    res[y + 1] = '\0';
    res = my_revstr(res);
    return res;
}

char *clear_string(char *result)
{
    int i;
    int y;

    for (i = 0; result[i] == '0' && result[i + 1] != '\0'; i++)
        if (result[i] == '\0')
            return result;
    for (y = 0; result[i] != '\0'; y++, i++)
        result[y] = result[i];
    result[y] = '\0';
    return result;
}

char *my_revstr(char *str) {

    int len_str = 0;
    char *tmp;
    int y = 0;

    len_str = strlen(str);
    if ((tmp = malloc(len_str + 1)) == NULL)
        malloc_error_message("my_revstr");
    len_str--;
    for (; len_str >= 0; y++, len_str--)
        tmp[y] = str[len_str];
    tmp[y] = '\0';
    return tmp;
}

char *my_strcat (char *dest, char const *src) {

    int size_src = strlen(src);
    int size_dest = strlen(dest);
    int end_of_line = size_src + size_dest + 1;
    char *res;
    int tmp = 0;

    if ((res = malloc(end_of_line)) == NULL)
        malloc_error_message("my_strcat");
    for (int i = 0; i < size_dest; i++)
        res[i] = dest[i];
    for (int i = size_dest; src[tmp] != '\0'; i++, tmp++)
        res[i] = src[tmp];
    res[end_of_line - 1] = '\0';
    return(res);
}

char *concat_strings(int ac, char **av)
{
    char *result;

    if ((result = malloc(strlen(av[1]) + 1)) == NULL)
        malloc_error_message("concat_strings");
    strcpy(result, av[1]);
    for (int i = 2; i < ac; i++)
        result = my_strcat(result, av[i]);
    return result;
}

int check_for_negative_char(char *str)
{
    if (str[0] == '-' && str[1] != '(' && (str[1] > '9' || str[1] < '0'))
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            for (; str[i] == '-'; i++)
                if (str[i + 1] != '\0' && (str[i + 1] == '/' || str[i + 1] =='*'
                                           || str[i] == '%' || str[i] == '+'))
                    return 1;
        }
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+' || str[i] == '*' || str[i] == '%' || str[i] == '/' ||
            str[i] == '-')
            for (int y = i; str[y] == '+' || str[y] == '*' || str[y] == '%' ||
                     str[y] == '/' || str[y] == '-'; y++)
                if (y - i >= 3)
                    return 1;
    }
    return 0;
}

int is_valid_string(char *str)
{
    char c;

    if (str[0] == '+' || str[0] == '*' || str[0] == '/' || str[0] == '%' ||
        strlen(str) == 0)
        return 1;
    c = str[strlen(str) - 1];
    if ((c > '9' || c < '0') && c != ')')
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        c = str[i];
        if (c != '-' && c != '+' && c != '*' && c != '/' && c != '%'
            && c != '(' && c != ')' && (c > '9' || c < '0') && c != '\0') {
            printf("Syntax Error: only integers and");
            printf(" basic operators are allowed.\n");
            return 1;
        }
    }
    if (str[0] == '\0')
        return 1;
    return check_for_negative_char(str);
}

char **delete_useless_zero(char **str)
{
    int y;
    char *tmp;

    for (int i = 0; str[i] != NULL; i++)
        if (str[i][0] == '0') {
            for (y = 0; str[i][y] == '0' && str[i][y + 1] != '\0'; y++);
            tmp = my_revstr(str[i]);
            if ((str[i] = realloc(str[i], strlen(str[i]) - y + 1)) == NULL)
                malloc_error_message("delete_useless_zero");
            strncpy(str[i], tmp, strlen(tmp) - y);
            str[i][strlen(tmp) - y] = '\0';
            str[i] = my_revstr(str[i]);
        }
    return str;
}

char *last_carry(char *result, int carry, int count)
{
    int i;
    int y;

    for (int i = 0; i != count; i++)
        result[i] = NTA(result[i]);
    if (carry > 0) {
        result[count] = NTA(carry);
        result[count + 1] = '\0';
    }
    else
        result[count] = '\0';
    result = my_revstr(result);
    for (i = 0; result[i] == '0' && result[i + 1] != '\0'; i++)
        if (result[i] == '\0')
            return result;
    for (y = 0; result[i] != '\0'; y++, i++)
        result[y] = result[i];
    result[y] = '\0';
    return result;
}

char *negative_carry(char *result, int carry, int count)
{
    int i;
    int y;

    if (carry > 0) {
        result[count] = result[count] - carry;
        result[count + 1] = '\0';
    }
    else
        result[count] = 0;
    for (int i = 0; i != count; i++)
        result[i] = NTA(result[i]);
    result = my_revstr(result);
    for (i = 0; result[i] == '0' && result[i + 1] != '\0'; i++)
        if (result[i] == '\0')
            return result;
    for (y = 0; result[i] != '\0'; y++, i++)
        result[y] = result[i];
    result[y] = '\0';
    return result;
}

char *subtractor(char *str, char *str2, char *result)
{
    int carry = 0;
    int count = 0;

    for (int i = 0; str2[i] != '\0' && str[i] != '\0'; i++, count = i) {
        result[i] = str[i] - (str2[i] + carry);
        carry = 0;
        if (result[i] < 0) {
            result[i] += 10;
            carry++;
        }
    }
    for (; str[count] != '\0'; count++) {
        result[count] = ATN(str[count]) - carry;
        carry = 0;
        if (result[count] < 0) {
            result[count] += 10;
            carry++;
        }
    }
    return negative_carry(result, carry, count);
}

char *calculator(char *str, char *str2, char *result)
{
    int carry = 0;
    int count = 0;

    for (int i = 0; str2[i] != '\0'; i++, count = i) {
        result[i] = str[i] + str2[i] + carry - 96;
        carry = 0;
        if (result[i] > 9) {
            result[i] -= 10;
            carry++;
        }
    }
    for (; str[count] != '\0'; count++) {
        result[count] = ATN(str[count]) + carry;
        carry = 0;
        if (result[count] > 9) {
            result[count] -= 10;
            carry++;
        }
    }
    return last_carry(result, carry, count);
}

char *double_negative(char *str, char *str2, char *result)
{
    char *result2;
    int len;
    int i;

    str[strlen(str) - 1] = '\0';
    str2[strlen(str2) - 1] = '\0';
    result = calculator(str, str2, result);
    len = strlen(result);
    if ((result2 = malloc(len + 2)) == NULL)
        malloc_error_message("double_negative");
    result2[0] = '-';
    for (i = 1; result[i] != '\0'; i++)
        result2[i] = result[i - 1];
    result2[i] = result[i - 1];
    result2[len + 1] = '\0';
    return result2;
}

int compare_size(char *str, char *str2)
{
    if (strlen(str) == strlen(str2))
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] < str2[i])
                return 2;
            if (str[i] > str2[i])
                return 1;
        }
    if (strlen(str) > strlen(str2))
        return 1;
    if (strlen(str2) > strlen(str))
        return 2;
    return 1;
}

char *change_sign(char *result)
{
    char *res;
    int i;

    if ((res = malloc(strlen(result) + 2)) == NULL)
        malloc_error_message("change_sign");
    res[0] = '-';
    for (i = 0; result[i] != '\0'; i++)
        res[i + 1] = result[i];
    res[i + 1] = '\0';
    return res;
}

char *negative(char *str, char *str2, char *result)
{
    if (str[strlen(str) - 1] == '-') {
        str[strlen(str) - 1] = '\0';
        if (compare_size(my_revstr(str), my_revstr(str2)) == 2)
            result = subtractor(str2, str, result);
        if (compare_size(my_revstr(str), my_revstr(str2)) == 1) {
            result = subtractor(str, str2, result);
            result = change_sign(result);
        }
    } else {
        str2[strlen(str2) - 1] = '\0';
        if (compare_size(my_revstr(str), my_revstr(str2)) == 1)
            result = subtractor(str, str2, result);
        if (compare_size(my_revstr(str), my_revstr(str2)) == 2) {
            result = subtractor(str2, str, result);
            result = change_sign(result);
        }
    }
    return result;
}

char *func_call(char *str, char *str2, int len)
{
    char *result;

    if ((result = malloc(len + 2)) == NULL)
        malloc_error_message("func_call");
    str = my_revstr(str);
    str2 = my_revstr(str2);
    if (strlen(str) == 0 || strlen(str2) == 0)
        return calculator(str, str2, result);
    if (str2[strlen(str2) - 1] == '-' && str[strlen(str) - 1] == '-')
        return double_negative(str, str2, result);
    else if (str2[strlen(str2) - 1] == '-' || str[strlen(str) - 1] == '-')
        return negative(str, str2, result);
    result = calculator(str, str2, result);
    return result;
}

char *infin_add(char *str, char *str2)
{
    int value1;
    int value2;
    char *result;

    value1 = strlen(str);
    value2 = strlen(str2);
    if (value1 <= value2)
        result = func_call(str2, str, value2);
    else
        result = func_call(str, str2, value1);
    return result;
}

char *sub_negative(char *str, char *str2, char *result)
{
    char *result2;
    int len;
    int i;

    result = calculator(str, str2, result);
    len = strlen(result);
    if ((result2 = malloc(len + 2)) == NULL)
        malloc_error_message("sub_negative");
    result2[0] = '-';
    for (i = 1; result[i] != '\0'; i++)
        result2[i] = result[i - 1];
    result2[i] = result[i - 1];
    result2[len + 1] = '\0';
    return result2;
}

char *check_negative(char *str, char *str2, char *result)
{
    str2 = change_sign(my_revstr(str2));
    str2 = my_revstr(str2);
    result = negative(str, str2, result);
    return result;
}

char *sub_func_call(char *str, char *str2, int len)
{
    char *result;

    if ((result = malloc(len + 2)) == NULL)
        malloc_error_message("sub_func_call");
    str = my_revstr(str);
    str2 = my_revstr(str2);
    if (str2[strlen(str2) - 1] == '-' && str[strlen(str) - 1] != '-') {
        str2[strlen(str2) -1] = '\0';
        return infin_add(my_revstr(str), my_revstr(str2));
    }
    if (str2[strlen(str2) - 1] != '-' && str[strlen(str) - 1] != '-')
        return check_negative(str, str2, result);
    if (str2[strlen(str2) - 1] != '-' && str[strlen(str) - 1] == '-') {
        str[strlen(str) - 1] = '\0';
        return sub_negative(str, str2, result);
    }
    if (str2[strlen(str2) - 1] == '-' && str[strlen(str) - 1] == '-') {
        str2[strlen(str2) -1] = '\0';
        return infin_add(my_revstr(str), my_revstr(str2));
    }
    return str;
}

char *infin_sub(char *str, char *str2)
{
    int value1;
    int value2;
    char *result;

    value1 = strlen(str);
    value2 = strlen(str2);
    if (value1 <= value2)
        result = sub_func_call(str, str2, value2);
    else
        result = sub_func_call(str, str2, value1);
    return result;
}

char *calc_modulo(char *nb1, char *nb2, char *result)
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
    return nb1;
}

char *modulo_negativity(char *str, char *str2)
{
    if (str[0] == '-' && str2[0] == '-')
        return calc_modulo(negative_to_positive2(str),
                           negative_to_positive2(str2), "0");
    if (str[0] == '-' && str2[0] != '-')
        return change_sign(calc_modulo(negative_to_positive2(str), str2, "0"));
    if (str[0] != '-' && str2[0] == '-')
        return change_sign(calc_modulo(str, negative_to_positive2(str2), "0"));
    return str;
}

char *infin_mod(char *str, char *str2)
{
    char *result;
    char *tmp = malloc(2);

    if (tmp == NULL)
        malloc_error_message("infin_mod");
    if (strcmp(str, "0") == 0) {
        tmp[0] = '0';
        tmp[1] = '\0';
        return tmp;
    }
    if (strcmp(str2, "0") == 0) {
        printf("Error: divisions by 0 are prohibited.\n");
        exit(84);
    }
    if (strcmp(str, str2) == 0) {
        tmp[0] = '1';
        tmp[1] = '\0';
        return tmp;
    }
    if (str[0] == '-' || str2[0] == '-')
        return modulo_negativity(str, str2);
    if (strlen(str2) > strlen(str)) {
        tmp[0] = '0';
        tmp[1] = '\0';
        return tmp;
    }
    result = calc_modulo(str, str2, "0");
    return result;
}

char **malloc_array(char *init, int count, int len)
{
    char **result;
    int tmp = 0;
    int tmp2 = 0;

    for (int i = 0; i < len; i++) {
        if (init[i] >= '0' && init[i] <= '9' && init[i] != '\0') {
            while (init[i] >= '0' && init[i] <= '9' && init[i] != '\0')
                i++;
            count++;
        }
        if ((init[i] < '0' || init[i] > '9') && init[i] != '\0') {
            while ((init[i] < '0' || init[i] > '9') && init[i] != '\0')
                i++;
            count++;
            i--;
        }
    }
    if ((result = malloc(sizeof(char *) * (count + 1))) == NULL)
        malloc_error_message("malloc_array");
    for (int i = 0; i < count; i++) {
        if ((init[tmp] >= '0' || init[tmp] <= '9') && init[tmp] != '\0')
            for (tmp2 = 0; (init[tmp] > 47 || init[tmp] < 58) &&
                     init[tmp] != '\0'; tmp2++, tmp++);
        if ((init[tmp] < '0' || init[tmp] > '9') && init[tmp] != '\0')
            for (tmp2 = 0; (init[tmp] < 48 || init[tmp] > 57) &&
                     init[tmp] != '\0'; tmp2++, tmp++);
        if ((result[i] = malloc(tmp2 + 1)) == NULL)
            malloc_error_message("malloc_array");
    }
    return result;
}

char **fill_array(char **result, char *init, int count, int len)
{
    int tmp = 0;
    int tmp2 = 0;

    for (int i = 0; i < len; i++) {
        if (init[i] >= '0' && init[i] <= '9' && init[i] != '\0') {
            while (init[i] >= '0' && init[i] <= '9' && init[i] != '\0')
                i++;
            count++;
        }
        if ((init[i] < '0' || init[i] > '9') && init[i] != '\0') {
            while ((init[i] < '0' || init[i] > '9') && init[i] != '\0')
                i++;
            count++;
            i--;
        }
    }
    for (int i = 0; i < count; i++) {
        if (init[tmp] >= '0' && init[tmp] <= '9' && init[tmp] != '\0') {
            for (tmp2 = 0; init[tmp] > 47 && init[tmp] < 58 &&
                    init[tmp] != '\0'; tmp2++, tmp++)
                result[i][tmp2] = init[tmp];
            result[i][tmp2] = '\0';
            i++;
        }
        if ((init[tmp] < '0' || init[tmp] > '9') && init[tmp] != '\0') {
            for (tmp2 = 0; (init[tmp] < 48 || init[tmp] > 57) &&
                    init[tmp] != '\0'; tmp2++, tmp++)
                result[i][tmp2] = init[tmp];
            result[i][tmp2] = '\0';
        }
    }
    result[count] = NULL;
    return result;
}

char **my_str_to_word_array(char *init)
{
    char **result = malloc_array(init, 0, strlen(init));

    result = fill_array(result, init, 0, strlen(init));
    return result;
}

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
        if (str[i] < str2[i]) {
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
        return "0";
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
    free(tmp);
    return result;
}

/* This function returns a string which contains all the characters before
   the parenthesis located at start pointer. */

/* This function returns a string which contains all the characters before
   the parenthesis located at start pointer. */

char *recup_str_before_parentheses(char *str, unsigned int start)
{
    char *new_string;

    if (start >= strlen(str) - 1 || start == 0)
        return "\0";
    if (start > 0)
        if ((new_string = malloc(start + 2)) == NULL)
            malloc_error_message("recup_str_before_parentheses");
    for (unsigned int tmp = 0; tmp < start; tmp++)
        new_string[tmp] = str[tmp];
    if ((new_string[start - 1] >= '0' && new_string[start - 1] < '9') ||
        new_string[start - 1] == ')')
            new_string[start] = '*';
    else
        new_string[start] = '\0';
    new_string[start + 1] = '\0';
    return new_string;
}

/* This function returns a string which contains all the characters located
   after the closing parenthesis located at the end pointer. */

char *end_of_str(char *str, int end)
{
    unsigned int nb = 0;
    char *new_string;

    if (str[end] == '\0')
        return "\0";
    if ((new_string = malloc(strlen(str) - end + 2)) == NULL)
        malloc_error_message("end_of_str");
    if (end > 0 && str[end - 1] == ')' &&
        (str[end + 1] > '9' || str[end + 1] < '0') && str[end] != ')') {
        nb = 1;
        new_string[0] = '*';
    }
    for (; str[end] != '\0' ; nb++, end++)
        new_string[nb] = str[end];
    new_string[nb] = '\0';
    return new_string;
}

/* This function calculates the content between the open parenthesis
   located at the start pointer, up to the  closing parentesis
   located at the end pointer. */

char *calc_parentheses(char *result, char *str, int start, int end)
{
    int tmp;
    char *tmp2 = malloc(end - start);

    for (tmp = 0; start < end; tmp++, start++)
        result[tmp] = str[start];
    result[tmp] = '\0';
    for (int i = 0; result[i] != '\0'; i++)
        if (result[i] > '9' || result[i] < '0') {
            result = eval_expr(result);
            i = 0;
        }
    if (str[end + 1] >= '0' && str[end + 1] <= '9') {
        strcpy(tmp2, result);
        result = realloc(result, strlen(tmp2) + 2);
        strcpy(result, tmp2);
        result[strlen(tmp2)] = '*';
        result [strlen(tmp2) + 1] = '\0';
        }
    return result;
}

/* This function is a loop which will stop only when there are no more
   parentheses. This is the function that calls the other functions dealing
   with parentheses. */

char *parentheses_loop(char *str)
{
    char *result;
    char *new_string;
    int start;
    int end;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '(') {
            for (start = i; str[start] != '('; start++);
            for (end = start; str[end] != ')'; end++)
                if (str[end] == '(') {
                    start = end;
                    i = 0;
                }
            if ((result = malloc(end - start)) == NULL)
                malloc_error_message("parentheses_loop");
            result = calc_parentheses(result, str, start + 1, end);
            new_string = recup_str_before_parentheses(str, start);
            result = my_strcat(new_string, result);
            result = my_strcat(result, end_of_str(str, end + 1));
            str = result;
            puts(str);
        }
    return result;
}

/* This function checks if there is at least one perenthesis in the string
   sent as an argument. */

int check_parentheses(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '(' ||str[i] == ')')
            return 1;
    return 0;
}

/* This function checks if there are as many opening and closing parentheses. */

int check_nb_of_parentheses(char *str)
{
    int count = 0;
    int order = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '(')
            count++;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ')')
            count--;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            order++;
        if (str[i] == ')')
            order--;
        if (order < 0)
            return order;
    }
    return count;
}

char *parentheses(char *str)
{
    int count = 0;
    char *result = str;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            count++;
    }
    if (check_nb_of_parentheses(str) != 0) {
        printf("Syntax Error: check the number and order of parentheses.\n");
        exit(-1);
    }
    if (count == 0)
        return str;
    while (check_parentheses(result) != 0)
        result = parentheses_loop(result);
    return result;
}

char *multiplier(char *str, char *str2, char *result)
{
    int count = 0;
    int y;

    for (int i = 0; str2[i] != '\0'; i++) {
        for (y = 0 + i; str[count] != '\0'; y++, count++) {
            result[y] = ATN(result[y]) + ATN(str2[i]) * ATN(str[count]);
            if (result[y] > 9) {
                result[y + 1] = NTA(result[y] / 10) + ATN(result[y + 1]);
                result[y] = result[y] % 10;
            }
            result[y] = NTA(result[y]);
        }
        count = 0;
    }
    result[y + 1] = '\0';
    result = my_revstr(result);
    result = clear_string(result);
    return result;
}

char *negative_to_positive(char *str, char *str2, char *result)
{
    str[strlen(str) - 1] = '\0';
    str2[strlen(str2) - 1] = '\0';
    return multiplier(str, str2, result);
}

char *negative_product(char *str, char *str2, char *result)
{
    int count;

    for (count = 0; str[count] != '\0'; count++)
        if (str[count] == '-')
            str[count] = '\0';
    for (count = 0; str2[count] != '\0'; count++)
        if (str2[count] == '-')
            str2[count] = '\0';
    result = multiplier(str, str2, result);
    result = change_sign(result);
    return result;
}

char *func_caller(char *str, char *str2, int len)
{
    char *result;

    if ((result = malloc(len)) == NULL)
        malloc_error_message("negative_product");
    for (int i = 0; i < len; i++)
        result[i] = '0';
    result[len - 1] = '\0';
    str = my_revstr(str);
    str2 = my_revstr(str2);
    if (str[strlen(str) - 1] == '-' && str2[strlen(str2) - 1] == '-')
        return (negative_to_positive(str, str2, result));
    if (str[strlen(str) - 1] == '-' || str2[strlen(str2) - 1] == '-')
        return (negative_product(str, str2, result));
    if (strlen(str) > strlen(str2))
        return multiplier(str, str2, result);
    result = multiplier(str2, str, result);
    return result;
}

char *infin_mult(char *str, char *str2)
{
    int value1;
    char *result;
    char *tmp = malloc(2);

    if (tmp == NULL)
        malloc_error_message("infin_mult");
    tmp[0] = '0';
    tmp[1] = '\0';
    if (strcmp(str, "0") == 0 || strcmp(str2, "0") == 0)
        return tmp;
    value1 = strlen(str) + strlen(str2) + 3;
    if (strlen(str) <= strlen(str2))
        result = func_caller(str2, str, value1);
    else
        result = func_caller(str, str2, value1);
    return result;
}

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

/* This loop will check if there are priority operations and send
   them to the calculator first */

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


int main(void)
{
    int res;
    char *result;

    result = eval_expr("12+5-3*8-(1+2)/6");
    res = strcmp(result, "-7");
    //@ assert res == 0;
    result = eval_expr("77986/-986%854258*2/55500-1");
    res = strcmp(result, "-1");
    //@ assert res == 0;
    result = eval_expr("12+(((3+4)+(5)))");
    res = strcmp(result, "24");
    //@ assert res == 0;
    result = eval_expr("13%2");
    res = strcmp(result, "1");
    //@ assert res == 0;
    result = eval_expr("500%30");
    res = strcmp(result, "20");
    //@ assert res == 0;
    result = eval_expr("-13%2");
    res = strcmp(result, "-1");
    //@ assert res == 0;
    result = eval_expr("-100/10");
    res = strcmp(result, "-10");
    //@ assert res == 0;
    result = eval_expr("-200/-2");
    res = strcmp(result, "100");
    //@ assert res == 0;
    result = eval_expr("0/5000");
    res = strcmp(result, "0");
    //@ assert res == 0;
    result = eval_expr("9500/5000");
    res = strcmp(result, "1");
    //@ assert res == 0;
    result = eval_expr("95000/531");
    res = strcmp(result, "178");
    //@ assert res == 0;
    result = eval_expr("950*5000");
    res = strcmp(result, "4750000");
    //@ assert res == 0;
    result = eval_expr("-2*-6");
    res = strcmp(result, "12");
    //@ assert res == 0;
    result = eval_expr("-765489*11000653");
    res = strcmp(result, "-8420878864317");
    //@ assert res == 0;
    result = eval_expr("0-0");
    res = strcmp(result, "0");
    //@ assert res == 0;
    result = eval_expr("-950--5000");
    res = strcmp(result, "4050");
    //@ assert res == 0;
    result = eval_expr("-760-900");
    res = strcmp(result, "-1660");
    //@ assert res == 0;
    result = eval_expr("8524-5846");
    res = strcmp(result, "2678");
    //@ assert res == 0;
    result = eval_expr("7854-25");
    res = strcmp(result, "7829");
    //@ assert res == 0;
    result = eval_expr("779865-9865854258*2+55500-1");
    res = strcmp(result, "-19730873152");
    //@ assert res == 0;
    result = eval_expr("779865-9865854258*2+55500-1500+1580000*150284");
    res = strcmp(result, "217717845349");
    //@ assert res == 0;
    result = eval_expr("16+25(36+1*2)+(4+(2*6))(3*3)");
    res = strcmp(result, "1110");
    //@ assert res == 0;
    result = eval_expr("10");
    res = strcmp(result, "10");
    //@ assert res == 0;
    result = eval_expr("-17*8(15-3)");
    res = strcmp(result, "-1632");
    //@ assert res == 0;
    return 0;
}
