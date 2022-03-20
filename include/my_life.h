/*
** EPITECH PROJECT, 2022
** MY_LIFE_H
** File description:
** my_life
*/

#ifndef MY_LIFE_H_
    #define MY_LIFE_H_

typedef struct life_s {
    sfSprite *base_hp;
    sfSprite *hp;
    sfIntRect rect_base;
    sfIntRect rect_hp;
    sfText *t_life;
    int width;
    float life_max;
    float life;
} life_t;

#endif /* !MY_LIFE_H_ */
