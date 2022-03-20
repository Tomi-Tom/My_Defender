/*
** EPITECH PROJECT, 2022
** MY_PAUSE_MENU_C
** File description:
** my_pause_menu
*/

#include "my_defender.h"

int my_get_actions_in_pause(game_t *game)
{
    sfVector2i mouse = {0, 0};
    sfMouseButton click = 0;

    mouse = sfMouse_getPositionRenderWindow(game->window);
    my_poll_event(game);
    if (is_button_pressed(game->pause_menu->resume, mouse, click))
        return 1;
    if (is_button_pressed(game->pause_menu->menu, mouse, click))
        return 2;
    if (is_button_pressed(game->pause_menu->leave, mouse, click))
        return 3;
    return 0;
}

void my_display_pause_menu(game_t *game)
{
    my_display_button(game->pause_menu->resume, game);
    my_display_button(game->pause_menu->menu, game);
    my_display_button(game->pause_menu->leave, game);
    return;
}

void my_pause_menu(game_t *game)
{
    game->pause = 1;
    int choose = 0;

    sfRenderWindow_drawSprite(game->window, game->pause_menu->bg, NULL);
    sfRenderWindow_display(game->window);
    while (game->pause) {
        my_display_pause_menu(game);
        choose = my_get_actions_in_pause(game);
        if (choose == 1) {
            game->pause = 0;
        } if (choose == 2) {
            game->pause = 0;
            END_GAME;
        } if (choose == 3) {
            game->pause = 0;
            END_GAME;
            END_PROG;
        }
        sfRenderWindow_display(game->window);
    }
}