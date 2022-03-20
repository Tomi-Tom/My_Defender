/*
** EPITECH PROJECT, 2022
** MY_POLL_EVENT_C
** File description:
** my_poll_event
*/

#include "my_defender.h"

int my_poll_event(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            END_GAME;
            END_PROG;
            game->pause = 0;
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return ESCAPE_KEY;
        if (sfKeyboard_isKeyPressed(sfKeyEnter))
            return ENTER_KEY;
    }
    return 0;
}
