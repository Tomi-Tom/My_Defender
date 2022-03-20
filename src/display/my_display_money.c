/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_MONEY_C
** File description:
** my_display_money
*/

#include "my_defender.h"

void my_draw_text(game_t *game)
{
    char *current_money = my_itoa(game->money->money);
    char *display = malloc(sizeof(char) * 10);

    my_strcpy(display, current_money);
    my_strcat(display, "$");
    sfText_setString(game->money->t_money, display);
    sfRenderWindow_drawText(game->window, game->money->t_money, NULL);
    free(display);
}

void my_display_money(game_t *game)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->money->time)) > 0.05) {
        game->money->rect.left += game->money->rect.width;
        sfClock_restart(game->money->time);
    }
    if (game->money->rect.left == game->money->rect.width * 10)
        game->money->rect.left = 0;
    game->money->rect.height = 32;
    sfSprite_setTextureRect(game->money->sp_money, game->money->rect);
    sfRenderWindow_drawSprite(game->window, game->money->sp_money, NULL);
    my_draw_text(game);
}