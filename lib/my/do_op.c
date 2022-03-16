/*
** EPITECH PROJECT, 2021
** eval exp
** File description:
** do_op
*/

int do_op(int nb1, int nb2, char op)
{
    int i = 0;

    if (op == '+')
        return (nb1 + nb2);
    if (op == '-')
        return (nb1 - nb2);
    i++;
    if (op == '/')
        return (nb1 / nb2);
    if (op == '*')
        return (nb1 * nb2);
    i++;
    if (op == '%')
        return (nb1 % nb2);
    return 0;
}