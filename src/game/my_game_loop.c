/*
** EPITECH PROJECT, 2022
** MY_LAUNCH_GAME_C
** File description:
** my_launch_game
*/

#include "my_defender.h"

void my_game_loop(game_t *game)
{
    sfMusic_play(game->music->game_music);
    while (game->end_game == 0) {
        sfRenderWindow_clear(game->window, sfBlack);
        my_game_actions(game);
        my_display_map(game);
        my_display_tower(game);
        my_display_ennemies(game);
        my_display_life(game);
        my_tower_actions(game);
        sfRenderWindow_display(game->window);
    }
    sfMusic_stop(game->music->game_music);
}
