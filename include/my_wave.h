/*
** EPITECH PROJECT, 2022
** MY_WAVE_H
** File description:
** my_wave
*/

#ifndef MY_WAVE_H_
    #define MY_WAVE_H_

typedef struct wave_s {
    sfClock *time;
    vec_t begin;
    int count;
    int wave;
    int actual_wave;
    int wave_max;
    char *path;
    int spd;
    int end_menu;
    sfSprite *sprite;
    sfSprite *menu_tower;
    entity_t *entity;
} wave_t;

#endif /* !MY_WAVE_H_ */
