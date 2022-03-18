/*
** EPITECH PROJECT, 2022
** MY_PAUSE_H
** File description:
** my_pause
*/

#ifndef MY_PAUSE_H_
    #define MY_PAUSE_H_

typedef struct pause_s {
    sfSprite *bg;
    button_t *resume;
    button_t *menu;
    button_t *leave;
} pause_t;

#endif /* !MY_PAUSE_H_ */
