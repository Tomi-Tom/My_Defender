/*
** EPITECH PROJECT, 2022
** MY_TILE_H
** File description:
** my_tile
*/

#ifndef MY_TILE_H_
    #define MY_TILE_H_

typedef struct tile_s {
    int x;
    int y;
    int is_tower;
    tower_t *tower;
    struct tile_s *next;
} tile_t;

#endif /* !MY_TILE_H_ */
