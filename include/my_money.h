/*
** EPITECH PROJECT, 2022
** MY_MONEY_H
** File description:
** my_money
*/

#ifndef MY_MONEY_H_
    #define MY_MONEY_H_

typedef struct money_s {
    sfClock *time;
    sfIntRect rect;
    int money;
    sfSprite *sp_money;
    sfText *t_money;
} money_t;

#endif /* !MY_MONEY_H_ */
