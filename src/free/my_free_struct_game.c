/*
** EPITECH PROJECT, 2022
** MY_FREE_STRUCT_GAME_C
** File description:
** my_free_struct_game
*/

#include "my_defender.h"

void my_free_musics(game_t *game)
{
    sfMusic_stop(game->music->menu_music);
    sfMusic_stop(game->music->game_music);
    sfMusic_destroy(game->music->menu_music);
    sfMusic_destroy(game->music->game_music);
    free(game->music);
}

void my_free_struct_game(game_t *game)
{
    sfRenderWindow_close(game->window);
    sfRenderWindow_destroy(game->window);
    sfSprite_destroy(game->bgsprite);
    sfSprite_destroy(game->portal);
    sfSprite_destroy(game->base);
    my_free_array(game->map);
    my_free_musics(game);
    //my_free_menu(game);
    //my_free_pasue_menu(game);
    //my_free_life(game);
    //my_free_wave(game);
}
