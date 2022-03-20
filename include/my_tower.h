/*
** EPITECH PROJECT, 2022
** MY_TOWER_H
** File description:
** my_tower
*/

#ifndef MY_TOWER_H_
    #define MY_TOWER_H_

typedef struct tower_s {
    int type;
    sfClock *shoot;
    sfClock *rotate;
    sfSprite *body;
    sfSprite *head;
    int dmg;
    int att_spd;
    int range;
} tower_t;

#endif /* !MY_TOWER_H_ */
