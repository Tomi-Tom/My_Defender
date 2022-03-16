/*
** EPITECH PROJECT, 2021
** STRSTR
** File description:
** STRSTR
*/

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    while (str[i]) {
        while (str[i + j] == to_find[j] && to_find[j]) {
            j++;
        }
        if (to_find[j] == '\0')
            return (&str[i]);
        j = 0;
        i++;
    }
    return (0);
}
