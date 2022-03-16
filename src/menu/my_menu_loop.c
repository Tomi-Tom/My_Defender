/*
** EPITECH PROJECT, 2022
** MY_MENU_LOOP_C
** File description:
** my_menu_loop
*/

#include "my_defender.h"

int is_button_pressed(button_t *button, sfVector2f mouse, sfMouseButton click)
{
    if (mouse.x >= button->vec.x && mouse.x <= button->vec.x +
        button->rect.width && mouse.y >= button->vec.y && mouse.y
        <= button->vec.y + button->rect.height &&
        sfMouse_isButtonPressed(click) == 1)
        return 1;
    return 0;
}

int my_get_actions_in_menu(game_t *game)
{
    sfVector2f mouse = {0, 0};
    sfMouseButton click = 0;

    mouse.x = sfMouse_getPositionRenderWindow(game->window).x;
    mouse.y = sfMouse_getPositionRenderWindow(game->window).y;
    if (is_button_pressed(game->menu->play, mouse, click)) {
        printf("ON PLAY\n");
        return 1;
    }
    if (is_button_pressed(game->menu->how_to_play, mouse, click)) {
        printf("ON HOW TO PLAY\n");
        return 2;
    }
    if (is_button_pressed(game->menu->leave, mouse, click)) {
        printf("ON LEAVE\n");
        return 3;
    }
}

void my_menu_loop(game_t *game)
{
    int choose = 0;

    my_display_menu(game);
    choose = my_get_actions_in_menu(game);
    if (choose == 1) {
        sfMusic_stop(game->music->menu_music);
        my_game_loop(game);
    } else if (choose == 3) {
        game->end = 1;
    }
}
