/*
** EPITECH PROJECT, 2021
** MY_PUTSTR_C
** File description:
** do a putstr
*/

#include "my.h"

int my_puterror(char const *str)
{
    write(2, str, my_strlen(str));
    return 84;
}
