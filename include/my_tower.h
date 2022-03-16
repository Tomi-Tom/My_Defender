/*
** EPITECH PROJECT, 2022
** MY_TOWER_H
** File description:
** my_tower
*/

#ifndef MY_TOWER_H_
    #define MY_TOWER_H_

typedef struct tower_s {
    sfClock *time;
    char *tower_name;
    sfSprite *sprite;
    int att_spd;
    int dmg;
    int range;
    int bullet_spd;
} tower_t;

#endif /* !MY_TOWER_H_ */
