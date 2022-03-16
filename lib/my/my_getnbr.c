/*
** EPITECH PROJECT, 2021
** MY_GETNBR_C
** File description:
** faire un my_atoi
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    long long int res = 0;

    while ((str[i] == '-' || str[i] == '+') && str[i]) {
        if (str[i] == '-')
            neg = neg * -1;
        i++;
    }
    while ((str[i] >= '0' && str[i] <= '9') && str[i]) {
        res = res * 10;
        res = res + (str[i] - 48);
        i++;
        if ((res > 2147483648 && neg == -1) || (res > 2147483647 && neg == 1))
            return (0);
    }
    return (res * neg);
}
