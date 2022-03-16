/*
** EPITECH PROJECT, 2021
** MY_IS_PRIME_C
** File description:
** return 1 if prime and 0 if not
*/

int my_is_prime(int nb)
{
    int i = 2;

    while (i * 2 <= nb) {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}
