/*
** EPITECH PROJECT, 2021
** MY_FIND_PRIME_SUP_C
** File description:
** return the next prime of an int
*/

int my_is_prime(int nb);

int prime_sup(int nb)
{
    while (nb) {
        if (my_is_prime(nb))
            return (nb);
        nb++;
    }
    return (0);
}

int my_find_prime_sup(int nb)
{
    int i = 2;

    while (i <= nb / 2) {
        if (nb % i == 0)
            return (prime_sup(nb));
        i++;
    }
    return (i);
}
