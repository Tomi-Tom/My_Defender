/*
** EPITECH PROJECT, 2021
** MY_PUTCHAR_C
** File description:
** afficher un caractere
*/

#include "unistd.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
