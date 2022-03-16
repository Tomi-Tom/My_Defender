/*
** EPITECH PROJECT, 2021
** IS_NUM_C
** File description:
** is a char a num
*/

int     is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}