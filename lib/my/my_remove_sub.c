/*
** EPITECH PROJECT, 2021
** my_remove_sub_c
** File description:
** remove sub from the begining of a string (return a malloc str)
*/

#include "my.h"

char *remove_sub(char const *str)
{
    int i = 0;
    int j = 0;
    char *fin = my_strdup(str);

    if (str[0] == '-')
        j = 1;
    while (str[i + j]) {
        fin[i] = str[i + j];
        i++;
    }
    fin[i] = '\0';
    return (fin);
}