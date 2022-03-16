/*
** EPITECH PROJECT, 2021
** MY_STRDUP_C
** File description:
** MY_STRDUP
*/

#include "stdlib.h"

int     my_strlendup(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char    *my_strdup(char const *src)
{
    int i = 0;
    int len = my_strlendup(src);
    char *str;

    str = (malloc(sizeof(char) * (len + 1)));
    if (!(str))
        return (0);
    while (src[i]) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
