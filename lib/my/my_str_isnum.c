/*
** EPITECH PROJECT, 2021
** ISNUM
** File description:
** ISNUM
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] > '9' || str[i] < '0')
            return (0);
        i++;
    }
    return (1);
}
