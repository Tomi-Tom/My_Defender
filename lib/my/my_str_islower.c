/*
** EPITECH PROJECT, 2021
** ISLOWER
** File description:
** ISLOWER
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] > 'z' || str[i] < 'a')
            return (0);
        i++;
    }
    return (1);
}
