/*
** EPITECH PROJECT, 2022
** MY_FREE_GAME_C
** File description:
** my_free_game
*/

#include "my_defender.h"

void my_free_sfx(sound_t *sound, music_t *music)
{
    sfMusic_stop(music->menu_music);
    sfMusic_stop(music->game_music);
    sfMusic_destroy(music->menu_music);
    sfMusic_destroy(music->game_music);
    free(music);

    sfMusic_destroy(sound->click);
    sfMusic_destroy(sound->click_htp);
    free(sound);
}

void my_free_menus(menu_t *menu, pause_t *pause)
{
    sfSprite_destroy(menu->back);
    sfSprite_destroy(menu->map);
    sfSprite_destroy(menu->front);
    my_free_button(menu->play);
    my_free_button(menu->how_to_play);
    my_free_button(menu->leave);
    free(menu);

    sfSprite_destroy(pause->bg);
    my_free_button(pause->resume);
    my_free_button(pause->menu);
    my_free_button(pause->leave);
    free(pause);
}

void my_free_stats(life_t *life, money_t *money)
{
    sfSprite_destroy(life->base_hp);
    sfSprite_destroy(life->hp);
    sfText_destroy(life->t_life);
    free(life);

    sfClock_destroy(money->time);
    sfSprite_destroy(money->sp_money);
    sfText_destroy(money->t_money);
    free(money);
}

void my_free_wave(wave_t *wave)
{
    sfClock_destroy(wave->time);
    free(wave->path);
    sfSprite_destroy(wave->sprite);
    sfSprite_destroy(wave->menu_tower);
    my_free_entity_list(&wave->entity);
    free(wave);
}

void my_free_game(game_t *game)
{
    sfFont_destroy(game->font);
    sfRenderWindow_close(game->window);
    sfRenderWindow_destroy(game->window);
    sfSprite_destroy(game->bgsprite);
    sfSprite_destroy(game->portal);
    sfSprite_destroy(game->base);
    sfText_destroy(game->best_wave);
    my_free_array(game->map);
    my_free_menus(game->menu, game->pause_menu);
    my_free_sfx(game->sound, game->music);
    my_free_stats(game->life, game->money);
    my_free_tile_list(&game->tile);
    my_free_wave(game->wave);
    free(game);
}
