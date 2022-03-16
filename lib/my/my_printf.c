/*
** EPITECH PROJECT, 2021
** PRINTF_C
** File description:
** PRINTF_C
*/

#include "my.h"

int parse_flag(char *str, int i)
{
    i++;
    while (str[i]) {
        if (str[i] == '+')
            my_putchar('+');
        if (str[i] == 'c' || str[i] == 's' || str[i] == 'd' ||
            str[i] == 'u' || str[i] == 'l' || str[i] == '%' ||
            str[i] == 'x' || str[i] == 'X' || str[i] == 'b' ||
            str[i] == 'p' || str[i] == 'i')
            return i;
        i++;
    }
    return '\0';
}

int parse_flag_int(char *str, int i)
{
    int j = 1;

    while (str[i + j]) {
        if (str[i + j] == 'c' || str[i + j] == 's' || str[i + j] == 'd' ||
            str[i + j] == 'u' || str[i + j] == 'l' || str[i + j] == '%' ||
            str[i + j] == 'x' || str[i + j] == 'X' || str[i + j] == 'b' ||
            str[i + j] == 'p' || str[i + j] == 'i')
            return j;
        j++;
    }
    return 1;
}

int my_printf(char *str, ...)
{
    int i = 0;
    va_list arg;

    va_start(arg, str);
    while (str[i]) {
        if (str[i] == '%') {
            disp_stdarg(str, parse_flag(str, i), arg);
            i = i + parse_flag_int(str, i);
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    va_end(arg);
    return (i);
}
