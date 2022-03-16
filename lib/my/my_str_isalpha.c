/*
** EPITECH PROJECT, 2021
** ISALPHA
** File description:
** ISALPHA
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i]) {
        if ((str[i] > 'z' || str[i] < 'a') && (str[i] > 'Z' || str[i] < 'A'))
            return (0);
        i++;
    }
    return (1);
}
