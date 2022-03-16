/*
** EPITECH PROJECT, 2021
** TESTS_my_error_handling_C
** File description:
** unit tests for my_error_handling
*/

#include "criterion/criterion.h"
#include "my_defender.h"

Test (my_error_handling, simple_test_succes)
{
    char **av = malloc(sizeof(char *) * 3);
    int ac = 2;
    av[1] = "maps/map1.test";

    cr_assert_eq(my_error_handling(ac, av), 0);
}

Test (my_error_handling, simple_test_fail)
{
    char **av = malloc(sizeof(char *) * 2);
    int ac = 2;
    av[1] = "bonjour moi c'est tom";

    cr_assert_eq(my_error_handling(ac, av), 84);
}

Test (my_error_handling, simple_test_fail2)
{
    char **av = malloc(sizeof(char *) * 3);
    int ac = 3;
    av[0] = NULL;

    cr_assert_eq(my_error_handling(ac, av), 84);
}
