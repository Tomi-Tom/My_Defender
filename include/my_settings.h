/*
** EPITECH PROJECT, 2022
** MY_SETTINGS_H
** File description:
** my_settings
*/

#ifndef MY_SETTINGS_H_
    #define MY_SETTINGS_H_



    #define END_GAME game->end_game = 1
    #define END_PROG game->end = 1

    #define ESCAPE_KEY 84
    #define ENTER_KEY 42

/*==================[MENU SETTINGS]==================*/

    #define CURSOR_IS_IN_BUTTON mouse.x >= button->vec.x && mouse.x \
        <= button->vec.x + button->rect.width && mouse.y >= \
        button->vec.y && mouse.y <= button->vec.y + button->rect.height
    #define LEFT_CLICKED sfMouse_isButtonPressed(click)
    #define BUTTON_PRESSED CURSOR_IS_IN_BUTTON && LEFT_CLICKED

/*==================[MENU SETTINGS]==================*/

    #define LAUNCH_GAME 1
    #define DISPLAY_HTP 2
    #define LEAVE_GAME 3

/*=================[ENTITY SETTINGS]=================*/

    #define ENTITY_LIFE 50
    #define ENTITY_SPEED 4
    #define ENTITY_HEIGHT 64
    #define ENTITY_WIDTH 64

#endif /* !MY_SETTINGS_H_ */
