/*
** EPITECH PROJECT, 2021
** STRCAPITALIZE
** File description:
** STRCAPITALIZE
*/

#include "stdio.h"

int compare(char act, char bef)
{
    if (act >= 'a' && act <= 'z') {
        if (bef >= 'a' && bef <= 'z')
            return (0);
        if (bef >= 'A' && bef <= 'Z')
            return (0);
        if (bef >= '0' && bef <= '9')
            return (0);
        return (1);
    }
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int ok = 0;

    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
    i = 0;
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
    while (str[i]) {
        ok = compare(str[i], str[i - 1]);
        if (ok)
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}
