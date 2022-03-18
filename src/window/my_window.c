/*
** EPITECH PROJECT, 2022
** MY_WINDOW_C
** File description:
** my_window
*/

#include "my_defender.h"

void my_window(int ac, char **av)
{
    game_t *game = my_init_game(av[1]);
    sfMusic_setLoop(game->music->menu_music, sfTrue);
    sfMusic_play(game->music->menu_music);
    while (game->end == 0) {
        my_menu_loop(game);
    }
    sfRenderWindow_close(game->window);
    my_free_struct_game(game);
}
