/*
** EPITECH PROJECT, 2022
** MY_INIT_MUSIC_C
** File description:
** my_init_music
*/

#include "my_defender.h"

void my_init_music(game_t *game)
{
    game->music = malloc(sizeof(music_t));

    game->music->game_music =
        sfMusic_createFromFile("assets/musics/bgmusic.ogg");
    game->music->menu_music =
        sfMusic_createFromFile("assets/musics/loop_menu.ogg");
}
