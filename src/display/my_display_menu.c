/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_MENU_C
** File description:
** my_display_menu
*/

#include "my_defender.h"

void my_display_button(button_t *button, game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfMouseButton click = 0;
    sfVector2f vec = {button->vec.x, button->vec.y};

    button->rect.left = 0;
    if (CURSOR_IS_IN_BUTTON) {
        button->rect.left = 535;
        if (LEFT_CLICKED) {
            button->rect.left = 535 * 2;
        }
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

void my_anim_map_menu2(game_t *game)
{
    sfVector2f vec;
    static int state = 0;
    static float rotate = 1;

    if (rotate >= 25)
        state = 1;
    if (rotate <= -25)
        state = 0;
    if (state == 0)
        rotate += 0.004;
    if (state == 1)
        rotate -= 0.004;
    vec.x = 800;
    vec.y = 600;
    sfSprite_setOrigin(game->menu->map, vec);
    sfSprite_setPosition(game->menu->map, vec);
    sfSprite_setRotation(game->menu->map, rotate);
}

void my_anim_map_menu(game_t *game)
{
    sfVector2f vec;
    static int state = 0;
    static float scale = 1;

    if (scale >= 1.1)
        state = 1;
    if (scale <= 0.9)
        state = 0;
    if (state == 0)
        scale += 0.00004;
    if (state == 1)
        scale -= 0.00004;
    vec.x = 800;
    vec.y = 600;
    sfSprite_setOrigin(game->menu->map, vec);
    sfSprite_setPosition(game->menu->map, vec);
    vec.x = scale;
    vec.y = scale;
    sfSprite_setScale(game->menu->map, vec);
}

void my_display_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    my_anim_map_menu(game);
    my_anim_map_menu2(game);
    sfRenderWindow_drawSprite(game->window, game->menu->back, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu->map, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu->front, NULL);
    my_display_buttons(game);
    sfRenderWindow_drawText(game->window, game->best_wave, NULL);
    sfRenderWindow_display(game->window);
}
