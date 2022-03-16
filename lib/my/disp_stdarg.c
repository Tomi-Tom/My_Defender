/*
** EPITECH PROJECT, 2021
** DISP_STDARG_C
** File description:
** DISP_STRARG_C
*/

#include "my.h"

void disp_stdarg2(char *str, int i, va_list arg)
{
    if (str[i] == '%')
        my_putchar('%');
    if (str[i] == 'x')
        my_put_nbr_base(va_arg(arg, int), "0123456789abcdef");
    if (str[i] == 'X')
        my_put_nbr_base(va_arg(arg, int), "0123456789ABCDEF");
    if (str[i] == 'b')
        my_put_nbr_base(va_arg(arg, int), "01");
}

void disp_stdarg(char *str, int i, va_list arg)
{
    if (str[i] == 'c')
        my_putchar(va_arg(arg, int));
    if (str[i] == 's')
        my_putstr(va_arg(arg, char *));
    if (str[i] == 'd' || str[i] == 'i')
        my_put_nbr(va_arg(arg, int));
    if (str[i] == 'u')
        my_put_nbr_u(va_arg(arg, unsigned int));
    if (str[i] == 'l') {
        if (str[i + 1] == 'l') {
            my_put_nbr_ll(va_arg(arg, long long int));
        } else {
            my_put_nbr_l(va_arg(arg, long int));
        }
    }
    disp_stdarg2(str, i, arg);
}
