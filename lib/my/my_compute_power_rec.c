/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_POWER_IT
** File description:
** return an int powered by another int
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return (1);
    else if (p == 1)
        return (nb);
    else
        return (nb * my_compute_power_rec(nb, p - 1));
}
