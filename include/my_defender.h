/*
** EPITECH PROJECT, 2022
** MY_PROJECT_H
** File description:
** MY_PROJECT_H
*/

#ifndef MY_PROJECT_H
    #define MY_PROJECT_H

    #include "my.h"
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <assert.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/mman.h>

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct vec_s {
    int x;
    int y;
} vec_t;


    #include "my_tower.h"
    #include "my_tile.h"
    #include "my_entity.h"
    #include "my_wave.h"
    #include "my_button.h"
    #include "my_life.h"
    #include "my_music.h"
    #include "my_menu.h"

typedef struct game_s {
    int end;
    int end_game;
    sfRenderWindow *window;
    sfSprite *bgsprite;
    sfSprite *portal;
    sfSprite *base;
    char **map;
    menu_t *menu;
    music_t *music;
    tower_plate_t *tower;
    life_t *life;
    wave_t *wave;
} game_t;

/*==========================[BEGIN]==========================*/

int my_error_handling(int ac, char **av);
int my_help(void);

/*==========================[WINDOW]=========================*/

void my_window(int ac, char **av);

/*==========================[INIT]==========================*/

char *my_parse_path(char **map);
game_t *my_init_game(char *filename);
void my_init_ennemies(game_t *game);
void my_init_life(game_t *game);
void my_init_music(game_t *game);
void my_init_menu(game_t *game);

/*==========================[LOOP]==========================*/

void my_game_loop(game_t *game);
void my_menu_loop(game_t *game);

/*=========================[CREATE]=========================*/

void my_create_ennemies(game_t *game);

/*=========================[ACTIONS]========================*/

void my_game_actions(game_t *game);
void my_tower_actions(game_t *game);

/*==========================[MOVE]==========================*/

void my_move_ennemie(entity_t *entity, wave_t *wave, game_t *game);
void my_move_up(wave_t *wave, entity_t *entity);
void my_move_down(wave_t *wave, entity_t *entity);
void my_move_left(wave_t *wave, entity_t *entity);
void my_move_right(wave_t *wave, entity_t *entity);

/*=========================[DISPLAY]========================*/

void my_display_menu(game_t *game);
void my_display_map(game_t *game);
void my_display_tower(game_t *game);
void my_display_ennemies(game_t *game);
void my_display_life(game_t *game);

/*=========================[PARSING]========================*/

vec_t get_departure(char **map);

/*=========================[LINKED]=========================*/

entity_t *my_append_entity(game_t *game);
entity_t *my_delete_entity(game_t *game, int id);

#endif /* !MY_PROJECT_H */
