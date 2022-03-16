/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_MENU_C
** File description:
** my_display_menu
*/

#include "my_defender.h"

void my_display_button(button_t *button, game_t *game)
{
    sfVector2f mouse = {0, 0};
    sfMouseButton click = 0;
    sfVector2f vec;

    mouse.x = sfMouse_getPositionRenderWindow(game->window).x;
    mouse.y = sfMouse_getPositionRenderWindow(game->window).y;
    vec.x = button->vec.x;
    vec.y = button->vec.y;
    button->rect.left = 0;
    if (mouse.x >= vec.x && mouse.x <= vec.x + button->rect.width && mouse.y
        >= vec.y && mouse.y <= vec.y + button->rect.height) {
        button->rect.left = 535;
        if (sfMouse_isButtonPressed(click))
            button->rect.left = 535 * 2;
    }
    sfSprite_setPosition(button->sprite, vec);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
}

void my_display_buttons(game_t *game)
{
    my_display_button(game->menu->play, game);
    my_display_button(game->menu->how_to_play, game);
    my_display_button(game->menu->leave, game);
}

void my_display_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->menu->back, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu->map, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu->front, NULL);
    my_display_buttons(game);
    sfRenderWindow_display(game->window);
}
