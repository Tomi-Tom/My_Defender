/*
** EPITECH PROJECT, 2021
** ISPRINTABLE
** File description:
** ISPRINTABLE
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (!(str[i] < 127 && str[i] > 32))
            return (0);
        i++;
    }
    return (1);
}
