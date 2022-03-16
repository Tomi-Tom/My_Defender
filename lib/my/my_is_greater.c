/*
** EPITECH PROJECT, 2021
** MY_IS_GREATER_C
** File description:
** compare two str and return 1 if str1 > str2 (not equals)
*/

#include "my.h"

int is_greater(char const *n1, char const *n2)
{
    int i = 0;
    int j = 0;

    if (my_strlen(n1) > my_strlen(n2))
        return 1;
    if (my_strlen(n2) > my_strlen(n1))
        return 0;
    while (n1[i] == n2[j]) {
        i++;
        j++;
    }
    if (n1[i] > n2[j])
        return 1;
    return 0;
}
