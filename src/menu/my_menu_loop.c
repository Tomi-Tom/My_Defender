/*
** EPITECH PROJECT, 2022
** MY_MENU_LOOP_C
** File description:
** my_menu_loop
*/

#include "my_defender.h"

int is_button_pressed(button_t *button, sfVector2i mouse, sfMouseButton click)
{
    if (BUTTON_PRESSED)
        return 1;
    return 0;
}

int my_get_actions_in_menu(game_t *game)
{
    sfVector2i mouse = {0, 0};
    sfMouseButton click = 0;

    mouse = sfMouse_getPositionRenderWindow(game->window);
    if (is_button_pressed(game->menu->play, mouse, click)) {
        sfMusic_play(game->sound->click);
        return LAUNCH_GAME;
    }
    if (is_button_pressed(game->menu->how_to_play, mouse, click)) {
        sfMusic_play(game->sound->click_htp);
        return DISPLAY_HTP;
    }
    if (is_button_pressed(game->menu->leave, mouse, click)) {
        sfMusic_play(game->sound->click);
        return LEAVE_GAME;
    }
    return 0;
}

void my_display_how_to_play(game_t *game)
{
    sfSprite *sp_hplay = sfSprite_create();
    sfTexture *tex_hplay =
        sfTexture_createFromFile("assets/menu/how_to_play.png", NULL);
    sfMouseButton click = 0;

    sfSprite_setTexture(sp_hplay, tex_hplay, sfTrue);
    sfRenderWindow_drawSprite(game->window, sp_hplay, NULL);
    sfRenderWindow_display(game->window);
    while (sfMouse_isButtonPressed(click) == 0) {}
    sfSprite_destroy(sp_hplay);
    sfTexture_destroy(tex_hplay);
}

void my_menu_loop(game_t *game)
{
    int choose = 0;

    my_poll_event(game);
    my_display_menu(game);
    choose = my_get_actions_in_menu(game);
    if (choose == LAUNCH_GAME) {
        sfMusic_stop(game->music->menu_music);
        my_game_loop(game);
    }
    if (choose == DISPLAY_HTP)
        my_display_how_to_play(game);
    if (choose == LEAVE_GAME)
        game->end = 1;
}
