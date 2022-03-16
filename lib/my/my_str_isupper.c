/*
** EPITECH PROJECT, 2021
** ISUPPER
** File description:
** ISUPPER
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] > 'Z' || str[i] < 'A')
            return (0);
        i++;
    }
    return (1);
}
