/*
** EPITECH PROJECT, 2022
** MY_MENU_H
** File description:
** my_menu
*/

#ifndef MY_MENU_H_
    #define MY_MENU_H_

typedef struct menu_s {
    sfSprite *back;
    sfSprite *map;
    int scale;
    sfSprite *front;
    button_t *play;
    button_t *how_to_play;
    button_t *leave;
    int best_wave;
} menu_t;

#endif /* !MY_MENU_H_ */
