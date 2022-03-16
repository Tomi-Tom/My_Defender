/*
** EPITECH PROJECT, 2022
** MY_BUTTON_H
** File description:
** my_button
*/

#ifndef MY_BUTTON_H_
    #define MY_BUTTON_H_

typedef struct button_s {
    sfSprite *sprite;
    vec_t vec;
    sfIntRect rect;
} button_t;

#endif /* !MY_BUTTON_H_ */
