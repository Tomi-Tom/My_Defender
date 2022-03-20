/*
** EPITECH PROJECT, 2022
** MY_LAUNCH_GAME_C
** File description:
** my_launch_game
*/

#include "my_defender.h"

void my_init_begin_game(game_t *game)
{
    game->end_game = 0;
    game->wave->wave_max = 5;
    game->wave->wave = 0;
    game->wave->count = 0;
    game->life->life = 100;
    game->wave->entity = NULL;
}

void my_display_game(game_t *game)
{
    my_display_map(game);
    my_display_ennemies(game);
    my_display_life(game);
    my_display_money(game);
    my_display_tower(game);
}

void my_game_parse_life(game_t *game)
{
    if (game->life->life <= 0)
        game->end_game = 1;
}

void my_game_loop(game_t *game)
{
    sfMusic_play(game->music->game_music);
    my_init_begin_game(game);
    while (game->end_game == 0) {
        sfRenderWindow_clear(game->window, sfBlack);
        my_display_game(game);
        my_tower_actions(game);
        my_game_parse_life(game);
        my_game_actions(game);
        if (my_poll_event(game) == ESCAPE_KEY)
            my_pause_menu(game);
        sfRenderWindow_display(game->window);
    }
    sfMusic_stop(game->music->game_music);
    sfMusic_play(game->music->menu_music);
}
