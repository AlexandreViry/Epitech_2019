#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define ATN(c) (c - '0')
#define NTA(n) (n + '0')

char *power_of_ten(int i)
{
    char *res = malloc(i + 2);
    int y;

    res[0] = '1';
    i++;
    for (y = 1; y < i - 1; y++)
        res[y] = '0';
    res[y] = '\0';
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
    tmp = malloc(sizeof(char) * (len_str + 1));
    len_str--;
    for (; len_str >= 0; y++, len_str--)
        tmp[y] = str[len_str];
    tmp[y] = '\0';
    return tmp;
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
    result[count] = '\0';
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
    result2 = malloc(len + 2);
    result2[0] = '-';
    for (i = 1; result[i] != '\0'; i++)
        result2[i] = result[i - 1];
    result2[i] = result[i - 1];
    result2[len + 1] = '\0';
    return result2;
}

int who_is_bigger(char *str, char *str2)
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
    char *res = malloc(strlen(result) + 2);
    int i;

    res[0] = '-';
    for (i = 0; result[i] != '\0'; i++)
        res[i + 1] = result[i];
    res[i + 1] = '\0';
    free(result);
    return res;
}

char *negative(char *str, char *str2, char *result)
{
    if (str[strlen(str) - 1] == '-') {
        str[strlen(str) - 1] = '\0';
        if (who_is_bigger(my_revstr(str), my_revstr(str2)) == 2)
            result = subtractor(str2, str, result);
        if (who_is_bigger(my_revstr(str), my_revstr(str2)) == 1) {
            result = subtractor(str, str2, result);
            result = change_sign(result);
        }
    } else {
        str2[strlen(str2) - 1] = '\0';
        if (who_is_bigger(my_revstr(str), my_revstr(str2)) == 1)
            result = subtractor(str, str2, result);
        if (who_is_bigger(my_revstr(str), my_revstr(str2)) == 2) {
            result = subtractor(str2, str, result);
            result = change_sign(result);
        }
    }
    return result;
}

char *func_call(char *str, char *str2, int len)
{
    char *result = malloc(len + 2);

    str = my_revstr(str);
    str2 = my_revstr(str2);
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

int my_compute_power_it(int nb , int p)
{
    int res = nb;
    int tmp = p;

    if (tmp < 0)
        return 0;
    if (tmp == 0)
        return 1;
    for (; tmp > 1; tmp--) {
        if (INT_MAX / res <= nb && INT_MAX / res > 0)
            return 0;
        res = nb * res;
    }
    return res;
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
    char *result = malloc(len);

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

    if (strcmp(str, "0") == 0 || strcmp(str2, "0") == 0)
        return "0";
    value1 = strlen(str) + strlen(str2) + 3;
    if (strlen(str) <= strlen(str2))
        result = func_caller(str2, str, value1);
    else
        result = func_caller(str, str2, value1);
    return result;
}

char *sub_negative(char *str, char *str2, char *result)
{
    char *result2;
    int len;
    int i;

    result = calculator(str, str2, result);
    len = strlen(result);
    result2 = malloc(len + 2);
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
    char *result = malloc(len + 2);

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
    puts(rest);
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

int main(void)
{
    int res;
    char *result;

    result = infin_div("-100", "10");
    res = strcmp(result, "-10");
    //@ assert res == 0;
    result = infin_div("-200", "-2");
    res = strcmp(result, "100");
    //@ assert res == 0;
    result = infin_div("0", "5000");
    res = strcmp(result, "0");
    //@ assert res == 0;
    result = infin_div("9500", "5000");
    res = strcmp(result, "1");
    //@ assert res == 0;
    result = infin_div("95000", "531");
    res = strcmp(result, "178");
    //@ assert res == 0;
    result = infin_mult("950", "5000");
    res = strcmp(result, "4750000");
    //@ assert res == 0;
    result = infin_mult("-2", "-6");
    res = strcmp(result, "12");
    //@ assert res == 0;
    result = infin_mult("-765489", "11000653");
    res = strcmp(result, "-8420878864317");
    //@ assert res == 0;
    result = infin_sub("0", "0");
    res = strcmp(result, "0");
    //@ assert res == 0;
    result = infin_sub("-950", "-5000");
    res = strcmp(result, "4050");
    //@ assert res == 0;
    result = infin_sub("-760", "900");
    res = strcmp(result, "-1660");
    //@ assert res == 0;
    result = infin_sub("8524", "5846");
    res = strcmp(result, "2678");
    //@ assert res == 0;
    result = infin_sub("7854", "25");
    res = strcmp(result, "7829");
    //@ assert res == 0;
    return 0;
}
